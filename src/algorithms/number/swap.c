#include <stddef.h>

#include "algorithms/number/swap.h"

int number_swap(int * number1, int * number2)
{
    if (number1 != NULL && number2 != NULL)
    {
        const int temp = *number1;
        *number1 = *number2;
        *number2 = temp;

        return 0;
    }
    else
    {
        return -1;
    }
}
