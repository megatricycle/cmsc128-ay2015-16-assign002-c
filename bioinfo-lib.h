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

int countSubstrPattern(char *str1, char *str2) {
    char substr[50];
    int substrCount = 0;
    int strstrIndex;
    
    strcpy(substr, str1);
    
    while(substr[0] != '\0') {        
        // check if str2 can be found at the current letter
        if((strstr(substr, str2)) !=  NULL) {
            substrCount++;
            
            strcpy(substr, strstr(substr, str2) + 1);
        }
        else {
            break;  
        }
    }
    
    return substrCount;
}

int isValidString(char *str1, char *str2) {
    int i;
    char currentLetter[2];
    
    // iterate each element in str1
    for(i = 0; i < strlen(str1); i++) {
        // convert character to string
        currentLetter[0] = str1[i];
        currentLetter[1] = '\0';
        
        // check if current character is within str2
        if(countSubstrPattern(str2, currentLetter) == 0) {
            return 0;
        }
    }
    
    return 1;
}