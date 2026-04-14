#include "get_next_line.h"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return 1;

    char *line;
    int count = 1;

    while(1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        printf("Linea %d: %s", count, line);
        free(line);
        count++;
	}
    close(fd);
    return 0;
}
