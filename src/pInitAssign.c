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
	p->dict[0].key = NORTH;
	p->dict[1].key = SOUTH;
	p->dict[2].key = EAST;
	p->dict[3].key = WEST;
	p->dict[4].key = FLOOR;
	p->dict[5].key = CEILING;
	int i = 0;
	while(i < 6) {
		p->dict[i].flag = false;
		p->dict[i].value = NULL;
		i++;
	}
}
