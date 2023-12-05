#include "../include/cub3D.h"

/*
rawElements 0-5
rawMap 6-end

assigning readout[i]
might need to copy it over later
*/
int getRawElementsAndMap(t_parser *p) {
	int i = 0;
	int arrLength = getLengthArr(p->readout);
	p->rawElements = callocStringArr(6);
	if (p->rawElements == NULL) {
		return parserError("p->rawElements alloc fail\n");
	}
	p->rawMap = callocStringArr(arrLength - 6);
	while(p->readout[i] != NULL) {
		if (i < 6) {
			p->rawElements[i] = p->readout[i];
		}
		else {
			p->rawMap[i-6] = p->readout[i];
		}
		i++;
	}
	return 0;
}

int parser(char **argv, t_parser *p) {
	if (parserInit(argv, p) == 1) {
		return parserError("parserInit() Error!\n");
	}
	// printArr(p->readout);
	if (getRawElementsAndMap(p) == 1) {
		freeArr(p->readout);
		return parserError("getRawElementsAndMap() Error!\n");
	}
	// maybe free p->readout and set it to NULL regardless
	printArr(p->rawElements);
	printArr(p->rawMap);

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
