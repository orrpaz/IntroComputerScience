/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: Exercise 5
******************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Mission2And3.h"
#include "GetInput.h"


/************************************************************************
* function name: ReverseWord
* The Input: 2 pointer type char *
* The output: none
* The Function operation:  the function use SwapChar to replace between letter
then it increase the first pointer and decrease the second pointer.
*************************************************************************/
void ReverseWord(char *begin, char *end)
{
	while (begin < end)
	{
		SwapChar(begin, end);
		begin++;
		end--;
	}
}

/************************************************************************
* function name: CountApearnaceLetter
* The Input: str type char* and letter type char
* The output: return number how much the letter appears in word
* The Function operation: the function run until the end of word and
count how much the letter appears.
*************************************************************************/
int CountApearnaceLetter(char *str, char letter)
{
	int i = 0;
	int counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == letter)
			counter++;
		i++;
	}
	return counter;
}

/************************************************************************
* function name: ReverseNumWords
* The Input: int n, string type char*
* The output: none
* The Function operation: the function swap the letter from each word.
then it reverse letter in the range of n first word.
*************************************************************************/
void ReverseNumWords(char *str, int n)
{
	// help from geeksforgeeks.com
	char *pword = NULL, *ptr = str;
	int i = 0;
	if (str != NULL)
	{
		while (n > 0)
		{
			// make sure that string begin with valid char and not space.
			if (pword == NULL && *ptr != ' ')
			{
				pword = ptr;
			}
			// search the end of the word
			if ((*(ptr + 1) == ' ' || *(ptr + 1) == '\0') && pword != NULL)
			{
				// reverse per word.
				ReverseWord(pword, ptr);
				pword = NULL;
				n--;
			}
			ptr++;
		}
		// reverse the n first place.
		ReverseWord(str, ptr - 1);
	}
}