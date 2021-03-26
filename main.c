#include <stdio.h>
#include <stdlib.h>
#include "stringUtilities.h"

int main() {
    char text[] = "Hello, World!";
    char * reversedText = reverse(&text[0]);
    printf("Original: '%s' --> Reversed: '%s'\n", text, reversedText);

    free(reversedText);

    return 0;
}
