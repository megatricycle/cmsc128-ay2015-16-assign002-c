#include<string.h>

/*
    Returns the the number of characters that differ in ith position from position 1 to strlen(str1).
    
    Returns -1 on different length error.
*/
int getHammingDistance(char *str1, char *str2) {
    int distance = 0;
    int i;
    
    // check if same length
    if(strlen(str1) != strlen(str2)) {
        return -1;
    }
    
    // check each element if not equal
    for(i = 0; i < strlen(str1); i++) {
        // increment distance when not equal
        if(str1[i] != str2[i]) {
            distance++;
        }
    }
    
    return distance;
}

