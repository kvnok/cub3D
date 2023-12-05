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

#define NORTH "NO "
#define SOUTH "SO "
#define EAST "EA "
#define WEST "WE "
#define FLOOR "F "
#define CEILING "C "

typedef struct s_parser t_parser;

typedef int (*func)(t_parser *, int, char *);

// dictionary
// mostly used for elements
typedef struct s_dict {
	char *key;
	bool flag;
	char *value;
	func func;
}	dict;

typedef struct s_vector {
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
typedef struct s_parser {
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

	char		**readout;
	dict		dict[6];

	char		**rawElements;
	char		**rawMap;
}	t_parser;

// parserUtils.c
void	freeArr(char **stringArr);
void	printArr(char **stringArr);
int		parserError(char *errorText);
char	**callocStringArr(int amount);
int		getLengthArr(char **stringArr);

// parser.c
int		parser(char **argv, t_parser *p);

// pInitMain.c
int		parserInit(char **argv, t_parser *p);

// pInitAssign.c
void	parserSetNull(t_parser *p);
void	initDict(t_parser *p);

// pInitCheck.c
int		loopThroughElements(char *str, int *elementCount);
int		checkElementCountandNewlines(char *s);
bool	isFileNameCorrect(char *fileName);

// pInitRead.c
int		fillStringFromFile(char **str, int fd);
int		extractTextFromFile(char **str, t_parser *p);

// parserElements.c
int handleColor(t_parser *p, int dictIndex, char *line);
int handleTexturePath(t_parser *p, int dictIndex, char *line);
int		setElementValues(t_parser *p);

#endif
