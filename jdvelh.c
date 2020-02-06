#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
	int input = 0;
	int location = 0;
	
	printf ("Which way ?\n");
	printf ("(1) Left (2) Right\n");
	do {
		scanf("%1d", &input);
	} while (input != 1  && input != 2);
	location = input;
	switch (location) {
		case 1:
			printf ("You take the red door on your left.\n");
			break;
		case 2:
			printf ("You take the metal door on your right.\n");
	}
	
}