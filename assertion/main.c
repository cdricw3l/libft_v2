#include "libft.h"

void putnbr_hex(int n, char *base)
{
    long nb;
    char c;
    size_t base_len;

    nb = n;
    base_len = strlen(base);
    if (nb < 0)
    {
        write(1, "-", 1);
        nb = nb * -1;
    }
    if(nb >= (long)base_len)
        putnbr_hex(nb / base_len, base);
    c = base[nb % base_len];
    write(1, &c, 1);
}

int main(void)
{  
    //assertion();

    int fd;
    int b_read;
    char buffer[1024];
    char *sub;

    fd = open("test", O_RDONLY);
    if (fd < 0)
    {
        printf("open error\n");
        return (1);
    }
    
    while((b_read = read(fd, buffer, 1023)) > 0)
    {
        if (b_read < 0)
        {
            printf("read error\n");
            return (1);
        }
        
        buffer[b_read] = '\0';

        size_t i;

        i = 0;
        while (i < 1024)
        {
            putnbr_hex(buffer[i], "0123456789ABCDEF");
            write(1, " ", 1);

            i++;
        }
        printf("\n");
        break;
        
    }
    

    return (0);
}