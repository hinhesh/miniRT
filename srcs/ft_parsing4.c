#include "minirt.h"

int			ft_cy(char *line, t_scene *scene)
{
	t_cylinder *cylinder;

	if ((cylinder = malloc(sizeof(t_cylinder))) == NULL)
		return (-1);
	ft_lstadd_front(scene->list, ft_lstnew((void *)cylinder
	, 4));
	if ((line = ft_parsing_position(line, &cylinder->base)) == NULL)
		return (-1);
	if ((line = ft_parsing_position(line, &cylinder->direction)) == NULL)
		return (-1);
	if ((line = ft_parsing_rgb(&cylinder->rgb, line)) == NULL)
		return (-1);
	if ((line = ft_parsing_double(line, &cylinder->diameter)) == NULL)
		return (-1);
	if ((line = ft_parsing_double(line, &cylinder->height)) == NULL)
		return (-1);
	(*(scene->list))->magic = ft_atoi_rt(line);
	return (1);
}