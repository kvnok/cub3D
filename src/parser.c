#include "../include/cub3D.h"

void	read_from_file(char **str, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			if ((*str)[0] == '\0' || int_strlen(*str) == 0)
			{
				free(*str);
				exit(1);
			}
			break ;
		}
		*str = strjoin_free(str, &line);
		if (*str == NULL)
		{
			free(*str);
			exit(1);
		}
		if (line != NULL)
			free(line);
	}
	// printf("|%s|\n", *str);
	close(fd);
}

void parserInitNull(t_parser *stuff) {
	stuff->filename = NULL;
	stuff->pathNorthTexture = NULL;
	stuff->pathSouthTexture = NULL;
	stuff->pathEastTexture = NULL;
	stuff->pathWestTexture = NULL;
	stuff->floorColor = 0;
	stuff->ceilingColor = 0;
	stuff->map = NULL;
	// stuff->playerPos = NULL;
	stuff->startingDir = 0;
	stuff->readout = NULL;
}

int parser(int argc, char **argv, t_parser *stuff) {
	(void) argc;
	parserInitNull(stuff);	
	stuff->filename = argv[1];
	int fd = open(stuff->filename, O_RDONLY);
	if (fd < 0) {
		// error out
	}
	char *str = ft_calloc(sizeof(char *) + 1, 1);
	if (str == NULL) {
		// error out
	}
	read_from_file(&str, fd);
	// printf("%s", str);
	stuff->readout = ft_split(str, '\n');
	printArr(stuff->readout);
	return 0;
}
