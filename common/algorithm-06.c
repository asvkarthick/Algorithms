#include <stdio.h>
#include <string.h>

/*
    Algorithm:

    Implement an algorithm to determine if a string has all unique characters.
    What if you cannot use additional data structures?
*/

const char *check_unique(char *string)
{
    char character_set[128];
    int i;
    int string_length = strlen(string);

    memset(character_set, 0, 128);

    for(i = 0; i < string_length; i++)
    {
        if(!character_set[string[i]])
        {
            character_set[string[i]] = 1;
        }
        else
        {
            return "NO";
        }
    }

    return "YES";
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return -1;
    }

    printf("%s unique: %s\n", argv[1], check_unique(argv[1]));

    return 0;
}
