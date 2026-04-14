#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
    if (!s)
        return NULL;
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == (char)c)
            return s + i;
        i++;
    }
    return NULL;
}

size_t ft_strlen(char *s)
{
    if (!s)
        return 0;
    
    size_t i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i;

    if (!dst || !src)
        return NULL;
    i = 0;
    while (i < n)
    {
        ((char *)dst)[i] = ((const char *)src)[i];
        i++;
    }
    return dst;
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
    size_t size1;
    char *tmp;

    if (!s1 || !s2)
        return 0;

    // 1. Calculamos la longitud previa acumulada.
    if (*s1)
        size1 = ft_strlen(*s1);
    else
        size1 = 0;

    // 2. Reservamos la cadena resultado: anterior + nuevo fragmento + '\0'.
    tmp = malloc(size1 + size2 + 1);
    if (!tmp)
        return 0;

    // 3. Copiamos primero lo que ya teniamos acumulado.
    if (*s1)
        ft_memcpy(tmp, *s1, size1);

    // 4. Copiamos a continuacion el nuevo bloque leido.
    ft_memcpy(tmp + size1, s2, size2);

    // 5. Cerramos string y actualizamos el puntero acumulado.
    tmp[size1 + size2] = '\0';
    free(*s1);
    *s1 = tmp;
    return 1;
}

void *ft_memmove(void *dst, const void *src, size_t n)
{
    if ((!dst || !src) && n > 0)
        return NULL;
    size_t i;

    // 1. Si se solapan y destino queda por delante, copiamos hacia atras.
    if (dst > src)
    {
        i = n;
        while (i > 0)
        {
            i--;
            ((char *)dst)[i] = ((const char *)src)[i];
        }
    }
    // 2. Sin solape, copiamos normal.
    else
        ft_memcpy(dst, src, n);
    return dst;
}

char *get_next_line(int fd)
{
    static char b[BUFFER_SIZE + 1] = "";
    char *tmp;
    char *res = NULL;
    int read_res;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    // 1. Repetimos hasta poder devolver una linea completa o llegar a EOF/error.
    while(1)
    {
        // 1.1. Si el buffer ya tiene '\n', devolvemos esa linea.
        tmp = ft_strchr(b, '\n');
        if (tmp)
        {
            if(!str_append_mem(&res, b, tmp - b + 1))
                return free(res), NULL;

            // 1.2. Desplazamos el resto del buffer para la siguiente llamada.
            ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
            return res;
        }

        // 1.3. Si no hay salto de linea, acumulamos todo el buffer actual.
        if(!str_append_mem(&res, b, ft_strlen(b)))
            return free(res), NULL;

        // 2. Leemos mas datos para intentar completar la linea.
        read_res = read(fd, b, BUFFER_SIZE);
        if (read_res <= 0)
        {
            b[0] = '\0';
            if (res && *res)
                return res;
            free(res);
            return NULL;
        }

        // 3. Convertimos el bloque leido en string valida para operar con strchr/strlen.
        b[read_res] = '\0';
    }
}
