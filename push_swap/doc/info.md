

Instructions must be separated by a ’\n’ and nothing else

If no parameters are specified, the program must not display anything and give
the prompt back.

In case of error, you must display "Error" followed by a ’\n’ on the standard
error. Errors include for example: some arguments are not integers, some arguments
are bigger than an integer, there are duplicates, an instruction doesn’t exist
and/or is incorrectly formatted.

parser user infos
faire les fonction des mouvements autorises

ARG="5 4 3 1 2"; ./push_swap $ARG | wc -l

ARG="4 67"; ./push_swap $ARG | ./checker $ARG
