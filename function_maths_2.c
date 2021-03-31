#include <math.h>
#include "function_maths.h"

void	ft_vectors_translate(t_coord *a, t_coord *b)
{
	a->x = a->x + b->x;
	a->y = a->y + b->y;
	a->z = a->z + b->z;
}

void	ft_vectors_mult(t_coord *a, double b, t_coord *res)
{
	res->x = a->x * b;
	res->y = a->y * b;
	res->z = a->z * b;
}

void	ft_vectors_add_const(t_coord *a, double b, t_coord *res)
{
	res->x = a->x + b;
	res->y = a->y + b;
	res->z = a->z + b;
}

void	ft_vectors_mult_by_two(t_coord *a, t_coord *b, t_coord *res)
{
	res->x = a->x * b->x;
	res->y = a->y * b->y;
	res->z = a->z * b->z;
}

void	ft_vectors_div(t_coord *a, double b, t_coord *res)
{
	res->x = a->x / b;
	res->y = a->y / b;
	res->z = a->z / b;
}