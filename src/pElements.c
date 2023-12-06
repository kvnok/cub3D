#include "../include/cub3D.h"

int extractColor(char *line, int32_t *val) {
	char **colors = ft_split(line, ',');
	if (colors == NULL)
		return parserError("ft_split() fail\n");
	if (getLengthArr(colors) != 3)
		return parserError("incorrect amount values\n");
	int32_t values[3];
	int i = 0;
	while(i < 3) {
		values[i] = ft_atoi(colors[i]);
		if (values[i] > 255)
			return parserError("color value too big\n");
		i++;
	}
	*val = pixel_select(values[0], values[1], values[2], 255);
	return 0;
}

int setDictColor(t_parser *p, int dictIndex, char *line) {
	int i = 0;
	int commaCount = 0;
	if (strlen(line) > 11)
		return parserError("incorrect color length\n");
	while(line[i]) {
		if (line[i] != ',' && ft_isdigit(line[i]) == false)
			return parserError("incorrect char color\n");
		if (line[i] == ',')
			commaCount++;
		if (commaCount > 2)
			return parserError("too many commas\n");
		i++;
	}
	if (dictIndex == F_INDEX)
		if (extractColor(line, &p->floorColor) == 1)
			return parserError("incorrect floorColor\n");
	if (dictIndex == C_INDEX)
		if (extractColor(line, &p->ceilingColor) == 1)
			return parserError("incorrect ceilingColor\n");
	return 0;
}

int setDictPath(t_parser *p, int dictIndex, char *line) {
	p->dict[dictIndex].value = line;
	mlx_texture_t *test;
	test = mlx_load_png(line);
	if (test == NULL)
		return parserError("incorrect texture path\n");
	mlx_delete_texture(test);
	return 0;
}

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
