char *ft_strchr(char *s, int c)
{
    if(!s)
        return NULL;

    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == (char)c)
            return s + i;
        i++;
    }
    return NULL;
}


void *ft_memcpy(void *dest, const void *src, size_t n)
/**
* const void *src: no se puede modificar el contenido al que apunta src dentro de la función.
**/
{
    size_t i = 0;
    while(i < n)
    {
        ((char *)dest)[i] = ((char *)src)[i];
        i++;
    }
    return dest;
} 

char *get_next_line(int fd)
{
    static char *b[BUFFER_SIZE + 1] = "";
    char *  res = NULL;
    char *  tmp;
    int     read_res;

    while(1)
    {
        tmp = ft_strchr(b, '\n');

        if(tmp)
        {
            // str_append_mem devuelve 1 si tiene exito y 0 si falla; este if se cumple solo cuando falla porque NOT False es verdadero y NOT True es falso.
            if(!str_append_mem(&res, b, tmp - b + 1))
                return (free(res), NULL);
            // Una vez que se ha copiado el contenido de b hasta el salto de linea, se mueve el contenido restante (si lo hay) al principio del buffer para la siguiente llamada.
            ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1); 
            return res;
        }
        if(!str_append_str(&res, b))
            // El ejemplo no protegía, pero si se hacen varias llamadas sin encontrar \n y str_append_mem falla, se estaría perdiendo la ref a la memoria previamente asignada a res.
            return (free(res), NULL);
    }
    read_res = read(fd, b, BUFFER_SIZE);
    if(read_res <= 0)
    {
        b[0] = '\0';
        
    }
}
