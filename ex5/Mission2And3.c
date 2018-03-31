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
* function name: SubGenerator
* The Input: char *str, char *sub
* The output: return the number of times that second srting build the first
string.
* The Function operation: the function compare each letter on word
with letter on the second word, count how much second word build the first word
until we reach to the end of first word
*************************************************************************/
int SubGenerator(char *str, char *sub)
{
	// point on the first letter
	char *pstr = str;
	char *psub = sub;
	int counter = 0;
	if (str != NULL && sub != NULL)
	{
		while (*pstr != '\0')
		{  // if the letter dont equal.
			if (*pstr != *psub)
			{
				counter = 0;
				break;
			}
			// continue to the next letter
			pstr++;
			psub++;
			// end of 1 time.
			if (*psub == '\0')
			{
				// psub retun to begin of string
				psub = sub;
				counter++;
			}
		}
	}
	if (psub == sub)
		return counter;
	else
		return 0;
}

/************************************************************************
* function name: ShortestStr
* The Input: char *str
* The output: return the length of the shortest first part that builds the string
* The Function operation: the function use SubGenerator that return the number of time
that second srting build the first string.
then it return the length of shortest first part
*************************************************************************/
int ShortestStr(char *str)
{
	char temp;
	int check = 0, i = 0, len;
	char *sub;
	if (str != NULL)
	{
		//length of the string
		len = strlen(str);
		sub = (char*)malloc((len + 1) * sizeof(char));
		// if it didnt success
		if (sub == NULL)
		{
			printf("Error:Cannot allocate Memory\n");
			return 0;
		}
		strcpy(sub, str);
		// run in loop until the end of word.
		for (i = 0; i < len; i++)
		{
			temp = *(sub + i + 1);
			*(sub + i + 1) = '\0';
			check = SubGenerator(str, sub);
			*(sub + i + 1) = temp;
			if (check > 0)
			{
				break;
			}
		}
		free(sub);
	}
	return i + 1;
}

/************************************************************************
* function name: printRiesha
* The Input: char *str, int len-number of time that shortest prefix build
the string .
* The output: none
* The Function operation: the function print the shortest prefix that build
the string
*************************************************************************/
void printRiesha(char *str, int len)
{
	char temp;
	temp = str[len];
	// divide the word by '\0'.
	str[len] = '\0';
	printf("The shortest prefix building the string is: %s of length %d\n", str, len);
	str[len] = temp;
}