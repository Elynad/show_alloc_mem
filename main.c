#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

char    *dec_to_hex(uint64_t dec);

int     main()
{
    char        a;
    uint64_t    ptr;

    ptr = (uint64_t)&a;
    printf("POINTER VALUE = %lu\n", ptr);
    printf("TRUE ADDRESS  = %p\n", &a);
    printf(dec_to_hex(ptr));

    return (0);
}

char    *dec_to_hex(uint64_t dec)
{
    char    result[9];
    int     remainder;
    int     index;

    result[8] = '\0';
    index = 7;
    while (dec != 0)
    {
        remainder = dec % 16;
        printf("DEBUG | Iter %d, remainder = %d\n", index, remainder);
        dec = dec / 16;
        if (remainder > 9)
            result[index] = remainder % 10 + 'A';
        else
            result[index] = remainder % 10 + '0';
        index--;
    }
    while (index >= 0)
    {
        printf("DEBUG | Iter %d, setting default 0\n", index);
        result[index] = '0';
        index--;
    }
    printf("\nEND ; RESULT = %s\n", result);
    return (result);
}
