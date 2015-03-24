#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) a<b ? b : a

char* buff_string (char* first, char* second){
    int max_length = max(strlen(first), strlen(second));
    bool first_bigger = strlen(first) > strlen(second);
    char* result = (char*)malloc(max_length + 1);
    printf("%s\n%s\n", first, second);

    for (int i = 0; i < max_length; i++) {
        if (first_bigger) {
            if (i < strlen(second) && first[i] < second[i]) {
                result[i] = second[i];
            } else {
                result[i] = first[i];
            }
        } else {
            if (i < strlen(first) && second[i] < first[i]) {
                result[i] = first[i];
            } else {
                result[i] = second[i];
            }
        }
    }
    return result;
}

int main(int argc, char** argv) {
    char* first = "first";
    char* second = "second";
    if (argc != 3) {
        printf("GIVE ME TWO STRINGS YOU IDIOT!\n");
        return 69;
    }
    first = argv[1];
    second = argv[2];

    char* buffed = buff_string(first, second);
    printf("%s\n", buffed);
    free(buffed);

    return 0;
}