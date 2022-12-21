#include "minilibx/mlx.h"
#define XSIZE 1001
#define YSIZE 1000
#define	BYTESIZE	8
#include <stdio.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}			t_img;

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / BYTESIZE));
	*(unsigned int *)dst= color;
}

int	main(void)
{
	void	*dev;
	void	*win;
	t_img	img;

	dev = mlx_init();
	win = mlx_new_window(dev, XSIZE, YSIZE, "new window!");
	img.img = mlx_new_image(dev, XSIZE, YSIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(dev, win, img.img, 0, 0);
	printf("%d, %d, %d", img.bits_per_pixel, img.line_len, img.endian);
	mlx_destroy_image(dev, img.img);
	mlx_loop(dev);

}
