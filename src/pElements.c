#include "../include/cub3D.h"

// handle color
int handleColor(t_parser *p, int dictIndex, char *line) {
	printf("handleColor called\n");
	p->dict[dictIndex].value = line+1;
	return 0;
}

/*
spacing
loop until '\0'
set in dict key
*/
int handleTexturePath(t_parser *p, int dictIndex, char *line) {
	printf("handleTexturePath called\n");
	int i = 0;
	while(line[i] && line[i] != ' ')
		i++;
	while(line[i] && line[i] == ' ')
		i++;
	p->dict[dictIndex].value = line + i;
	return 0;
}

// maybe function pointer in struct
int selectFunction(t_parser *p, int dictIndex, char *line) {
	p->dict[dictIndex].func(p, dictIndex, line);
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
				printf("%s== %s\n", p->dict[j].key, p->readout[i]);
				if (p->dict[j].flag == true)
					return parserError("duplicate element\n");
				p->dict[j].flag = true;
				flag = true;
				selectFunction(p, j, p->readout[i]);
			}
			j++;
		}
		if (flag == false)
			return parserError("no element match found\n");
		i++;
	}
	return 0;
}
