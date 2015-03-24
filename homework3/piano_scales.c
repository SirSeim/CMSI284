#include <stdio.h>
#include <string.h>
 
char* keys[] = {"A","A#","B","C","C#","D","D#","E","F","F#","G","G#"};
int NOTES = 12;
int majors[] = {2,2,1,2,2,2};
int minors[] = {2,1,2,2,1,2};
int STEPS = 6;
 
int main(int argc, char** argv) {
	if (argc != 2) {
		printf("This program requires exactly one command line argument\n");
	return 1;
	}
 
	/* Find the note and outputs its info */
	for (int j = 0; j < NOTES; j++) {
		if (strcmp(argv[1], keys[j]) == 0) {
			printf("%s major:", argv[1]);
			for (int i = 0, k = 0; i <= STEPS; k += majors[i++]) {
				printf("%3s", keys[(k + j) % NOTES]);
			}
			printf("\n%s minor:", argv[1]);
			for (int i = 0, k = 0; i <= STEPS; k += minors[i++]) {
				printf("%3s", keys[(k + j) % NOTES]);
			}
			printf("\n");
			return 0;
		}
	}
	 
	/* If invalid */
	printf("Invalid key: %s\n", argv[1]);
	return 2;
}