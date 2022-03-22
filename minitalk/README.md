# Partie Obligatoire
Vous devez réaliser un programme de communication sous la forme d’un client et d’un serveur.
- Le serveur doit être lancé en premier et doit, après le lancement, afficher son PID.
- Le client prend deux paramètres :
  - Le PID du serveur.
  - Une chaîne de caractères à transmettre.
- Le client doit communiquer au serveur la chaîne passée en paramètre. Une fois la chaîne entièrement reçue, le serveur doit l’afficher.
- Le serveur doit être capable d’afficher la chaîne rapidement. Par rapidement, on entend que si vous pensez que c’est trop long, alors c’est sûrement trop long.

> 1 seconde pour afficher 100 caractères, c’est COLOSSAL !

- Votre serveur doit pouvoir recevoir des chaînes de plusieurs clients à la suite sans nécessiter d’être relancé.
- La communication entre vos programmes doit se faire uniquement à l’aide de signaux UNIX.
- Vous ne pouvez utiliser que les deux signaux suivants : SIGUSR1 et SIGUSR2.

> Le système Linux ne met PAS les signaux en file d’attente lorsque vous avez déjà un signal en attente de ce type ! Bonus ?

# Partie Bonus
- Le serveur confirme la réception de chaque message en envoyant un signal au client.
- Le support des caractères Unicode !

# Execution
```
make

// open two terminals, one for client, one for server

// run the server to get its PID
lgenevey@c1r15s7 minitalk % ./server
Server's PID : 70257

// run the client with correct arguments
lgenevey@c1r15s7 minitalk % ./client 70257 "coucou"

// server got the message, and keep listening to new signals. Client got the acknowledge message.
```
