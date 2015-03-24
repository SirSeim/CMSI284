#include <stdio.h>
#include <math.h>

double A4_CONCERT = 440.0;
int NUM_OF_KEYS = 88;
int KEY_NUM = 12;
char* keys[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};

double get_frequency (double A4, int key_number) {
    double exponent = (((double)key_number - 49) / KEY_NUM);
    return A4 * pow(2.0, exponent);
}

int main() {
    for (int i = 0; i < NUM_OF_KEYS; i++) {
        char* label = keys[i % KEY_NUM];
        printf("%s\t%10.4f\n", label, get_frequency(A4_CONCERT, i+1));
    }
    return 0;
}