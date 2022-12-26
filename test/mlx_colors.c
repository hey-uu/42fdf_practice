#include "minilibx/mlx.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_transparency(int trgb)
{
	return ((trgb >> 24) & 0xff);
}

int	get_red(int trgb)
{
	return ((trgb >> 16) & 0xff);
}

int	get_green(int trgb)
{
	return ((trgb >> 8) & 0xff);
}

int	get_blue(int trgb)
{
	return (((trgb) & 0xff));
}
