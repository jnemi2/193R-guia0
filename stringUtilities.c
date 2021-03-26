//
// Created by bauti on 3/26/2021.
//

#include "stringUtilities.h"
#include <stdlib.h>

int length(char txt[])
{
    char * character = &txt[0];
    int len = 0;

    while (*(character + len) != '\0')
        len++;

    return len;
}

char *reverse(char * text)
{
    int len = length(text);
    char * reversed;
    reversed = (char*) malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
    {
        *(reversed + i) = *(text + len - 1 - i);
    }
    *(reversed + len) = '\0';
    return reversed;
}
