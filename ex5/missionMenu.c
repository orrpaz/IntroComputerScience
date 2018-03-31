/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: Exercise 5
******************************************/

#include "missionMenu.h"
#include "GetInput.h"
#include "Mission1.h"
#include "Mission2And3.h"
#include "Mission5.h"
#include "Mission4.h"
#include "FuncMission6.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/************************************************************************
* function name: Mission1
* The Input: none
* The output: none
* The Function operation: the menu of mission 1 get string from user
  print the string after sort according to condition.
*************************************************************************/
void Mission1()
{
	char *ptr1;
	ptr1 = GetNewSring(1);
	if (isValid(ptr1) == 1)
	{
		if (SortSorting(ptr1) == 1)
		{
			printf("The string after sorting is: %s\n", ptr1);
		}
		else
		{
			printf("The string is already sorted\n");
		}
		free(ptr1);
	}
	
}

/************************************************************************
* function name: Mission2
* The Input: none
* The output: none
* The Function operation: the menu of mission 2 get from user 2 string and print 
how much times the second word build the first word.
*************************************************************************/
void Mission2()
{
	char *ptr1;
	char *ptr2;
	int check;
	Get2Srting(&ptr1, &ptr2);
	check = SubGenerator(ptr1, ptr2);
	if (check == 0)
	{
		printf("No concatenation found\n");
	}
	else
	{
		printf("%s is a concatenation of %s %d times\n", ptr1, ptr2, check);
	}
	free(ptr1);
	free(ptr2);
}

/************************************************************************
* function name: Mission3
* The Input: none
* The output: none
* The Function operation: the menu of mission 3 get string from user 
  and navigate between other function
*************************************************************************/
void Mission3()
{
	char * ptr1;
	int check;
	ptr1 = GetNewSring(3);
	check = ShortestStr(ptr1);
	printRiesha(ptr1, check);
	free(ptr1);
}

/************************************************************************
* function name: Mission4
* The Input: none
* The output: none
* The Function operation: get string from user and number,then it count space in the string.
  if the number is lower than thr num of space in string + 1 , ReverseNumWords do reverse.
*************************************************************************/
void Mission4()
{
	char *ptr1;
	char space = ' ';
	int n, countWords = 0;
	ptr1 = GetNewSring(4);
	printf("Please enter how many words to reverse:\n");
	scanf("%d", &n);
	countWords = CountApearnaceLetter(ptr1, space);
	if (n <= countWords + 1)
	{
		ReverseNumWords(ptr1, n);
		printf("The string after reverse is: %s\n", ptr1);
	}
	else
	{
		printf("Error: Illegal input\n");
		
	}
	free(ptr1);
}

/************************************************************************
* function name: Mission5
* The Input: none
* The output: none
* The Function operation: the menu of mission 5 navigate between other function
*************************************************************************/
void Mission5()
{

	int numOfItem = 0;
	char **ptr;
	ptr = GetInputsAndStore(&numOfItem);
	SortingWords(ptr, numOfItem);
	PrintString(ptr, numOfItem);
	FreeMemory(ptr, numOfItem);
}

/************************************************************************
* function name: Mission6
* The Input: none
* The output: none
* The Function operation: the menu of mission 6 by switch-case
*************************************************************************/
void Mission6()
{
	int option, flag = 1;
	int **queue = NULL;
	int numOfElement = 0;
	PrintMenu();
	while (flag)
	{
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			queue = AddItem(queue, &numOfElement);
			if (queue == NULL)
				return;
			break;
		case 2:
			queue = RemoveItem(queue, &numOfElement);
			if (queue == NULL && numOfElement > 0)
				return;
			break;
		case 3:
			PrintQueue(queue, numOfElement);
			break;
		case 4:
			PrintMax(queue, numOfElement);
			break;
		case 5:
			PrintMin(queue, numOfElement);
			break;
		case 6:
			PrintIndex(queue, numOfElement);
			break;
		case 7:
			queue = ClearQueue(queue, &numOfElement);
			break;
		case 8:
			PrintMenu();
			break;
		case 0:
			flag = 0;
			DestroyQueue(queue, numOfElement);
			break;
		default:
			printf("Error: Unrecognized choice\n");
		}
		if (option != 0)
			printf("Please select your next choice (select 8 for complete menu)\n");
	}
}
