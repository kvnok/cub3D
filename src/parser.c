#include "../include/cub3D.h"

void freeArr(char **arr) {
	int i = 0;
	while(arr[i] != NULL) {
		free(arr[i]);
		i++;
	}
	free(arr);
}

void printArr(char **arr) {
	int i = 0;
	while(arr[i] != NULL) {
		printf("%s", arr[i]);
		i++;
	}
}

void parser(int argc, char **argv, t_parser *stuff) {
	
}
