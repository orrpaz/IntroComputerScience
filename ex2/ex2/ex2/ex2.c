/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: ex2
******************************************/

#include <stdio.h>
#include <math.h>

int main()
{
	
	int missionNum ;
	int grade;
	int  num1, num2, num3;
	float average;
	int maxNum = 0, minNum = 0;
	char letter1, letter2, letter3;
	double exam1, homework1, exam2, homework2;
	double finalGrade1, finalGrade2;
	char LetterName1, LetterName2;


	printf("Please enter your input:\n");
	scanf("%d", &missionNum);


	switch (missionNum)
	{
		/*recieving of score and ranking A-F by if condition*/
	case 1:
	{
		printf("Please enter your score:\n");
		scanf("%d", &grade);
		if (grade >= 90 && grade <= 100)
			printf("The rank for %d is: A\n", grade);
		else if (grade >= 80 && grade <= 89)
			printf("The rank for %d is: B\n", grade);
		else if (grade >= 70 && grade <= 79)
			printf("The rank for %d is: C\n", grade);
		else if (grade >= 60 && grade <= 69)
			printf("The rank for %d is: D\n", grade);
		else if (grade < 60 && grade >= 0)
			printf("The rank for %d is: E\n", grade);
		/* if the grade bigger than 100 or lower than o*/
		else
			printf("Error");

		break;
	}
	/*input 3 nembers and output the maximum,minimum and average*/
	case 2:
	{
		printf("Please enter three numbers:\n");
		scanf("%d %d %d", &num1, &num2, &num3);

		/*first option:
		if num1 is the maximum,check between the other the minimum*/
		if (num1 >= num3 && num1 >= num2)
		{
			maxNum = num1;
			if (num3 <= num2)
			{
				minNum = num3;
			}
			else
			{
				minNum = num2;
			}
		}
		/*second option:
		if num3 is the maximum,check between the other the minimum*/
		else if (num3 >= num2)
		{
			maxNum = num3;
			if (num2 >= num1)
			{
				minNum = num1;
			}
			else
			{
				minNum = num2;
			}
		}
		/*third option:
		otherwise num2 is maximum,check between the other the minimum*/
		else
		{
			maxNum = num2;
			if (num3 >= num1)
			{
				minNum = num1;
			}
			else
			{
				minNum = num3;
			}
		}

		/*Calculation of average by casting to float*/
			average = (float)(num1 + num2 + num3) / 3;
		/* output of maximum, minimum and average */
		printf("The minimal value is: %d\n", minNum);
		printf("The maximal value is: %d \n", maxNum);
		printf("The average is: %.2f\n", average);
		break;
	}
	/*recieving of 3 letter and presented in a different way*/
	case 3:
	{
		printf("Please enter three chars:\n");
		scanf(" %c %c %c", &letter1, &letter2, &letter3);
		printf("%c\n", letter1);
		printf("%c\n", letter1);
		printf("%c\n", letter2);
		printf("%c\n", letter3);
		printf("%c@%c@%c\n", letter1, letter2, letter3);
		printf("%c\n", letter3);
		printf("%c#%c#%c\n", letter3, letter2, letter1);
		break;
	}
	/*recieving of 2 grade from 2 student
	 calculate the final grade and print it*/
	case 4:
	{
		printf("Please enter two course details:\n");
		scanf("%lf %lf %c", &exam1, &homework1, &LetterName1);
		scanf("%lf %lf %c", &exam2, &homework2, &LetterName2);
		/* calculation of final grade, sqrt return (type) double  */
		finalGrade1 = (8 * sqrt(exam1) + homework1*0.1);
		finalGrade2 = (8 * sqrt(exam2) + homework2*0.1);


		/*check if there is value over 100 and under 0*/
		if (exam1 > 100 || exam1 < 0 || exam2 > 100 || exam2 < 0 
			|| homework1 > 100 || homework1 < 0 || homework2 > 100 || homework2 < 0)
		{
			/* if the exam or homework don't in the range */
			printf("Error\n");
		}
		else
		{
			/* output of final grade */
			printf("The final grade of %c is: %.2f\n", LetterName1, finalGrade1);
			printf("The final grade of %c is: %.2f\n", LetterName2, finalGrade2);
		}

		break;
	}
	case 0:
		break;
	default:
		printf("please enter number 1-4\n");
		break;
		/*ended of switch*/
	}
	return 0;
}
