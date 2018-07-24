#include <stdio.h>
#include <string.h>

/*
    Algorithm:

    Implement a function to perform basic string compression using the counts
    of repeated characters. For example, the string aabcccccaaa would become
    a2b1c5a3. If the compressed string would not become smaller than the original
    string, your function should return the original string. You can assume the
    string has only uppercase and lowercase letters (a-z)
*/

char *compress(char *string)
{
    char *compressed_string = strdup(string);
    int string_length = strlen(string);
    int character_count = 0;
    int i, j = 0;
    char previous_character;

    memset(compressed_string, '\0', string_length);

    for(i = 0; i < string_length; i++)
    {
        character_count++;

        if(i + 1 > string_length || string[i] != string[i + 1])
        {
            if(j + 2 >= string_length)
            {
                return string;
            }
            compressed_string[j++] = string[i];
            compressed_string[j++] = '0' + character_count;
            previous_character = string[i];
            character_count = 0;
        }
    }

    return compressed_string;
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return -1;
    }

    printf("Compressed string of %s is %s\n", argv[1], compress(argv[1]));

    return 0;
}
