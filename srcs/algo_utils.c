#include "push_swap.h"

int ft_something_push(t_data *data)
{
    t_stack *tmp;

    tmp = data->a;
    while (!tmp)
    {
        if (tmp->nb < data->median_a)
            return (1);
        tmp = tmp->next;
    }
    return (0);
}