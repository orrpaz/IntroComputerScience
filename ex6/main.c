/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: Exercise 6
******************************************/

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "GADT.h"
#define MAXSTR 16
#define MAXPOINT 6

struct point
{
	int x;
	int y;
};

typedef struct point point;

void MenuOpration(HEAD sll, int option);
ELM CreatePoint(); 
ELM CreateString();
int CmpPoint(ELM val1, ELM val2);
int CmpString(ELM str1, ELM str2);
void CpyPoint(ELM dest, ELM src);
void CpyChar(ELM dest, ELM src);
ELM AddPoint(ELM val1, ELM val2);
ELM AddString(ELM str1, ELM str2);
void PrintPoint(ELM val);
void PrintChar(ELM str);
void FreePoint(ELM val);
void FreeString(ELM str);
//void GetPointOrSring(char* buffer, point* point, int option);
void GetString(char* buffer);
void GetPoint(point* point);
void CheckResult(RESULT result);



int main() {
	int option;
	point point;
	HEAD sll;
	char buffer[MAXSTR];
	scanf("%d", &option);
	switch (option)
	{
		// string
	case 0:
		//GetPointOrSring(buffer, &point, 0);
		GetString(buffer);
		sll = SLCreate(buffer, CreateString, CpyChar, CmpString, FreeString, PrintChar, AddString);
		MenuOpration(sll, option);
		break;
		// point
	case 1:
		//GetPointOrSring(buffer, &point, 1);
		GetPoint(&point);
		sll = SLCreate(&point, CreatePoint, CpyPoint, CmpPoint, FreePoint, PrintPoint, AddPoint);
		MenuOpration(sll, option);
		break;
	default:
		printf("Please enter 0 or 1\n");
		break;
	}
	return 0;
}

/************************************************************************
* function name: MenuOpration
* The Input: option type int ,sll type HEAD
* The output: none
* The Function operation: the function go to suitable mission 
  according to letter was entered. 'e' to exit from program
*************************************************************************/
void MenuOpration(HEAD sll, int option)
{
	char opertion;
	ELM data = NULL;
	point point,point2;
	char dummy;
	RESULT result;
	int runningflag = 1;
	char buffer[MAXSTR], buffer1[MAXSTR];
	while (runningflag)
	{
		scanf("%c", &dummy); 
		scanf("%c",&opertion);
		switch (opertion)
		{
		case 'a':
			if (option == 0)
			{
				GetString(buffer);
				SLAddListElement(&sll, buffer);
			}
			else
			{
				GetPoint(&point);
				SLAddListElement(&sll, &point);
			}
			break;
		case 's':
			if (option == 0)
			{
				GetString(buffer);
				data = SLFindElement(sll, buffer);
			}
			else
			{
				GetPoint(&point);
				data = SLFindElement(sll, &point);
			}
			if (data == NULL)
			{
				printf("FALSE\n");
			}
			else
				printf("TRUE\n");
			break;
		case 'd':
			if (option == 0)
			{
				GetString(buffer);
				result=SLRemoveElement(&sll, buffer);
				CheckResult(result);
			}
			else
			{
				GetPoint(&point);
				result=SLRemoveElement(&sll, &point);
				CheckResult(result);
			}
			// exit from program, the list is empty.
			if (sll == NULL)
			{
				runningflag = 0;
			}
			break;
		case 'p':
			PrintSll(sll);
			break;
		case 'l':
			PrintSize(sll);
			break;
		case 't':
			if (option == 0)
			{
				GetString(buffer);
				scanf("%c", &dummy);
				GetString(buffer1);
				SLAddToElement(&sll, buffer, buffer1);
			}
			else
			{
				GetPoint(&point);
				GetPoint(&point2);
				SLAddToElement(&sll, &point, &point2);
			}
			break;
		case 'e':
			SLDestroy(sll);
			runningflag = 0;
			break;
		default:
			printf("Please enter letter\n");
			break;
		}
	}
}

/************************************************************************
* function name: CreatePoint
* The Input: none
* The output: return ELM( void*)
* The Function operation: allocated memory type sizeof point
*************************************************************************/
ELM CreatePoint()
{
	point *t = (point*)malloc(sizeof(point));
	return (ELM)t;
}

/************************************************************************
* function name: CreateString
* The Input: none
* The output: return ELM( void*)
* The Function operation: allocated memory
*************************************************************************/
ELM CreateString()
{
	char *t = (char*)malloc(16*sizeof(char));
	return (ELM)t;
}

