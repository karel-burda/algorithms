#include <math.h>

#include "algorithms/number/prime.h"

bool is_prime_using_division(const size_t number)
{
    if (number % 2 == 0 && number > 2)
    {
        return false;
    }

    const double square_root = sqrt((double)number);
    size_t divisor = 3;

    while (divisor < square_root)
    {
        if (number % divisor != 0)
        {
            divisor += 2;
        }
        else
        {
            return false;
        }
    }

    return true;
}

error_code number_is_prime_using_division(const size_t number, bool * is_prime)
{
    if (number > 1 && is_prime != NULL)
    {
        *is_prime = is_prime_using_division(number);

        return E_SUCCESS;
    }
    else
    {
        return E_INVALID_INPUT;
    }
}
