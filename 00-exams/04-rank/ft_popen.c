/*
Assignment name  : ft_popen
Expected files   : ft_popen.c
Allowed functions: pipe, fork, dup2, execvp, close, exit

--------------------------------------------------------------------------------------

Write the following function:

int ft_popen(const char *file, char *const argv[], char type);

The function must launch the executable file with the arguments argv (using execvp).
If type is 'r' the function must return a file descriptor connected to the output of the command.
If type is 'w' the function must return a file descriptor connected to the input of the command.
In case of error or invalid parameter the function must return -1.

For example, the function could be used like that:

int main()
{
    int  fd;
    char *line;

    fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
    while ((line = get_next_line(fd)))
        ft_putstr(line);
    return (0);
}


int	main() {
	int	fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
	dup2(fd, 0);
	fd = ft_popen("grep", (char *const []){"grep", "c", NULL}, 'r');
	char	*line;
	while ((line = get_next_line(fd)))
		printf("%s", line);
}

Hints:
Do not leak file descriptors!
This exercise is inspired by the libc's popen().

--------------------------------------------------------------------------------------

** fork y pipe **

1. - Pipe:
        - mecanismo IPC unidireccional.
        - comunican procesos "relacionados".
        - envío de "byte streams".
        - pipe asociado a dos fd.

2. - Funciones:
        crear pipe: int pipe(int fd[2]); // fd[0] : READ; fd[1] : WRITE
        escribir:   ssize_t write(int fd, const void *buf, size_t nr);
        leer:       ssize_t read(int fd, const void *buf, size_t nr);
        cerrar:     int close(int fd);

*/

#include <unistd.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const argv[], char type)
{
    int fd[2];
    pid_t pidC;

    if(!file || !argv || (type != 'r' || type != 'w'))
        return (-1);
    
    if(pipe(fd) == -1)
        return (-1);
    
    pidC = fork();
    if(pidC == -1)
    {
        close(fd[0]);
        close(fd[1]);
        return (-1);
    }
    if(pidC == 0) // hijo
    {
        if(type == 'r')
        {
            if (dup2(fd[1], STDOUT_FILENO) == -1)
                exit(1);
        }
        else
        {
            if(dup2(fd[0], STDOUT_FILENO) == -1)
                exit(1);
        }
        close(fd[0]);
        close(fd[1]);
        execvp(file, argv);
        exit(1);
    }
    else
    {
        if(type == 'r')
        {
            close(fd[1]);
            return (fd[0]);
        }
        else
        {
            close(fd[0]);
            return (fd[1]);
        }
    }
}
