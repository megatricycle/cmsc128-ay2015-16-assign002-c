#include<stdio.h>
#include<string.h>
#include "bioinfo-lib.h"

int errorCount = 0;

void getHammingDistanceTest(char *str1, char *str2, int expectedResult) {
    int hammingDistance = getHammingDistance(str1, str2);
     
    printf("getHammingDistance(\"%s\", \"%s\") ", str1, str2);
    
    if(hammingDistance == expectedResult) {
        printf("PASSED\n");
    }
    else {
        printf("FAILED (Expected %i, got %i.)\n", expectedResult, hammingDistance);
        errorCount++;
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
        errorCount++;
    }
}

void isValidStringTest(char *str1, char *str2, int expectedResult) {
    int result = isValidString(str1, str2);
     
    printf("isValidString(\"%s\", \"%s\") ", str1, str2);
    
    if(result == expectedResult) {
        printf("PASSED\n");
    }
    else {
        printf("FAILED (Expected %i, got %i.)\n", expectedResult, result);
        errorCount++;
    }
}

void getSkewTest(char *str1, int n, int expectedResult) {
    int result = getSkew(str1, n);
     
    printf("getSkew(\"%s\", %i) ", str1, n);
    
    if(result == expectedResult) {
        printf("PASSED\n");
    }
    else {
        printf("FAILED (Expected %i, got %i.)\n", expectedResult, result);
        errorCount++;
    }
}

int main() {
    printf("\n");
    
    // test hamming distance
    getHammingDistanceTest("AACCTT", "GGCCTT", 2);
    getHammingDistanceTest("TCGGA", "AAAAG", 5);
    getHammingDistanceTest("A", "AG", -1);
    
    // test countSubstrPattern
    countSubstrPatternTest("AATATATAGG", "GG", 1);
    countSubstrPatternTest("AATATATAGG", "ATA", 3);
    countSubstrPatternTest("AATATATAGG", "ACTGACTGACTG", 0);
    
    // test isValidString
    
    isValidStringTest("AAGGCTATGC", "ACGT", 1);
    isValidStringTest("AAGGCTATGa", "ACGT", 0);
    isValidStringTest("ACGT", "ACGT", 1);
    isValidStringTest("ACGT101_", "ACGT", 0);
    isValidStringTest("091212345", "0123456789", 1);
    
    // test getSkew
    getSkewTest("GGCCAC", 1, 1);
    getSkewTest("GGCCAC", 2, 2);    
    getSkewTest("GGCCAC", 3, 1);    
    getSkewTest("GGCCAC", 4, 0);    
    getSkewTest("GGCCAC", 5, 0);
    getSkewTest("GGCCAC", -5, -999);
    getSkewTest("GGCCAC", 10, -999);
    
    printf("\n");
    
    printf("Total errors: %i\n\n", errorCount);
    
    return 0;
}