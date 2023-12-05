#include "../include/cub3D.h"

int parser(int argc, char **argv, t_parser *stuff) {
	if (parserInit(argc, argv, stuff) == 1) {
		return 1;
	}
	// check for flags, key value pair array, constants and booleans
	// readout raw map data
	// check for obvious errors like illegal characters
	// floodfill map
	// errorcheck values of floor and ceiling color
	
	return 0;
}
