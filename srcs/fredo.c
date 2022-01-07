#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

void	opti_sort(t_data *data)
{
	int	pivot;
	int	save_pivot[50] = {};
	int	old_l1size;
	int	old_l2size;
	int	i;
	int j;

	//printf("nb misfit : %d\n", spot_misfits(data->l1));
	j = 0;
	while (data->l1size > 3 && pivot >= 0)
	{
		pivot = get_mediane_stack(data->l1, data->l1size);
//		printf("pivot : %d\n", pivot);
		old_l1size = data->l1size;
		i = 0;
		while (i < old_l1size && get_index_first_l(data->l1, pivot) != -1)
		{
			if (*(int *)(data->l1->content) < pivot)
				pb(data);
			else
				ra(data);
			i++;
		}
		save_pivot[j] = pivot;
		j++;
	}
//	print_lst(*data);
	sort_3a(data);
	//print_lst(*data);

	j--;
//	printf("doing b\n");
	while (data->l2size > 3)
	{
		if (j >= 0)
			pivot = save_pivot[j];
		else
		{
			pivot = get_mediane_stack(data->l2, data->l2size);
		}	
//		printf("pivot : %d\n", pivot);
		old_l2size = data->l2size;
		//if (pivot <= 4)
		//	break ;
		i = 0;
		while (i < old_l2size && get_index_first_g(data->l2, pivot) != -1)
		{
//			printf("Doing something. value : %d, pivot : %d", *(int *)(data->l2->content), pivot);
			if (*(int *)(data->l2->content) >= pivot)
			{
//				printf(" : PA\n");
				pa(data);
				if (*(int *)(data->l1->content) == pivot)
				{
//					printf("THIS IS THE PIVOT\n");
					ra(data);
				}
			}
			else
			{
//				printf(" : RB\n");
				rb(data);
			}
			i++;
			if (get_index_first_ge(data->l2, pivot) == -1)
			{
//				printf(" : RRA for pivot\n");
				rra(data);
			}
		}

		j--;
	}
	sort_3b(data);
	while (data->l2size)
		pa(data);
	print_lst(*data);
	printf("nb misfit : %d\n", spot_misfits(data->l1));
	
}