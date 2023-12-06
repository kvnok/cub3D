#include "../include/cub3D.h"

int main(int argc, char **argv) {
	t_parser p;

	if (argc != 2)
		return parserError("argc != 2\n");
	if (parser(argv, &p) == 1) {
		// error out
		freeArr(p.readout);
		return parserError("parser() fail\n");
	}
	freeArr(p.readout);
	return 0;
}
