// Write a function to reverse the string

#include <stdio.h>
#include <string.h>

void strrev(char *str)
{
    int len;
    char *start = str;
    char *end;
    int i;

    len = strlen(str);
    end = str + len - 1;

    printf("Length = %d\n", len);
    if(len == 0)
        return;

    for(i = 0; i < len >> 1; ++i) {
        char c = *start;
        *start++ = *end;
        *end-- = c;
    }
}

int main(void)
{
    char str[] = "reverse";

    strrev(str);

    printf("String = %s\n", str);

    return 0;
}
