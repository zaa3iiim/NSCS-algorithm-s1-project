#ifndef STRING_OPERATIONS_H
#define STRING_OPERATIONS_H

#include <stdbool.h>
#include <ctype.h>

/* Basic String Operations */
int stringLength(char* str);
void stringCopy(char* dest, const char* src);  
void stringConcat(char* dest, const char* src);
int stringCompare(const char* str1, const char* str2);
bool isEmpty(char* str);
void reverseString(char* str);
void toUpperCase(char* str);
void toLowerCase(char* str);

/* Intermediate String Operations */
bool isPalindromeStr(char* str);  // Renamed to avoid conflict with numeric version
void countVowelsConsonants(char* str, int* vowels, int* consonants);
int findSubstring(const char* str, const char* sub);
void removeWhitespaces(char* str);
bool isAnagram(char* str1, char* str2);
void charFrequency(char* str, int* freq);
int countWords(char* str);
void removeDuplicates(char* str);

/* Advanced String Operations */
void compressString(char* str, char* result);
void longestWord(char* str, char* result);
bool isRotation(char* str1, char* str2);
int countChar(char* str, char ch);
void findAndReplace(char* str, char* find, char* replace);
void longestPalindrome(char* str, char* result);
void printPermutations(char* str);
void splitString(char* str, char delimiter, char tokens[][100], int* tokenCount);
#endif
