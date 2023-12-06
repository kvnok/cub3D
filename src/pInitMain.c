#include "../include/cub3D.h"

int parserInit(char **argv, t_parser *p) {
	parserSetNull(p);
	initDict(p);
	p->filename = argv[1];
	if (isFileNameCorrect(p->filename) == false)
		return parserError("isFileNameCorrect() false\n");
	char *str = ft_calloc(sizeof(char *) + 1, 1);
	if (str == NULL)
		return parserError("str ft_calloc() fail\n");
	if (extractTextFromFile(&str, p) == 1) {
		free(str);
		return parserError("extractTextFromFile() fail\n");
	}
	if (isTabInside(str) == true) {
		free(str);
		return parserError("tab found, not allowed!");
	}
	if (checkElementCountandNewlines(str) == 1) {
		free(str);
		return parserError("checkElementCountandNewlines() fail\n");
	}
	p->readout = ft_split(str, '\n');
	free(str);
	if (p->readout == NULL)
		return parserError("p->readout ft_split() fail\n");
	return 0;
}
