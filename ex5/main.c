/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: Exercise 5
******************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GetInput.h"
#include "missionMenu.h"
#include "FuncMission6.h"


int main()
{
	int choice;
	int runningflag=1;
	while (runningflag)
	{
		printf("Please enter your input:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			Mission1();
			break;
		case 2:
			Mission2();
			break;
		case 3:
			Mission3();
			break;
		case 4:
			Mission4();
			break;
		case 5:
			Mission5();
			break;
		case 6:
			Mission6();
			break;
		case 0:
			runningflag = 0;
			break;
		default:
			printf("Error: Illegal input\n");
			break;
		}
	}
	
	return 0;
}