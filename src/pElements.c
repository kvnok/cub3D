#include "../include/cub3D.h"

// handle color
int setDictColor(t_parser *p, int dictIndex, char *line) {
	p->dict[dictIndex].value = line;
	int i = 0;
	while(line[i]) {
		if (line[i] != ',' && ft_isdigit(line[i]) == false) {
			return parserError("incorrect char color\n");
		}
		i++;
	}
	return 0;
}

/*
spacing
loop until '\0'
set in dict key
*/
int setDictPath(t_parser *p, int dictIndex, char *line) {
	p->dict[dictIndex].value = line;
	mlx_texture_t *test;
	test = mlx_load_png(line);
	if (!test)
		return parserError("incorrect texture path\n");
	mlx_delete_texture(test);
	return 0;
}

// maybe function pointer in struct
int selectFunction(t_parser *p, int dictIndex, char *line) {
	int i = 0;
	while(line[i] && line[i] != ' ')
		i++;
	while(line[i] && line[i] == ' ')
		i++;
	if (p->dict[dictIndex].func(p, dictIndex, line + i) == 1) {
		return parserError("Dict Function Pointer fail\n");
	}
	return 0;
}

int setElementValues(t_parser *p) {
	int i = 0;
	int j = 0;
	bool flag = false;
	while (i < 6) {
		j = 0;
		flag = false;
		while (j < 6) {
			if (strncmp(p->dict[j].key, p->readout[i], ft_strlen(p->dict[j].key)) == 0) {
				// printf("%s== %s\n", p->dict[j].key, p->readout[i]);
				if (p->dict[j].flag == true)
					return parserError("duplicate element\n");
				p->dict[j].flag = true;
				flag = true;
				if (selectFunction(p, j, p->readout[i]) == 1)
					return parserError("selectFunction() fail\n");
			}
			j++;
		}
		if (flag == false)
			return parserError("no element match found\n");
		i++;
	}
	return 0;
}
