#include "../include/cub3D.h"

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("pls give one arg\n");
		return 1;
	}

	t_parser p;
	if (parser(argc, argv, &p) == 1) {
		// error out
	}
	return 0;
}
