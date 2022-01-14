
#include "push_swap.h"

int __is_min_index(t_stack *a,int index_a, int index_b)
{
    t_stack tmp;

    if (index_a > index_b)
        return (0);
    tmp = a;
    while (tmp != NULL)
    {

    }


}
int __cost_stack_b(t_data *data)
{
    t_stack *a;
    t_stack *b;
    int     r;
    a = data->a;
    b = data->b;

    while (__is_min_index(a, a->index, b->index) != 1)
    {
        if (data->a != 3)
            break;
        if(data->a == 3)
            r++;
        a = a->next; 
    }
    while(data->a != 3)
        a = a->next;
    while (__is_min_index(a,b->index) == 1
    &&__is_max_index(a,b->index) == 1)
    {
        if (data->a != 3)
            break;
        if(data->a == 3)
            rr++;
        a = a->next; 
    }
}