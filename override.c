//
// Created by bauti on 4/11/2021.
//

#include "override.h"
#include <stddef.h>

int * overrideMalloc(int requestedSize, int memory[])
{
    int * assignedMemory = NULL;
    //Check memory
    int index = 0;
    int * tempMem = NULL;
    while (assignedMemory == NULL && (memory[index] == 0 || memory[index] == 1))
    {
        //If a free unit was found
        if (memory[index] == 0)
        {
            tempMem = &memory[index];
            //Checking if there are enough contiguous free units
            for (int i = 0; i < requestedSize; i++)
            {
                //If an occupied unit is found, keep checking from this point
                if (memory[index + i] != 0)
                {
                    tempMem = NULL;
                    index = index + i;
                    break;
                }
            }

            //If tempMem != NULL --> There is enough space
            if (tempMem != NULL)
            {
                assignedMemory = tempMem; //Set assigned memory
                //Reserve allocated memory
                for (int r = 0; r < requestedSize; r++)
                {
                    memory[index + r] = 1;
                }
            }
        }
        index++;
    }

    return assignedMemory;
}