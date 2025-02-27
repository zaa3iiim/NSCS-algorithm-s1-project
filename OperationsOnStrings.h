#pragma once 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Basic String Functions

int stringLength(const char *str)
{
	int length = 0;
	while (str[length] != '\0')
	{			  // '/0' is the end of the string  and the loop check fo all chars in the str
		length++; // for each char we add 1 to check the next and to get the length
	}
	return length;
}

void stringCopy(char *dest, const char *src)
{
	if (dest == NULL || src == NULL)
	{
		return; // Do nothing if either pointer is NULL
	}
	int i = 0;
	while (src[i] != '\0')
	{ // Copy characters from src to dest
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0'; // Null-terminate the destination string
}

void stringConcat(char *dest, const char *src)
{
	int j = 0, i = 0;
	while (dest[i] != '\0')
	{ // Find the end of the destination string
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j]; // start adding each char to the dest starting from the end of the dest
		i++;
		j++;
	}
	dest[i] = '\0'; // Null-terminate the concatenate string
}

int stringCompare(const char *str1, const char *str2)
{
	int i = 0;
	// Compare characters until one of the strings ends
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return str1[i] - str2[i]; // Return the difference if characters don't match
		}
		i++; // Move to the next character
	}

	// If strings are of different lengths, the first non-matching character will be the null character
	return str1[i] - str2[i]; // If both are equal, return 0; else return the difference in lengths
}

bool isEmpty(char *str)
{
	return str[0] == '\0';
}

void reverseString(char *str)
{
	char k;
	int i, j = stringLength(str);
	for (i = 0; i <= (int)j / 2; i++)
	{
		k = str[i];
		str[i] = str[j - 1 - i];
		str[j - 1 - i] = k;
	}
}
void toUpperCase(char *str)
{
	int i;
	// Loop through each character of the string until the null terminator
	for (i = 0; str[i] != '\0'; i++)
	{
		// If the character is a lowercase letter, convert it to uppercase
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 'a' + 'A'; // this to have the difference between the upper and lowercase according to ASCII
		}
	}
}

void toLowerCase(char *str)
{
	int i;
	// Loop through each character of the string until the null terminator
	for (i = 0; str[i] != '\0'; i++)
	{
		// If the character is an uppercase letter, convert it to lowercase
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] - 'A' + 'a'; // this to have the difference between the upper and lowercase according to ASCII
		}
	}
}

// Intermediate String Functions
bool strisPalindrome(char *str)
{
	int i, len = stringLength(str);

	// Compare original string with reversed string
	for (i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - 1 - i])
		{
			return 0; // Not a palindrome
		}
	}
	return 1; // It's a palindrome
}

void countVowelsConsonants(char *str, int *vowels, int *consonants)
{
	*vowels = 0;
	*consonants = 0;
	int i = 0;
	char ch;
	toLowerCase(str);
	while (str[i] != '\0')
	{
		ch = str[i];
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		{
			(*vowels)++;
		}
		else
		{
			(*consonants)++;
		}
		i++;
	}
}

int findSubstring(const char *str, const char *sub)
{
    int i = 0, k = 0;
    int subLen = stringLength(sub);

    while (str[i] != '\0') 
    {
        
        if (str[i] == sub[k]) 
        {
            k++;
            // If we matched the entire substring
            if (k == subLen) 
                return i - subLen + 1; // Starting index of the substring
        }
        else 
        {
            i -= k; // Backtrack `i` to just after the start of the last match attempt
            k = 0;
        }
        i++;
    }
    return -1; // Substring not found
}

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
void removeWhitespaces(char *str)
{
	int i = 0, j = 0;
	char rev[stringLength(str) + 1];
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			rev[j] = str[i];
			j++;
		}
		i++;
	}
	rev[j] = '\0';
	stringCopy(str, rev);
}
void sortString(char *str)
{
	if (str == NULL)
	{
		return; // Handle null input
	}

	int i, j, length = strlen(str);

	for (i = 0; i < length - 1; i++)
	{
		for (j = 0; j < length - i - 1; j++)
		{
			if (str[j] > str[j + 1])
			{
				swap(&str[j], &str[j + 1]);
			}
		}
	}
}

bool isAnagram(char *str1, char *str2)
{
	int i;
	if (stringLength(str1) != stringLength(str2))
	{
		return false;
	}

	// Sort both strings
	char *copy1 = strdup(str1);
	char *copy2 = strdup(str2);
	sortString(copy1);
	sortString(copy2);
	// Compare the sorted strings
	if (stringCompare(copy1, copy2) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void charFrequency(char *str, int *freq)
{
	*freq = 0;
	int i = 0, j = 0;

	sortString(str); // Sort the string to group identical characters

	// Count frequencies
	while (str[i] != '\0')
	{
		char current = str[i];
		int count = 0;

		// Count consecutive occurrences of the same character
		while (str[i] == current && str[i] != '\0')
		{
			count++;
			i++;
		}

		// Store frequency in the array
		freq[j++] = count;
		printf("'%c': %d\n", current, count); // Print character and its frequency
	}
}
int countWords(char *str)
{
    if (str == NULL || str[0] == '\0')
    {
        return 0;
    }

    int count = 0;
    bool inWord = false;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && !inWord)
        {
            inWord = true;
            count++;
        }
        else if (str[i] == ' ')
        {
            inWord = false;
        }
    }

    return count;
}


