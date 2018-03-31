/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: Exercise 4
******************************************/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "PigLatin.h"
#define STR_DES 130
#define STR_SRC 52
#define MAX_WORD 18

/************************************************************************
* function name: PigLatin
* The Input: -
* The output: none
* The Function operation: the function get sentence from GetSentence convert 
  to lovwercase with ConvertToLowCase and go on withe other function.
*************************************************************************/
void PigLatin()
{
	char src[STR_SRC];
	char des[STR_DES] = "\0";
	int runningflag = 1;

	while (runningflag)
	{
		GetSentence(src);
		ConvertToLowCase(src);
		Parser(src, des);
		puts(des);
		runningflag = IsContinue();
		des[0] = '\0';
	}
}

/************************************************************************
* function name: Parser
* The Input: 2 array type char
* The output: none
* The Function operation: the function divide the sentnce was got to word
then it go to PigLatinManipulation function.
*************************************************************************/
void Parser(char src[], char des[])
{
	char word[MAX_WORD];
	char *token;
	const char s[2] = " ";
    // devide the string to words.
	token = strtok(src, s);

	while (token != NULL)
	{
		strcpy(word, token);
		token = strtok(NULL, s);
		PigLatinManipulation(word, des);
	}
}

/************************************************************************
* function name: GetSentence
* The Input: array src type char
* The output: none
* The Function operation: the function get from the user sentnce.
*************************************************************************/
void GetSentence(char src[])
{
	int srcLen = 0;
	printf("Please enter a sentence in English:\n");
	fgets(src, STR_SRC, stdin);
	//subtract the \0 from the sentence. 
	srcLen = strlen(src);
	src[srcLen - 1] = '\0';
}


/************************************************************************
* function name: IsContinue
* The Input: -
* The output: return 1 for continue and 0 for end
* The Function operation: the function check witch char enter.
  'y' for continue, 'n' for end.
*************************************************************************/
int IsContinue()
{
	int retval = 0;
	char letter, dummy;
	printf("Do you want to translate another sentence?(y/n)\n");
	scanf(" %c", &letter);
	scanf("%c", &dummy);
	if (letter == 'y')
	{
		// continue and ask new sentnce
		retval = 1;
		return retval;
	}
	else
		return 0;
		
}

/************************************************************************
* function name: IsLowel
* The Input: first letter type char from PigLatinManipulation function
* The output: return 1 for continue to
  LowelOperation function by PigLatinManipulation function
* The Function operation: the function check if the first word is a,e,o,i,u.
  yes- go to LowelOperation function
  no- go to ConsonantsOperation function
*************************************************************************/
int IsLowel(char firstLetter)
{
	int retval = 0;
	if (firstLetter == 'a' || firstLetter == 'e' || firstLetter == 'i' || firstLetter == 'o'
		|| firstLetter == 'u')
	{
		
		retval = 1;
	}
	return retval;
}


/************************************************************************
* function name: PigLatinManipulation
* The Input: 2 array- word and destntion type char
* The output: none
* The Function operation: the function navigate to other function according
to instruction.
*************************************************************************/
void PigLatinManipulation(char word[], char des[])
{
	char firstLetter = word[0];
	//check if the first letter is a,e,i,o,u
	if (IsLowel(word[0]) == 1)
	{
		LowelOperation(word, des);
	}
	// the first letter isnt a,e,o,u,i
	else
	{
		ConsonantsOperation(word, des);
	}
}


/************************************************************************
* function name: ConvertToLowCase
* The Input: array type char
* The output: none
* The Function operation: the function get the array from other function
and add 32 in ASCII for each letter if it needed.
*************************************************************************/
void ConvertToLowCase(char array[])
{
	int i = 0;
	while (array[i] != '\0')
	{
		// in ASCII table
		if (array[i] >= 'A' && array[i] <= 'Z')
			array[i] += 32;
		++i;
	}
}


/************************************************************************
* function name: ConsonantsOperation
* The Input: 2 array- word and destntion type char
* The output: -
* The Function operation: the function find the first a,e,o,i,u .
copy form it until the end of word to temp array.Then the function
add the rest to temp array with 'ay' in the end.
*************************************************************************/
void ConsonantsOperation(char word[], char des[])
{
	int index = 0, i, j;
	char array[MAX_WORD] = "";
	while (word[index] != '\0')
	{ //search the first a,e,o,i,u,y
		if (IsLowel(word[index]) == 1 || word[index] == 'y')
		{
			for (i = index, j = 0; word[i] != '\0'; ++i, ++j)
			{
				// copy from a,e,i,o,u,y until the end of word to array
				array[j] = word[i];
			}
			// to save the index ,because i dont want it continue.
			break;
		}
		++index;
	}
	// copy the rest of letter to array.
	strncat(array, word, index);
	strcat(array, "ay ");
	strcat(des, array);
}

/************************************************************************
* function name: LowelOperation
* The Input: 2 array- word and destntion type char
* The output: none
* The Function operation: add 'way' to the end of word
*************************************************************************/
void LowelOperation(char word[], char des[])
{
	// add 'way' to word that start with a,e,i,o,u
	strcat(des, word);
	strcat(des, "way ");
}

