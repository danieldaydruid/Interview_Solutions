#include <stdio.h>

double Boringness(char * str);
void swap (float *a, float *b);
void BubbleSort(char *BoringBuffer[], int n);

int main() {
    size_t m = 5;
    char *BoringBuffer[5] = {"the", "a", "okay", "farts", "ten"};
    BubbleSort(BoringBuffer, m);
    return 0;
}

double Boringness(char *str) {
    double freq[] = {0.08167, 0.1492, 0.2782, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094,
                    0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749, 0.07507, 0.01929,
                    0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150,
                    0.01974, 0.00074};
    double boringness = 1.0;
    size_t i = 0;
    while (str[i] != '\n' && str[i] != '\0') { 
        boringness = boringness * freq[str[i] - 97];
        i++; // I'm guessing?
    }
    return boringness;
}

void BubbleSort(char *BoringBuffer[], int n) {
    int i, j;
    char* temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if( Boringness(BoringBuffer[j]) > Boringness(BoringBuffer[j + 1]) ) {
                printf("\n\n\nFound\n\n\n");
                temp = BoringBuffer[j];
                BoringBuffer[j] = BoringBuffer[j + 1];
                BoringBuffer[j + 1] = temp;
            }
        }
    }
    return;
}