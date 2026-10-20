#include "push_swap.h"

void free_split(char **res)
{
    size_t i;
    i = 0;
    if(!res)
        return ;
    while (res[i])
    {
        free(res[i]);
        i++;
    }
    free(res);
}
