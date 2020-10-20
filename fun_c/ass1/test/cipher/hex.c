#include <ctype.h>
#include <stdio.h>

static unsigned char hexdigit2int(unsigned char xd)
{
    if (xd <= '9')
        return xd - '0';
    xd = tolower(xd);
    if (xd == 'a')
        return 10;
    if (xd == 'b')
        return 11;
    if (xd == 'c')
        return 12;
    if (xd == 'd')
        return 13;
    if (xd == 'e')
        return 14;
    if (xd == 'f')
        return 15;
    return 0;
}

int main(void)
{
    int i_st = 0;
    char st[] = "746869737C6973617365637265743132";
    char text[sizeof st + 1], *dst = text;

    while (*st != '\0')
    {
        const unsigned char high = hexdigit2int(st[i_st++]);
        const unsigned char low = hexdigit2int(st[i_st++]);
        *dst++ = (high << 4) | low;
    }
    *dst = '\0';
    printf("Converted '%s', got '%s'\n", st, text);
    return 0;
}