/************************************************************************
* function name: CmpPoint
* The Input: 2 point
* The output: return subtraction between distance of 2 point
* The Function operation: calculate the distance between x and y of point by abs.
*************************************************************************/
int CmpPoint(ELM val1, ELM val2)
{
	point *elm1 = (point*)val1;
	point *elm2 = (point*)val2;
	int d1 = abs(elm1->x) + abs(elm1->y);
	int d2 = abs(elm2->x) + abs(elm2->y);
	return d1 - d2;
}

/************************************************************************
* function name: CmpString
* The Input: 2 string type ELM
* The output: return > 0 if str1 is bigger , < 0 if str2 is bigger 
  , 0 if equal
* The Function operation: check which string is bigger by strcmp
*************************************************************************/
int CmpString(ELM str1, ELM str2)
{
	char* s1 = (char*)str1;
	char* s2 = (char*)str2;
	return strcmp(s1, s2);
}

/************************************************************************
* function name: CpyPoint
* The Input: src, dest type ELM
* The output: void
* The Function operation: copy the value of point to other point.
*************************************************************************/
void CpyPoint(ELM dest , ELM src)
{
	point *elm1 = (point*)src;
	point *elm2 = (point*)dest;
	elm2->x = elm1->x;
	elm2->y = elm1->y;
}

/************************************************************************
* function name: CpyChar
* The Input: src, dest type ELM
* The output: void
* The Function operation: copy the value elm2 to elm1
*************************************************************************/
void CpyChar(ELM dest, ELM src)
{
	char* elm1 = (char*)dest;
	char* elm2 = (char*)src;
	strcpy(elm1, elm2);
}

/************************************************************************
* function name: AddPoint
* The Input: 2 value type ELM	
* The output: return elm1 type point
* The Function operation: the fubction add point2 to point1.
*************************************************************************/
ELM AddPoint(ELM val1, ELM val2)
{
	point* elm1 = (point*)val1;
	point * elm2 = (point*)val2;
	elm1->x += elm2->x;
	elm1->y += elm2->y;
	return elm1;
}

/************************************************************************
* function name: AddString
* The Input: 2 string type ELM
* The output: return str1 type ELM
* The Function operation: connect str2 to str1
*************************************************************************/
ELM AddString(ELM str1, ELM str2)
{
	strcat(str1, str2);
	return str1;
}

/************************************************************************
* function name: PrintPoint
* The Input: val type ELM
* The output: None
* The Function operation: print point.
*************************************************************************/
void PrintPoint(ELM val)
{
	
	printf("%.3d|%.3d\n",((point*)val)->x, ((point*)val)->y);
}

/************************************************************************
* function name: PrintChar
* The Input: str type ELM
* The output: none
* The Function operation: the function print the string
*************************************************************************/
void PrintChar(ELM str)
{
	char* s = (char*)str;
	puts(s);
}

/************************************************************************
* function name: FreeString
* The Input: str type ELM
* The output: none
* The Function operation: free string
*************************************************************************/
void FreeString(ELM str)
{
	free((char*)str);
}

/************************************************************************
* function name: FreePoint
* The Input: val type ELM
* The output: none
* The Function operation: free point
*************************************************************************/
void FreePoint(ELM val)
{
	free((point*)val);
}

/************************************************************************
* function name: GetPoint
* The Input: point type point*
* The output: none
* The Function operation: the function scan from user point.
*************************************************************************/
void GetPoint(point* point)
{
	char dummy;
	scanf("%c", &dummy);
	scanf("(%d,%d)", &(point->x), &(point->y));
}

/************************************************************************
* function name: GetString
* The Input: buffer type char*
* The output: none
* The Function operation: the function scan from user string.
*************************************************************************/
void GetString(char* buffer)
{
	scanf("%s", buffer);
}

/************************************************************************
* function name: CheckResult
* The Input: result type RESULT(enum) 
* The output: none
* The Function operation: the function check the result. is 'badArgs' print
  'FALSE'.
*************************************************************************/
void CheckResult(RESULT result)
{
	if (result == badArgs)
	{
		printf("FALSE\n");
	}
}
/*
void GetPointOrSring(char* buffer, point* point ,int option)
{
	char dummy;
	if (option == 0)
	{
		scanf("%s", buffer);
	}
	else
	{
		scanf("%c", &dummy);
		scanf("(%d,%d)",&(point->x),&(point->y));
	}
	
}
*/
