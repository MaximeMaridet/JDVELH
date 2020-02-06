#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Chapter Chapter;
struct Chapter {
	char description[200];
	int goldplus;
	int healthplus;
	char* nextChapter[2];
};

void deplacement (Chapter);

int main(){
	int input = 0;
	int location = 0;
	
	Chapter chapter1 = {
		.description = "Chapitre 1",
		.goldplus = 0,
		.healthplus = 0,
		.nextChapter = {"chapter2", "chapter3"}
	};
	
	Chapter chapter2 = {
		.description = "Chapitre 2",
		.goldplus = 0,
		.healthplus = 0,
		.nextChapter = {"chapter3"}
	};
	
	Chapter chapter3 = {
		.description = "Chapitre 3",
		.goldplus = 0,
		.healthplus = 0,
		.nextChapter = {}
	};
	
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
			break;
	}
	
	deplacement(chapter1);
	deplacement(chapter2);
	deplacement(chapter3);
}

void deplacement (Chapter chapter) {
	printf("%s\n", chapter.description);