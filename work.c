#include <stdio.h>
#include <string.h>

//Q93: Check if two strings are anagrams of each other.

/*
Sample Test Cases:
Input 1:
listen
silent
Output 1:
Anagrams

Input 2:
hello
world
Output 2:
Not anagrams

*/

int main(){
    char str1[50], str2[50];
    int count1[256] = {0}, count2[256] = {0};
    int i;

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Count frequency of each character in str1
    for(i = 0; str1[i]; i++){
        count1[(unsigned char)str1[i]]++;
    }

    // Count frequency of each character in str2
    for(i = 0; str2[i]; i++){
        count2[(unsigned char)str2[i]]++;
    }

    // Compare the two frequency arrays
    for(i = 0; i < 256; i++){
        if(count1[i] != count2[i]){
            printf("Not anagrams\n");
            return 0;
        }
    }

    printf("Anagrams\n");
    return 0;
}


//Q94: Find the longest word in a sentence.

/*
Sample Test Cases:
Input 1:
I love programming
Output 1:
programming

*/


int main() {
    char sentence[100];
    char longestWord[50] = "";
    char currentWord[50];
    int maxLength = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence) - 1, stdin);

    // Tokenize the sentence into words
    char *token = strtok(sentence, " \n");
    while (token != NULL) {
        strcpy(currentWord, token);
        int length = strlen(currentWord);
        if (length > maxLength) {
            maxLength = length;
            strcpy(longestWord, currentWord);
        }
        token = strtok(NULL, " \n");
    }

    printf("Longest word: %s\n", longestWord);
    return 0;
}