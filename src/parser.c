#include "../include/cub3D.h"

/*
rawElements 0-5
rawMap 6-end

assigning readout[i]
might need to copy it over later
*/
int getRawElementsAndMap(t_parser *p) {
	int i = 0;
	int elementAmount = 6;
	int arrLength = getLengthArr(p->readout);
	p->rawElements = callocStringArr(elementAmount);
	if (p->rawElements == NULL) {
		return parserError("p->rawElements alloc fail\n");
	}
	p->rawMap = callocStringArr(arrLength - elementAmount);
	while(p->readout[i] != NULL) {
		if (i < elementAmount) {
			p->rawElements[i] = p->readout[i];
		}
		else {
			p->rawMap[i-elementAmount] = p->readout[i];
		}
		i++;
	}
	return 0;
}

int parser(char **argv, t_parser *p) {
	if (parserInit(argv, p) == 1)
		return parserError("parserInit() fail\n");
	// printArr(p->readout);
	if (getRawElementsAndMap(p) == 1) {
		freeArr(p->readout);
		return parserError("getRawElementsAndMap() fail\n");
	}
	// maybe free p->readout and set it to NULL regardless
	printArr(p->rawElements);
	printf("-----------------\n");
	printArr(p->rawMap);
	if (setElementValues(p) == 1) {
		freeArr(p->readout);
		return parserError("setElementValues() fail\n");
	}
	return 0;
}
