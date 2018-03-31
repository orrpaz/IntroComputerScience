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
* function name: GetNewWords
* The Input: none
* The output: return word
* The Function operation: the function get from user word
*************************************************************************/
char* GetNewWords()
{
	char letter;
	int lenOfNewWord = 1;
	char *word = NULL, *ptr = NULL;
	while ((letter = getc(stdin)) != '\n')
	{
		ptr = realloc(word, (lenOfNewWord + 1) * sizeof(char));
		// if it didnt success
		if (ptr == NULL)
		{
			printf("Error:Cannot allocate Memory\n");
			free(word);
			return NULL;
		}
		ptr[lenOfNewWord - 1] = letter;
		lenOfNewWord++;
		word = ptr;
	}
	word[lenOfNewWord - 1] = '\0';
	return word;
}

/************************************************************************
* function name: FreeMemory
* The Input: int numberOfItem, ptr type char**
* The output: none
* The Function operation: the function run all over array of pointer
and free each pointer. then the function free the ptr itself
*************************************************************************/
void FreeMemory(char **ptr, int numberOfItem)
{
	int i;
	// run all over the the array of pointers
	for (i = 0; i < numberOfItem; ++i)
	{
		free(ptr[i]);
	}
	free(ptr);
}
/************************************************************************
* function name: SaveWordToArray
* The Input: arrayWords type char**, word type char*, countword type int*
* The output: return arrayWords
* The Function operation: copy the word into array of pointers.
*************************************************************************/
char** SaveWordToArray(char **arrayWords, char *word, int *countWords)
{
	char **parrayWords = realloc(arrayWords, (*countWords + 1) * sizeof(char*));
	// if it didnt success
	if (parrayWords == NULL)
	{
		printf("Error:Cannot allocate Memory\n");
		FreeMemory(parrayWords, *countWords);
		return NULL;
	}
	arrayWords = parrayWords;
	// copy the word into arrayWords
	arrayWords[*countWords] = word;
	(*countWords)++;
	return arrayWords;
}


/************************************************************************
* function name: GetInputsAndStore
* The Input: numOfItem type int*
* The output: return arrayWords type char**
* The Function operation: get from user words by GetNewWords function, and then copy
the word into the array of words.
*************************************************************************/
char** GetInputsAndStore(int *numOfItem)
{
	char **arrayWords = NULL;
	char *word = NULL;
	int  run = 1;
	int countWords = 0;
	printf("Please enter list of names:\n");
	getc(stdin);
	while (run)
	{
		word = GetNewWords();
		if (word == NULL)
		{
			// free arrayWords
			FreeMemory(arrayWords, countWords);
			return NULL;
		}
		run = strcmp(word, "QUIT");
		if (run != 0)
		{
			// copy to arrayWords
			arrayWords = SaveWordToArray(arrayWords, word, &countWords);
			if (arrayWords == NULL)
			{
				// free arrayWords
				FreeMemory(arrayWords, countWords);
				return NULL;
			}
		}
		else
		{
			free(word);
		}
	}
	*numOfItem = countWords;
	return arrayWords;
}



/************************************************************************
* function name:SwapString
* The Input: x,y type char**
* The output: void
* The Function operation: the function swap between 2 string.
*************************************************************************/
void SwapString(char** x, char** y)
{
	char *tmp = *x;
	*x = *y;
	*y = tmp;
}

/************************************************************************
* function name: SortingWords
* The Input: numOfItem type int and pointer to pointer char **
* The output: none
* The Function operation: the function do bubble sort and compare between 2 string.
if we need swap, it calls to SwapString
*************************************************************************/
void SortingWords(char **ptr, int numOfItem)
{
	int i, j;
	int isSwap = 0;
	for (i = 0; i < numOfItem - 1; ++i)
	{
		isSwap = 0;
		for (j = 0; j < numOfItem - i - 1; ++j)
		{
			if (strcmp(ptr[j], ptr[j + 1]) > 0)
			{
				SwapString(&ptr[j], &ptr[j + 1]);
				isSwap = 1;
			}
		}
		if (isSwap == 0)
		{
			break;
		}
	}
}

/************************************************************************
* function name: PrintString
* The Input: numOfItem type int and pointer to pointer char **
* The output: none
* The Function operation:the function takes action after
the array of pointer is sort. if word appear twice , the function print it once.
*************************************************************************/
void PrintString(char **ptr, int numOfItem)
{
	int i = 0;
	printf("There are %d names:\n", numOfItem);
	printf("%s\n", ptr[i]);
	for (i = 1; i < numOfItem; ++i)
	{
		if (strcmp(ptr[i], ptr[i - 1]) != 0)
			printf("%s\n", ptr[i]);
	}
}