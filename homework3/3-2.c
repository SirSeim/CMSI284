#include <stdio.h>
#include <string.h>

int NOTES = 12;
int STEPS = 6;
int major_scale[] = {2,2,1,2,2,2};
int minor_scale[] = {2,1,2,2,1,2};
char* keys[] = {"A","A#","B","C","C#","D","D#","E","F","F#","G","G#"};

void get_major(char* note, int counter) {
    printf("%s Major:    ", note);
    for (int i = 0, j = 0; i <= STEPS; j += major_scale[i++]) {
        printf("%-4s", keys[(j + counter) % NOTES]);
    }
}

void get_minor(char* note, int counter) {
    printf("\n%s Minor:    ", note);
    for (int i = 0, j = 0; i <= STEPS; j += minor_scale[i++]) {
        printf("%-4s", keys[(j + counter) % NOTES]);
    }
}

int main(int argc, char** argv) {
    bool invalid_args = argc != 2;
    if (invalid_args) {
        printf("YOU NEED JUST ONE ARGUMENT YA DUNCE");
        return 69;
    }

    for (int i = 0; i < NOTES; i++) {
        bool note_found = strcmp(argv[1], keys[i]) == 0;
        if (note_found) {
            get_major(argv[1], i);
            get_minor(argv[1], i);

            printf("\n");
            return 0;
        }
    }
    printf("THIS KEY IS NOT VALID: %s\n", argv[1]);
    return 6969;
}