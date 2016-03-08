#include<stdio.h>
#include<string.h>
#include "bioinfo-lib.h"

void getHammingDistanceTest(char *str1, char *str2, int expectedResult) {
    int hammingDistance = getHammingDistance(str1, str2);
     
    printf("getHammingDistance(\"%s\", \"%s\") ", str1, str2);
    
    if(hammingDistance == expectedResult) {
        printf("PASSED\n");
    }
    else {
        printf("FAILED (Expected %i, got %i.)\n", expectedResult, hammingDistance);
    }
}

void countSubstrPatternTest(char *str1, char *str2, int expectedResult) {
    int substrCount = countSubstrPattern(str1, str2);
     
    printf("countSubstrPattern(\"%s\", \"%s\") ", str1, str2);
    
    if(substrCount == expectedResult) {
        printf("PASSED\n");
    }
    else {
        printf("FAILED (Expected %i, got %i.)\n", expectedResult, substrCount);
    }
}

int main() {
    printf("\n");
    
    // test hamming distance
    char str1[50];
    char str2[50];
    
    strcpy(str1, "AACCTT");
    strcpy(str2, "GGCCTT");
    
    getHammingDistanceTest(str1, str2, 2);
    
    strcpy(str1, "TCGGA");
    strcpy(str2, "AAAAG");
    
    getHammingDistanceTest(str1, str2, 5);
    
    strcpy(str1, "A");
    strcpy(str2, "AG");
    
    getHammingDistanceTest(str1, str2, -1);
    
    // test countSubstrPattern
    strcpy(str1, "AATATATAGG");
    strcpy(str2, "GG");
    
    countSubstrPatternTest(str1, str2, 1);
    
    strcpy(str1, "AATATATAGG");
    strcpy(str2, "ATA");
    
    countSubstrPatternTest(str1, str2, 3);
    
    strcpy(str1, "AATATATAGG");
    strcpy(str2, "ACTGACTGACTG");
    
    countSubstrPatternTest(str1, str2, 0);
    
    printf("\n");
    
    return 0;
}