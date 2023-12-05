#include "../include/cub3D.h"

int parserInit(char **argv, t_parser *p) {
	initDict(p);
	parserSetNull(p);
	if (isFileNameCorrect(p->filename) == false)
		return parserError("isFileNameCorrect() false\n");
	p->filename = argv[1];
	char *str = ft_calloc(sizeof(char *) + 1, 1);
	if (str == NULL)
		return parserError("str ft_calloc() fail\n");
	if (extractTextFromFile(&str, p) == 1) {
		free(str);
		return parserError("extractTextFromFile() fail\n");
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
