#include <sys/types.h>

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
    size_t i = 0;
    while (i < n)
    {
        ((char *)dst)[i] == ((char *)src)[i];
        i++;
    }
    return dst;
}

int str_append_mem(void **s1, void *s2, size_t size2)
{
    // 1. Comprobamos si hay buffer.
    size_t size1;
    if (*s1)
        size1 = ft_strlen(*s1);
    else
        size1 = 0;
    char *tmp = malloc(size1 + size2 + 1);
    if (!tmp)
        return 0;
    if (*s1)
        ft_memcpy(tmp, *s1, size1);
    ft_memcpy(tmp + size1, s2, size2);
    tmp[size1 + size2] = '\0';
    free(*s1);
    *s1 = tmp;
    return 1;
}

void *ft_memmove(void **dst, const void *src, size_t n)
{
    if (!dst || !src)
        return NULL;
    size_t i;
    if (dst > src)
    {
        i = n;
        while (i > 0)
        {
            i--;
            ((char *)dst)[i] == ((char *)src)[i];
        }
    }
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

    // 1. Comprobamos si ya tenemos una línea completa en el buffer.
    while(1)
    {
        tmp = ft_strchr(b, '\n');
        if (tmp)
        {
            if(!str_append_mem(&res, b, tmp - b + 1))
                return free(res), NULL;
            ft_memmove()

        }
    }

}