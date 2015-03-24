#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* movin (char* word, unsigned int integer){
    int length = strlen(word);
    int move_number = integer % length;
    char* result = (char*)malloc(length + 1);
    
    for (int j = 0; j < (length - move_number); j++) {
        result[j] = word[j + move_number];
    }

    for (int j = 0; j < move_number; j++) {
        result[length - move_number + j] = word[j];
    }
    return result;
}

int main(int argc, char** argv) {
    char* word = argv[1];
    unsigned int integer = atoi(argv[2]);
    char* switcheroo = movin (word, integ);
    printf("%s\n", switcheroo);
    free(switcheroo);
    return 0;
}