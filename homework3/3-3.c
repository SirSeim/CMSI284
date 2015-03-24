#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) a<b ? b : a

char* buff_string (char* first, char* second){
    char* result = "";
    int max_length = max(strlen(first), strlen(second));
    bool first_bigger = strlen(first) > strlen(second);

    for (int i = 0; i < max_length; i++) {
        if (first_bigger) {
            if (i < strlen(second) && first[i] < second[i]) {
                result += second[i];
            } else {
                result += first[i];
            }
        } else {
            if (i < strlen(first) && second[i] < first[i]) {
                result += first[i];
            } else {
                result += second[i];
            }
        }
        //printf("bull: %s\n", result);
    }
    return result;
}

int main() {
    char* first = "first";
    char* second = "second";
    printf("%s\n", buff_string(first, second));

    return 0;
}