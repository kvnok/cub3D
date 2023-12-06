#include "../include/cub3D.h"

void parserSetNull(t_parser *p) {
	p->filename = NULL;
	p->pathNorthTexture = NULL;
	p->pathSouthTexture = NULL;
	p->pathEastTexture = NULL;
	p->pathWestTexture = NULL;
	p->floorColor = 0;
	p->ceilingColor = 0;
	p->map = NULL;
	// p->playerPos = NULL;
	p->startingDir = 0;
	p->readout = NULL;
	p->rawElements = NULL;
	p->rawMap = NULL;
}

void initDict(t_parser *p) {
	p->dict[N_INDEX].key = NORTH;
	p->dict[S_INDEX].key = SOUTH;
	p->dict[E_INDEX].key = EAST;
	p->dict[W_INDEX].key = WEST;
	p->dict[F_INDEX].key = FLOOR;
	p->dict[C_INDEX].key = CEILING;
	int i = 0;
	while(i < 6) {
		p->dict[i].flag = false;
		p->dict[i].value = NULL;
		if (i < 4)
			p->dict[i].func = setDictPath;
		else
			p->dict[i].func = setDictColor;
		i++;
	}
}
