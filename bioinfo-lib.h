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

/*
    Returns the the number of occurrence of str2 in str1.
*/
int countSubstrPattern(char *str1, char *str2) {
    char substr[strlen(str1)];
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

/*
    Returns 1 if all letters in str1 are in str2, else returns 0;
*/
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

/*
    Returns the number of Gs minus the number of Cs in the first n nucleotides.
*/
int getSkew(char *str1, int n) {
    // check if n is valid. It must be within 1 to strlen of str1.
    if(n <= 0 || n > strlen(str1)) {
        return -999;
    }
    
    int i;
    int skew = 0;
    
    // iterate each element until n
    for(i = 0; i < n; i++) {
        if(str1[i] == 'G') {
            skew++;
        }
        else if(str1[i] == 'C') {
            skew--;
        }
    }
    
    return skew;
}

/*
    Returns the maximum number of Gs minus the number of Cs in the first n nucleotides.
*/
int getMaxSkewN(char *str1, int n) {
    // check if n is valid. It must be within 1 to strlen of str1.
    if(n <= 0 || n > strlen(str1)) {
        return -999;
    }
    
    int i;
    int maxSkew = -99999;
    int currentSkew;
    char substr[strlen(str1)];
    
    for(i = 0; i < n; i++) {
        // get substring from 0 to i
        strcpy(substr, str1);
        substr[i + 1] = '\0';
        
        // get skew of substring
        currentSkew = getSkew(substr, strlen(substr)); 
            
        // check if skew of substring is greater than max skew
        if(currentSkew > maxSkew) {
            maxSkew = currentSkew;
        }
    }
    
    
    return maxSkew;
}

/*
    Returns the minimum number of Gs minus the number of Cs in the first n nucleotides.
*/
int getMinSkewN(char *str1, int n) {
    // check if n is valid. It must be within 1 to strlen of str1.
    if(n <= 0 || n > strlen(str1)) {
        return -999;
    }
    
    int i;
    int minSkew = 99999;
    int currentSkew;
    char substr[strlen(str1)];
    
    for(i = 0; i < n; i++) {
        // get substring from 0 to i
        strcpy(substr, str1);
        substr[i + 1] = '\0';
        
        // get skew of substring
        currentSkew = getSkew(substr, strlen(substr)); 
            
        // check if skew of substring is less than min skew
        if(currentSkew < minSkew) {
            minSkew = currentSkew;
        }
    }
    
    
    return minSkew;
}