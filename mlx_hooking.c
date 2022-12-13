#include "minilibx/mlx.h"
#include "mlx_keycode.h"
#include <stdio.h>

#define XSIZE 1920
#define YSIZE 1080
#define TITLE "hello"
#define BYTESIZE 8



typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == H)
		printf("HELLO from KEY_HOOK!\n");
	return (0);
}

int	mouse_hook(int mousecode, t_vars *vars)
{
	if (mousecode == LEFT_CLICK)
		printf("HELLO from MOUSE_HOOK!\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, XSIZE, YSIZE, TITLE);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}