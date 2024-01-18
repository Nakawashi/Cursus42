#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>

typedef struct client
{
	int id;
	char msg[100000];
} t_client;

t_client clients[1024];

int max = 0;
int next_id = 0;
fd_set active, ready_write, ready_read;
char buf_write[424242];
char buf_read[424242];

void exit_error(char *str)
{
	write(2, str, strlen(str));
	exit(1);
}

void send_all(int fd)
{
	for (int i = 0; i <= max; i++)
	{
		if (FD_ISSET(i, &ready_write) && i != fd)
			send(i, buf_write, strlen(buf_write), 0);
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		exit_error("err");

	int port = atoi(av[1]);
	struct sockaddr_in servaddr;
	int server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket == -1)
		exit_error("fatal");
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(port);

	if ((bind(server_socket, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		exit_error("fatal");
	if (listen(server_socket, 128) != 0)
		exit_error("fatal");

	max = server_socket;
	FD_SET(server_socket, &active);

	while(1)
	{
		ready_read = ready_write = active;
		if (select(max + 1, &ready_read, &ready_write, NULL, NULL) < 0)
			continue;

		for (int fd = 0; fd <= max; fd++)
		{
			if (FD_ISSET(fd, &ready_read) && fd == server_socket)
			{
				int client_socket = accept(server_socket, NULL, NULL);
				if (client_socket < 0)
					continue;
				max = (client_socket > max) ? client_socket : max;
				clients[client_socket].id = next_id++;
				sprintf(buf_write, "server: client %d just arrived\n", clients[client_socket].id);
				send_all(client_socket);
				FD_SET(client_socket, &active);
				break;
			}
			else if (FD_ISSET(fd, &ready_read))
			{
				int ret = recv(fd, buf_read, sizeof(buf_read), 0);
				if (ret <= 0)
				{
					sprintf(buf_write, "server: client %d just left\n", clients[fd].id);
					send_all(fd);
					close(fd);
					FD_CLR(fd, &active);
					break;
				}
				else
				{
					for (int i = 0, j = strlen(clients[fd].msg); i < ret; i++, j++)
					{
						clients[fd].msg[j] = buf_read[i];
						if (clients[fd].msg[j] == '\n')
						{
							clients[fd].msg[j] = '\0';
							sprintf(buf_write, "client %d: %s\n", clients[fd].id, clients[fd].msg);
							send_all(fd);
							bzero(&clients[fd].msg, strlen(clients[fd].msg));
							j = -1;
						}
					}
					break;
				}
			}
		}
	}
}