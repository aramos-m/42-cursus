void ft_filter (char *buffer, const char *target)
{
    int i = 0;
    int j, k;
    int target_len = strlen(target);

    while (buffer[i])
    {
        j = 0;
        while (target[j] && (target[i + j] == target[j]))
            j++;
        if (j == target_len)
        {
            k = 0;
            while (k < target_len)
            {
                write(1, "*", 1);
                k++;
            }
            i += target_len;
        }
        else
        {
            write(1, &buffer[i], 1)
            i++;
        }
    }
}

int main (int argc, char **argv)
{
    if (argc != 2 || argv[1][0] == '\0')
        return 1;

    char temp[BUFFER_SIZE];
    char *result = NULL;
    char *buffer;
    int total_read = 0;
    size_t bytes;

    // Primera lectura ANTES del bucle
    bytes = read(0, temp, BUFFER_SIZE);

    while (bytes > 0)
    {
        buffer = realloc(result, total_read + bytes + 1);
        if (!buffer)
        {
            free(result);
            perror("Error");
            return 1;
        }
        
        result = buffer;
        memmove(result + total_read, temp, bytes);
        total_read += bytes;
        result[total_read] = '\0'; 

        // 3. Siguiente lectura al FINAL del bucle
        bytes = read(0, temp, BUFFER_SIZE);
    }

    if (bytes < 0)
    {
        perror("Error");
        free(result);
        return 1;
    }

    if (!result)
        return 0;

    ft_filter(result, argv[1]);
    
    free(result);
    return 0;
}