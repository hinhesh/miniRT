#ifndef FUNCTION_MATHS_H
# define FUNCTION_MATHS_H
# define PI 3.14159265359
typedef  struct s_coord
{
    double x;
    double y;
    double z;
}t_coord;

typedef struct s_ray
{
    t_coord *origin;
    t_coord *direction;
}t_ray;

typedef struct s_light
{
    t_coord *pos;
    int     i;//intensite
}t_light;



typedef struct s_sphere
{
    t_coord *origin;
    double  rayon;
    t_coord *color; //x -> R y--> G z-->B
    
}t_sphere;
void    ft_vectors_mult_by_two(t_coord *a, t_coord *b, t_coord *res);
double  ft_max(double a,const double b);
int intersection_sphere2(t_sphere *s, t_ray *r);
void    ft_coord(double x, double y,double z, t_coord *pt);
void    ft_vect(t_coord *a, t_coord *b, t_coord *ab);
void    ft_produit_vectoriel(t_coord *a, t_coord *b, t_coord *prod);
void    ft_normalize(t_coord* a);
double    ft_norm2(t_coord* a);
double  ft_scal_produce(t_coord *a, t_coord *b);
void    ft_vectors_div(t_coord *a, double b, t_coord *res);
void    ft_vectors_mult(t_coord *a, double b, t_coord *res);
void    ft_vectors_add(t_coord *a, t_coord *b, t_coord *res);
void    ft_vectors_substract(t_coord *a, t_coord *b, t_coord *res);
int intersection_sphere(t_sphere *s, t_ray *r, t_coord *pos, t_coord *normal);
#endif