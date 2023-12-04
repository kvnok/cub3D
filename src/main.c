#include "../include/cub3D.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("pls give one arg\n");
		return 1;
	}

	t_parser stuff;
	if (parser(argc, argv, &stuff) == 1) {
		// error out
	}
	return 0;
}
