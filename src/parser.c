#include "../include/cub3D.h"

int parser(int argc, char **argv, t_parser *p) {
	if (parserInit(argc, argv, p) == 1) {
		return 1;
	}
	// check for flags, key value pair array, constants and booleans
	dict dict[6];
	
	dict[0].key = NORTH;
	dict[1].key = SOUTH;
	dict[2].key = EAST;
	dict[3].key = WEST;
	dict[4].key = FLOOR;
	dict[5].key = CEILING;
	int i = 0;
	while(i < 6) {
		dict[i].flag = false;
		i++;
	}
	// loop through all lines
	
	// grab part until space

	// readout raw map data
	// check for obvious errors like illegal characters
	// floodfill map
	// errorcheck values of floor and ceiling color
	
	return 0;
}
