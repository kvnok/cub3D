#ifndef DDA_H
# define DDA_H

# define X_SIDE 1
# define Y_SIDE 2

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_coors_double
{
	double	x;
	double	y;
}	t_coors_double;

typedef struct s_coors_int
{
	int	x;
	int	y;
}	t_coors_int;

typedef struct s_dda
{
	double			planeX;
	double			planeY;
	t_coors_double	playerPos;
	t_vector		playerDir;
	double			cameraX;
	t_vector		rayDir;
	t_coors_int		mapPos;
	double			deltaDistX;
	double			deltaDistY;
	int				stepMapX;
	int				stepMapY;
	double			sideDistX;
	double			sideDistY;
	double			perpWallDist;
	int				sideHit;
}	t_dda;

#endif