#include "../include/cub3D.h"

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
