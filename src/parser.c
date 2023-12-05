#include "../include/cub3D.h"

/*
rawElements
rawMap
*/
int divideRawConfig(t_parser *p) {
	int i = 0;
	p->rawElements = callocStringArr(6);
	if (p->rawElements == NULL) {
		// error out
	}
	while(p->readout[i] != NULL) {
		
		i++;
	}
	return 0;
}

int parser(char **argv, t_parser *p) {
	if (parserInit(argv, p) == 1) {
		return parserError("parserInit Error!\n");
	}
	printArr(p->readout);
	// if (devideRawConfig(p) == 1) {
	// 	freeArr(p->readout);
	// 	return parserError("devideRawConfig Error!\n");
	// }
	// // maybe free p->readout and set it to NULL regardless
	// printArr(p->rawElements);
	// printArr(p->rawMap);

	// printf("testok\n");
	// loop through all lines
	// setElements(p);
	// check for flags, key value pair array, constants and booleans
	// readout raw map data
	// check for obvious errors like illegal characters
	// floodfill map
	// errorcheck values of floor and ceiling color
	
	return 0;
}
