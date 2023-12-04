#include "../include/cub3D.h"

int main(int argc, char **argv) {
	printf("cub3D\n");
	mlx_t *mlx;
	int size = 200;
	mlx = mlx_init(size*16, size*9, "cub3D", true);
	// mlx = mlx_init(3840, 2160, "cub3D", true);
	// mlx = mlx_init(size*4, size*3, "cub3D", true);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return 0;
}
