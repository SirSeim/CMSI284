#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* rotate (char* s, int k) {
    int length = strlen(s);
    int i = 0;
    char rotated[length + 1];
    char* result = rotated;

    while(i < k)
}

int main(int argc, char** argv) {
    printf("%c\n", rotate(argv[1], 69));
    return 0;
}