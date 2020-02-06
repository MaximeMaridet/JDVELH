#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE_ARRAY_DESTINATIONS 5

typedef struct Chapter Chapter;
struct Chapter {
	char description[200];
	int goldplus;
	int healthplus;
	int destination[SIZE_ARRAY_DESTINATIONS];
	int nDestinations;
};

typedef struct Ressources Ressources;
struct Ressources {
	int health;
	int gold;
	int maxHealth; 
	int minGold;
};	
	

int deplacement (Ressources*, Chapter*, int, int);

int main(){
	int input = 0;
	int location = 0;
	
	Chapter chapter0 = {
		.description = "Chapter 1",
		.goldplus = 0,
		.healthplus = 0,
		.destination = {1,2},
		.nDestinations = 2
	};
	
	Chapter chapter1 = {
		.description = "Chapter 1",
		.goldplus = -2,
		.healthplus = -20,
		.destination = {2, 3},
		.nDestinations = 2
	};
	
	Chapter chapter2 = {
		.description = "Chapter 2",
		.goldplus = -2,
		.healthplus = -15,
		.destination = {3},
		.nDestinations = 1
	};
	
	Chapter chapter3 = {
		.description = "Chapter 3",
		.goldplus = -2,
		.healthplus = -10,
		.destination = {},
		.nDestinations = 0
	};
	
	Chapter chapters[4] = {chapter0, chapter1, chapter2, chapter3};
	
	Ressources Ressources = {
		.health = 100,
		.maxHealth = 100,
		.gold = 10,
		.minGold = 0
		
	};
	
	
	printf ("Which way ?\n");
	printf ("(1) Left (2) Right\n");
	do {
		scanf("%1d", &input);
	} while (input != 1  && input != 2);
	location = input;
	switch (location) {
		case 1:
			printf ("You take the blue door on your left.\n");
			break;
		case 2:
			printf ("You take the metal door on your right.\n");
			break;
	}
	deplacement (&Ressources, chapters, 0, 0);
	deplacement (&Ressources, chapters, 0, 1);
	
}

int deplacement (Ressources* ressources, Chapter* chapters, int from, int to) {
	int nDestinations = chapters[from].nDestinations;
	for (int i = 0; i<nDestinations; i++) {
		if (chapters[from].destination[i] == to) {
			printf("%s\n", chapters[to].description);
			//Vie
			printf("HP : %d => ", (*ressources).health);
			(*ressources).health+=chapters[to].healthplus;
			if ((*ressources).health > (*ressources).maxHealth)
				(*ressources).health = (*ressources).maxHealth;
			printf("HP : %d => ", (*ressources).health);
			//Gold
			printf("Gold : %d => ", (*ressources).gold);
			(*ressources).gold+=chapters[to].goldplus;
			if ((*ressources).gold < (*ressources).minGold)
				(*ressources).gold = (*ressources).minGold;
			printf("Gold : %d => ", (*ressources).gold);
			if ((*ressources).health<0) {
				printf("YOU DIED");
				return 2;
			} else {
				return 1;
			}
			
		}	
		
	}
	printf("You can't go there !\n");
	return 0;
	
}