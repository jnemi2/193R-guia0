#include <stdio.h>
#include "override.h"


int main() {
    printf("Hello, World!\n");

    int memory[MEMORY] = {0};
    memory[MEMORY - 1] = -1;

    overrideMalloc(2, memory);
    overrideMalloc(3, memory);

    for (int i = 0; i < MEMORY; i++)
        printf("%d: %d\n", i, memory[i]);

    return 0;
}
