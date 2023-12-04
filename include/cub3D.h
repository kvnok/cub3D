#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <limits.h>
#include <stdbool.h>
#include <sys/time.h>
#include <math.h>
#include <fcntl.h>
#include "../MLX42/include/MLX42/MLX42.h"
#include "../MLX42/include/MLX42/MLX42_Int.h"
#include <time.h>
#include <errno.h>
#include "../libft/libft.h"

typedef struct s_vector
{
	int x;
	int y;
}	t_vector;

/*
filename.cub
paths to textures
floor color
ceiling color
map without player (N, W, S, E) in it
original player x and y
player starting direction
*/
typedef struct s_parser
{
	char		*filename;
	char		*pathNorthTexture;
	char		*pathSouthTexture;
	char		*pathEastTexture;
	char		*pathWestTexture;
	int			floorColor;
	int			ceilingColor;
	char		**map;
	t_vector	playerPos;
	char		startingDir;
}	t_parser;

// parser.c
void parser(int argc, char **argv, t_parser *stuff);

#endif
