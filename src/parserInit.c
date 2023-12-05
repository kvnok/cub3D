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

int extractTextFromFile(char **str, t_parser *p) {
	int fd = open(p->filename, O_RDONLY);
	if (fd < 0) {
		return parserError("fd < 0\n");
	}
	if (fillStringFromFile(str, fd) == 1) {
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
int loopThroughElements(char *str, int *elementCount) {
	int i = 1;
	if (ft_isalpha(str[0]) == 1) {
		(*elementCount)++;
	}
	while(str[i]) {
		if (str[i-1] == '\n' && str[i] != '\n' && ft_isalpha(str[i]) == false) {
			break;
		}
		if (str[i-1] == '\n' && ft_isalpha(str[i]) == true) {
			(*elementCount)++;
		}
		if (*elementCount == 6) {
			while(str[i] && str[i] != '\n') {
				i++;
			}
			break;
		}
		i++;
	}
	return i;
}

/*
looping through the first part
incrementing 
*/
int checkElementCountandNewlines(char *s) {
	int elementCount = 0;
	int i = loopThroughElements(s, &elementCount);
	// printf("elementCount: %d\n", elementCount);
	if (elementCount != 6) {
		return parserError("Does not have 6 elements\n");
	}
	// printf("|%s|\n", s);
	while(s[i] && s[i] == '\n') {
		i++;
	}
	while(s[i]) {
		if (s[i - 1] == '\n' && s[i] == '\n') {
			return parserError("map contains extra newline\n");
		}
		if (s[i] == '\n' && !(s[i-1] == '1' || s[i-1] == '0')) {
			return parserError("invalid map line\n");
		}
		i++;
	}
	return 0;
}

int parserInit(char **argv, t_parser *p) {
	initDict(p);
	parserSetNull(p);	
	p->filename = argv[1];
	char *str = ft_calloc(sizeof(char *) + 1, 1);
	if (str == NULL) {
		return parserError("str ft_calloc() fail\n");
	}
	if (extractTextFromFile(&str, p) == 1) {
		free(str);
		return parserError("extractTextFromFile() fail\n");
	}
	if (checkElementCountandNewlines(str) == 1) {
		free(str);
		return parserError("checkElementCountandNewlines() fail\n");
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
