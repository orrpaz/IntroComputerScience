/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: Exercise 5
******************************************/

#include "FuncMission6.h"
#include "missionMenu.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



/************************************************************************
* function name: PrintMenu
* The Input: none
* The output: none
* The Function operation: print the menu of mission 6
*************************************************************************/
void PrintMenu()
{
	printf("Please select your choice:	\n");
	printf("0.Exit\n");
	printf("1.Add item to the queue\n");
	printf("2.Remove item from the queue\n");
	printf("3.Print queue\n");
	printf("4.Print the maximum item in the queue\n");
	printf("5.Print the minimum item in the queue\n");
	printf("6.Print index of given item\n");
	printf("7.Clear queue\n");
	printf("8.Print the menu\n");
}




/************************************************************************
* function name: AddItem
* The Input:  array of pointer **queue type int, pointer *numOfElement type int
* The output: return the address of queue
* The Function operation: the function push item to pointer of pointer 
*************************************************************************/
int** AddItem(int **queue, int *numOfElement)
{
	int item;
	int **temp;
	int *pItem;
	printf("Enter item value to add\n");
	scanf("%d", &item);
	// increase the place in queue
	temp = realloc(queue, (*numOfElement + 1) * sizeof(int*));
	if (temp == NULL)
	{
		// if Dynamic allocation was failed.
		printf("Error: Insufficient Memory\n");
		DestroyQueue(queue, *numOfElement);
		return NULL;
	}
	queue = temp;
	pItem = malloc(sizeof(int*));
	if (pItem == NULL)
	{
		// if Dynamic allocation was failed.
		printf("Error: Insufficient Memory\n");
		DestroyQueue(queue, *numOfElement);
		return NULL;
	}
	// pItem point on item
	*pItem = item;
	queue[*numOfElement] = pItem;
	// count the elemnent
	(*numOfElement)++;
	printf("Item %d added\n", item);
	return queue;
}

/************************************************************************
* function name: RemoveItem
* The Input:  array of pointer **queue type int, pointer *numOfElement type int
* The output: return the address of queue
* The Function operation: the function remove item from pointer of pointer
*************************************************************************/
int** RemoveItem(int **queue, int *numOfElement)
{
	int value;
	int **temp;
	if (*numOfElement > 0)
	{
		value = *(queue[0]);
		free(queue[0]);
		// move the queue one plcae to left.
		ShiftLeft(queue, *numOfElement);
		(*numOfElement)--;
		if (*numOfElement > 0)
		{
			temp = realloc(queue, (*numOfElement) * sizeof(int*) );
			if (temp == NULL)
			{
				// if Dynamic allocation was failed.
				printf("Error: Insufficient Memory\n");
				DestroyQueue(queue, *numOfElement);
				return NULL;
			}
			queue = temp;
		} // end of if
		printf("Item %d was removed\n", value);
	}
	else
	{
		printf("Error: Queue is empty!\n");
	}
	return queue;
}

/************************************************************************
* function name: ShiftLeft
* The Input:  array of pointer **queue type int, numOfElement type int
* The output: none
* The Function operation: after remove item,
  the function move each pointer one place to left.
*************************************************************************/
void ShiftLeft(int **queue, int numOfElement)
{
	int i;
	for (i = 0; i < numOfElement - 1; ++i)
	{
		queue[i] = queue[i + 1];
	}
}

/************************************************************************
* function name: PrintQueue
* The Input:  array of pointer **queue type int, numOfElement type int
* The output: none
* The Function operation: the function print the items in queue.
*************************************************************************/
void PrintQueue(int **queue, int numOfElement)
{
	int i;
	if (numOfElement > 0)
	{
		printf("Queue items are: ");
		for (i = 0; i < numOfElement; ++i)
		{
			printf("%d ", *queue[i]);

		}
		printf("\n");
	}
	else
	{
		printf("Error: Queue is empty!\n");
	}
}


/************************************************************************
* function name: PrintMax
* The Input:  array of pointer **queue type int, numOfElement type int
* The output: none
* The Function operation: the function print the item number that is maximum
*************************************************************************/
void PrintMax(int **queue, int numOfElement)
{
	int max = 0;
	int i;
	if (numOfElement >= 1)
	{
		// the first item is maximum
		max = *queue[0];
		for (i = 1; i < numOfElement; ++i)
		{
			// each item was checked if it bigger than max.
			if (max < *queue[i])
			{
				max = *queue[i];
			}
		}
		printf("Maximum item in queue is %d\n", max);
	}
	else
	{
		printf("Error: Queue is empty!\n");
	}
}

/************************************************************************
* function name: PrintMin
* The Input:  array of pointer **queue type int, numOfElement type int
* The output: none
* The Function operation: the function print the item number that is minimum
*************************************************************************/
void PrintMin(int **queue, int numOfElement)
{
	int min = 0;
	int i;
	if (numOfElement >= 1)
	{
		// the first item is minimum
		min = *queue[0];
		for (i = 1; i < numOfElement; ++i)
		{
			// each item was checked if it lower than min.
			if (min > *queue[i])
			{
				min = *queue[i];
			}
		}
		printf("Minimum item in queue is %d\n", min);
	}
	else
	{
		printf("Error: Queue is empty!\n");
	}
}

/************************************************************************
* function name: PrintIndex
* The Input:  array of pointer **queue type int, numOfElement type int
* The output: none
* The Function operation: the function ask number from user. then it search 
  the item in the queue and print it and the location in queue.
*************************************************************************/
void PrintIndex(int **queue, int numOfElement)
{
	int item, i;
	int isAppear = 0;
	if (numOfElement > 0)
	{
		printf("Please enter the item you would like to know its index\n");
		scanf("%d", &item);
		for (i = 0; i < numOfElement; ++i)
		{
			// if the item exist in queue
			if (*queue[i] == item)
			{
				printf("Item %d index is %d\n", item, i+1); 
				isAppear = 1;
			}
		}
		// if the item dont exist
		if (isAppear == 0)
		{
			printf("Error: no such item!\n");
		}
	}
	else
	{
		printf("Error: Queue is empty!\n");
	}
}

/************************************************************************
* function name: ClearQueue
* The Input:  array of pointer **queue type int, numOfElement type int
* The output: none
* The Function operation: the function clear the queue from items
*************************************************************************/
int** ClearQueue(int **queue, int *numOfElement)
{
	
	/*
	int i;
	int **temp;
	for (i = 0; i < *numOfElement; ++i)
	{
		free(queue[i]);
		
	}
	temp = realloc(queue, sizeof(int*));
	if (temp == NULL)
	{
			// if Dynamic allocation was failed.
			printf("Error: Insufficient Memory\n");
			free(queue);
			
			return NULL;
	}
	queue = temp;
	*numOfElement = 0;
	printf("Queue is clear\n");
	return queue;
	*/
	
	DestroyQueue(queue, *numOfElement);
	*numOfElement = 0;
	printf("Queue is clear\n");
	return NULL;
}

/************************************************************************
* function name: DestroyQueue
* The Input:  array of pointer **queue type int, numOfElement type int
* The output: none
* The Function operation: the function free the pointer in queue, 
  and then free the queue itself.
*************************************************************************/
void DestroyQueue(int **queue, int numOfElement)
{
	int i;
	// run all over the queue
	for (i = 0; i < numOfElement; ++i)
	{
		free(queue[i]);
	}
	free(queue);
}