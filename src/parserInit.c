#include "../include/cub3D.h"

int	read_from_file(char **str, int fd) {
	char	*line;

	while (1) {
		line = get_next_line(fd);
		if (line == NULL) {
			if ((*str)[0] == '\0' || int_strlen(*str) == 0) {
				free(line);
				return 1;
			}
			break ;
		}
		*str = strjoin_free(str, &line);
		if (*str == NULL) {
			free(line);
			return 1;
		}
		if (line != NULL) {
			free(line);
		}
	}
	// printf("|%s|\n", *str);
	close(fd);
	return 0;
}

void parserSetNull(t_parser *p) {
	p->filename = NULL;
	p->pathNorthTexture = NULL;
	p->pathSouthTexture = NULL;
	p->pathEastTexture = NULL;
	p->pathWestTexture = NULL;
	p->floorColor = 0;
	p->ceilingColor = 0;
	p->map = NULL;
	// p->playerPos = NULL;
	p->startingDir = 0;
	p->readout = NULL;
	p->rawElements = NULL;
	p->rawMap = NULL;
}

void initDict(t_parser *p) {
	p->dict[0].key = NORTH;
	p->dict[1].key = SOUTH;
	p->dict[2].key = EAST;
	p->dict[3].key = WEST;
	p->dict[4].key = FLOOR;
	p->dict[5].key = CEILING;
	int i = 0;
	while(i < 6) {
		p->dict[i].flag = false;
		p->dict[i].value = NULL;
		i++;
	}
}

int parserInit(char **argv, t_parser *p) {
	initDict(p);
	parserSetNull(p);	
	p->filename = argv[1];
	int fd = open(p->filename, O_RDONLY);
	if (fd < 0) {
		// error out
		return 1;
	}
	char *str = ft_calloc(sizeof(char *) + 1, 1);
	if (str == NULL) {
		// error out
		close(fd);
		return 1;
	}
	if (read_from_file(&str, fd) == 1) {
		// error out
		free(str);
		close(fd);
		return 1;
	}
	// printf("%s", str);
	p->readout = ft_split(str, '\n');
	free(str);
	if (p->readout == NULL) {
		// error out
		close(fd);
		return 1;
	}
	// printArr(p->readout);
	return 0;
}