void removeDuplicates(char *str)
{
	char i, j = 0, rem[stringLength(str) + 1];
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != str[i + 1])
		{
			rem[j] = str[i];
			j++;
		}
	}
	rem[j] = '\0';
	stringCopy(str, rem);
}

// Advanced String Functions
void compressString(char *str, char *result)
{
	int j = 0, i, count = 1;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == str[i + 1])
		{
			count++;
		}
		else
		{
			j += sprintf(&result[j], "%d", count); // Convert count to a character  according to the ACII
			result[j] = str[i];
			j++;
			count = 1;
		}
	}
	result[j] = '\0';
}

void longestWord(char *str, char *result)
{
	int i = 0, length = 0, max = 0;
	char current[stringLength(str) + 1];
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			current[length] = str[i]; // saving each char of the word
			length++;				  // increasing the length
		}
		else
		{
			if (length > max)
			{
				current[length] = '\0';
				stringCopy(result, current); // taking the longest word
				max = length;
			}
			length = 0; // restarting the length from 1
		}
	}
	// comparing the last word
	if (length > max)
	{
		current[length] = '\0';
		stringCopy(result, current);
	}
}

bool isRotation(char *str1, char *str2)
{
	int len = stringLength(str2);
	if (stringLength(str1) != len)
	{
		return false; // strings does not have the same length will not be reotated
	}
	else
	{

		char double_str2[2 * (len + 1)];
		stringCopy(double_str2, str2);
		stringConcat(double_str2, str2); // double the str2 "str2str2"
		if (findSubstring(double_str2, str1) == -1)
		{
			return false; // if str1 is not found as asubstring than is rotation = false
		}
		else
		{
			return true; // if str1 is found as asubstring than is rotation = true
		}
	}
}

int countChar(char *str, char ch)
{
	int i, count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ch)
		{
			count++;
		}
	}
	return count;
}

void findAndReplace(char *str, char *find, char *replace)
{

	int lenFind = stringLength(find), lenReplace = stringLength(replace),L = stringLength(str);
	int found = 0, i;
	// Ensure `find` is not empty to avoid infinite loop
	if (lenFind == 0)
	{
		return;
	}
	char temp[1000];
	while (found != -1)
	{
		found = findSubstring(str, find);
		// Copy characters before the found substring
		strncpy(temp, str, found - L);
		temp[found - L] = '\0';

		// Append the replacement substring
		stringConcat(temp, replace);

		// Append the rest of the original string after the found substring
		stringConcat(temp, str + found + lenFind);

		// Copy the modified string back to `str`
		stringCopy(str, temp);
	}
}

void longestPalindrome(char *str, char *result)
{
	if (str == NULL || str[0] == '\0')
	{
		result[0] = '\0';
	}
	else
	{

		int i, c = 0, f, k, max = 0, len = 0, j = stringLength(str) - 1;
		for (i = 0; i < j; i++)
		{
			f = i;
			len = 0;
			c = 0;
			for (k = j; k >= f; k--, f++)
			{
				if (str[f] == str[k])
				{
					len++;
				}
				else
				{
					f = i;
					c++;
					k = j - c;
					len = 0;
				}
			}
			if (len > max)
			{
				max = len;
				if (i == 0)
				{
					i--;
				}
				for (f = i + 1, k = 0; f <= i + 2 * max - 1; f++, k++)
				{
					result[k] = str[f];
				}
				result[k] = '\0';
				if (!strisPalindrome(result))
				{
					result[k] = str[f];
					result[k + 1] = '\0';
				}
			}
		}
	}
}

void swapChars(char str[], int pos1, int pos2) {
    // Perform the swap
    char temp = str[pos1];
    str[pos1] = str[pos2];
    str[pos2] = temp;
}

void printPermutations(char *str)
{
	int len = stringLength(str), i = len - 1;
	long k;
	char temp;
	for (k = factorial(len); k > 0; k--){
		printf("%s;", str);
		swapChars(str,i,i-1);
		i -- ;
		if (i == 0)
		{
			i = len - 1;
		}
	}
}

void splitString(char* str, char delimiter, char tokens[][100], int* tokenCount) {
    int i = 0, j = 0, k = 0;

    // Iterate through the string
    while (str[i] != '\0') {
        if (str[i] == delimiter) {
            tokens[k][j] = '\0'; // Null-terminate the current token
            k++; // Move to the next token
            j = 0; // Reset position for the new token
        } else {
            tokens[k][j++] = str[i];
        }
        i++;
    }

    tokens[k][j] = '\0'; // Null-terminate the last token
    *tokenCount = k + 1; // Set the total number of tokens
}
