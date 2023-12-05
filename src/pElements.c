#include "../include/cub3D.h"

bool isWhitespace(char c) {
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\v') {
		return true;
	}
	return false;
}

/*
all prefixes are a length of 1 or 2
*/
int getPrefixLength(char *s) {
	int i = 0;
	while(s[i]) {
		if (i >= 4) {
			return -1;
		}
		if (isWhitespace(s[i]) == true) {
			break;
		}
		i++;
	}
	if (i != 2 && i != 3) {
		return -1;
	}
	return i-1;
}

// handle color
int handleColor(t_parser *p, int dictIndex, char *line) {
	printf("handleColor called\n");
	return 0;
}

// handle texture path
int handleTexturePath(t_parser *p, int dictIndex, char *line) {
	printf("handleTexturePath called\n");
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
