#include "../include/cub3D.h"

/*
INIT STRUCT WITH BASIC THINGS
*/
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

/*
READING OUT FILE
*/
int	fillStringFromFile(char **str, int fd) {
	char	*line;

	while (1) {
		line = get_next_line(fd);
		if (line == NULL) {
			if ((*str)[0] == '\0' || int_strlen(*str) == 0) {
				free(line);
				return parserError("line read fail\n");
			}
			break ;
		}
		*str = strjoin_free(str, &line);
		if (*str == NULL) {
			free(line);
			return parserError("strjoin() fail\n");
		}
		if (line != NULL) {
			free(line);
		}
	}
	return 0;
}

int extractTextFromFile(char **str) {
	int fd = open(p->filename, O_RDONLY);
	if (fd < 0) {
		return parserError("fd < 0\n");
	}
	if (fillStringFromFile(&str, fd) == 1) {
		close(fd);
		return parserError("fillStringFromFile() fail\n");
	}
	close(fd);
	return 0;
}

/*
ENTER ERRORCHECK
*/


// count elements

// get start of map part




int parserInit(char **argv, t_parser *p) {
	initDict(p);
	parserSetNull(p);	
	p->filename = argv[1];
	char *str = ft_calloc(sizeof(char *) + 1, 1);
	if (str == NULL) {
		return parserError("str ft_calloc() fail\n");
	}
	if (extractTextFromFile(&str) == 1) {
		free(str);
		return parserError("extractTextFromFile() fail\n");
	}


	// printf("%s", str);
	p->readout = ft_split(str, '\n');
	free(str);
	if (p->readout == NULL) {
		// error out
		return parserError("p->readout ft_split() fail\n");
	}
	// printArr(p->readout);
	return 0;
}
