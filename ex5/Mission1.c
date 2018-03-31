/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: Exercise 5
******************************************/


#include "GetInput.h"
#include "Mission1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



/************************************************************************
* function name: SortSorting
* The Input: pointer str (string) type char *
* The output: return 0 or 1. 0 if the string is already sort and 1
if the function sort the string
* The Function operation: the function run in loop on string and check
between 2 letter if we need swap.
*************************************************************************/
int SortSorting(char *str)
{
	int i, j;
	int isSwap = 0;
	if (str != NULL)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			for (j = 0; str[i + j + 1] != '\0'; j++)
			{
				// the function return 1 if it need swap.
				if (compere(str[j], str[j + 1]) == 1)
				{
					SwapChar(&str[j], &str[j + 1]);
					isSwap = 1;
				}
			} // end of for
		} // end of for
	} // end of if
	return isSwap;
}

/************************************************************************
* function name: compere
* The Input: firstItem, secItem type char
* The output: return retval - 0 or 1.
0- when we dont need swap
1- when we need swap
* The Function operation: the function check between to letter in string
who is lowercase or who is bigger than the other
*************************************************************************/
int compere(char firstItem, char secItem)
{
	int retval = 0;
	// the first letter is lowercase and the second is uppercase
	if (isLower(firstItem) && !isLower(secItem))
	{
		retval = 0;
	}
	// the first letter is uppercase and the second is lowercase
	else if (!isLower(firstItem) && isLower(secItem))
	{
		retval = 1;
	}
	else
	{
		// the first letter is bigger than second letter
		if (firstItem > secItem)
		{
			retval = 1;
		}
	}
	return retval;
}

/************************************************************************
* function name: isValid
* The Input: pointer ptr (string) type char *
* The output: return 0 or 1. 0 if the user enter illegal input,
and 1 if its ok.
* The Function operation: the function check if the letter in string is
between a-z or A-Z
*************************************************************************/
int isValid(char *ptr)
{
	int i;
	for (i = 0; ptr[i] != '\0'; ++i)
	{
		if ((ptr[i] >= 'a' && ptr[i] <= 'z') || (ptr[i] >= 'A' && ptr[i] <= 'Z'))
		{
			continue;
		}
		else
		{
			printf("Error: Illegal input\n");
			return 0;
		}
	}
	return 1;
}



/************************************************************************
* function name: isLower
* The Input: letter type char
* The output: return 0 or 1
* The Function operation: check if the letter is betwwen a-z
1- yes (true)
0- no (false)
*************************************************************************/
int isLower(char letter)
{
	return (letter >= 'a' && letter <= 'z');
}

/************************************************************************
* function name: SwapChar
* The Input: x,y type char*
* The output: none
* The Function operation: the function swap between 2 letter
*************************************************************************/
void SwapChar(char* x, char* y)
{
	char tmp = *x;
	*x = *y;
	*y = tmp;
}
