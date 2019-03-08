#include <stdio.h>
#include <stdlib.h>
#include<string.h> 

double Boringness(char *str);   
void swap (float *a, float *b); 
void BubbleSort(char *BoringBuffer[], size_t n);  
 
int main() { 
    char str[256];
    FILE *fp = fopen("word2.txt", "r"); 
    size_t m = 100;    
    char **BoringBuffer;  
    BoringBuffer = malloc( m * sizeof(char *) );
    size_t iterator = 0;
    while (fgets(str, sizeof(str), fp)) { 
        //printf("%s", str); 
        if (str == '\0') break; //Allocate strlen instead of m + 1 
        BoringBuffer[iterator] = malloc( (m + 1) * sizeof(char) );
        strcpy(BoringBuffer[iterator], str);  
        printf("%s", BoringBuffer[iterator]);                                   
        iterator++;     
    }   
 
    BubbleSort(BoringBuffer, iterator);       
    size_t i;       
    for(i = 0; i < iterator; i++) printf("%s\n", BoringBuffer[i]);   
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

void BubbleSort(char *BoringBuffer[], size_t n) {
    size_t i, j;
    char* temp;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if( Boringness(BoringBuffer[j]) < Boringness(BoringBuffer[j + 1]) ) {
                temp = BoringBuffer[j];
                BoringBuffer[j] = BoringBuffer[j + 1];
                BoringBuffer[j + 1] = temp;
            } 
        }  
    } 
    return;
}                            