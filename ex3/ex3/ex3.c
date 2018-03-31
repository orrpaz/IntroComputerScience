/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: Exercise 3
******************************************/

#include <stdio.h>

int CheckMinimum(int firNum, int secNum);
int CheckMaximum(int firNum, int secNum);
void Divider();
void DividerByDiv1OrDiv2(unsigned int div1, unsigned int div2, unsigned int n);
void DividerByDiv1AndDiv2(unsigned int div1, unsigned int div2, unsigned int n);
void Multiplication();
void FibonacciCacluate(int k);
void FibonacciNumber();
void SumDigit();
void TwoMinPositiveNumber();


int main() 
{
	int missionNum;
	int runningFlag = 1;
	
	while (runningFlag)
	{
		printf("Please select the assignment:\n");
		scanf("%d", &missionNum);

		switch (missionNum)
		{
		case 1:
			Multiplication();
			break;
		case 2:
			Divider();
			break;
		case 3 :
			FibonacciNumber();
			break;
		case 4:
			TwoMinPositiveNumber();
			break;
		case 5:
			SumDigit();
			break;
		case 0:
			// exit from the loop
			runningFlag = 0;
			break;
		default:
			printf("NO SUCH ASSIGNMENT!\n");
			break;
		}
	}
	return 0;
}

/************************************************************************
* function name: CheckMinimum
* The Input: get 2 numbers of type int
* The output: return mimimum number type int
* The Function operation:  the function compare the min number to  
  the second number and then check if first smallet than second number
*************************************************************************/
int CheckMinimum(int firNum, int secNum)
{
	int min = secNum;

	if (firNum <= secNum)
	{
		min =  firNum;
	}
	return min;
}

/************************************************************************
* function name: CheckMaximum
* The Input: get 2 numbers of type int
* The output: return the max number type int
* The Function operation:  the function compare the max number to  
  the second number and then check if first smallet than second number
*************************************************************************/
int CheckMaximum(int firNum, int secNum)
{
	int max = secNum;

	if (firNum >= secNum)
	{
		max = firNum;
	}
	return max;
}

/************************************************************************
* function name: Multiplication
* The Input: none
* The output: void
* The Function operation: The function get two number from user, 
 call the CheckMinimum and CheckMaximum in order to cacluate them.then
it passes all row and col ,multiplie them and print the result in suitable place.
*************************************************************************/
void Multiplication()
{
	int firsNum, secNum;
	int row, col;
	printf("Please enter two numbers for the multiplication table: \n");
	scanf("%d %d", &firsNum, &secNum);
	//enter the min number betwwen them to min by CheckMinimum function.
	int min = CheckMinimum(firsNum, secNum);
	//enter the max number betwwen them to max by CheckMaximum function.
	int max = CheckMaximum(firsNum, secNum);
	/*loop that passes all the number and multiplate them with other number
	in relation of row and col*/
	for (row = min; row <= max; ++row)
	{
		for (col = min; col <= max; ++col)
		{
			printf("%-4d", row*col);
		}
		printf("\n");
	}
}

/************************************************************************
* function name: Divider
* The Input: none
* The output: void
* The Function operation: get input from the user in the function 
  checking which key was inserted and 
  'A' or 'o' - the number divide div1 or div2. 
  'A' or 'a' - the number divide div1 and div2 .
  the fuction call to 2 another fuction for the cacluation
*************************************************************************/
void Divider()
{
	unsigned int div1, div2, n;
	char key ;
	printf("Please enter n:\n");
	scanf("%d", &n);
	printf("Please enter two dividers:\n");
	scanf(" %d %d", &div1, &div2);
	printf("Please enter the key:\n");
	scanf(" %c", &key);
	if (key == 'O' || key == 'o')
	{
		DividerByDiv1OrDiv2(div1, div2, n);
	}
	else if (key == 'A' || key == 'a')
	{
		DividerByDiv1AndDiv2(div1, div2, n);
	}
	else
		printf("ERROR IN KEY\n");
}


/************************************************************************
* function name:DividerByDiv1OrDiv2
* The Input: get unsigned int div1,div2 and n
* The output: void
* The Function operation: the function print all number 
  that divide by div1 or div 2.
*************************************************************************/
void DividerByDiv1OrDiv2(unsigned int div1, unsigned int div2, unsigned int n)

{
	unsigned int i;
	for (i = 1; i <= n; ++i)
	{
		/*Checking if the remainder of the division between
		i with div1 or i with div2 is equal to 0*/
		if (i % div1 == 0 || i % div2 == 0)
		{
			printf("%u ", i);
		}
	}
	printf("\n");
}

/************************************************************************
* function name: DividerByDiv1AndDiv2
* The Input: get unsigned int div1,div2 and n
* The output: void
* The Function operation: the function print all number that divide
  by div1 or div 2.
*************************************************************************/
void DividerByDiv1AndDiv2(unsigned int div1, unsigned int div2, unsigned int n)
{
	unsigned int i;

	// loop tne number from 1 until n
	for (i = 1; i <= n; ++i)
	{ 
			/*Checking if the remainder of the division between 
			i with div1 and i with div2 is equal to 0*/
		if (i % div1 == 0 && i % div2 == 0)
		{
			printf("%u ", i);
		}
	}
	printf("\n");
}

/************************************************************************
* function name: FibonacciCacluate
* The Input: get number from FibonacciNumber fuction type int
* The output: void
* The Function operation: the function print the 2 first numbers .
  then the function run from 0 until n-2,print the next number
  by sum of previous number.
*************************************************************************/
void FibonacciCacluate(int n)
{
	int i;
	int fibo1 = 1, fibo2 = fibo1, nextNumber=0;
		printf("%d %d", fibo1, fibo2);
		/*loop that run from 0 to n-2 because we know 
		that the 2 first number equal to 1*/
		for (i = 0; i < n-2; ++i)
		{
			nextNumber = fibo1 + fibo2;
			printf(" %d", nextNumber);
			fibo1 = fibo2;
			fibo2 = nextNumber;
		}
	printf("\n");
}

/************************************************************************
* function name: FibonacciNumber
* The Input: none
* The output: void
* The Function operation: get number from user.if number is 
  bigger than 1 the function go to FibonacciCacluate.
*************************************************************************/
void FibonacciNumber()

{
	int fiboNum;
	printf("Please enter n:\n");
	scanf("%d", &fiboNum);
	if (fiboNum < 1)
	{
		printf("INPUT ERROR\n");
	}
	else if (fiboNum == 1)
	{
		printf("%d\n", fiboNum);
	}
	else 
		FibonacciCacluate(fiboNum);
}

/************************************************************************
* function name: SumDigit
* The Input: none
* The output: void
* The Function operation: get number from user. 
  As long as the number is bigger than 0 the function
  add the last digit to sum and then divide the number in 10 to get a new longNumber
************************************************************************/
void SumDigit()
{
	int sum = 0;
	unsigned long int longNumber;
	printf("Please enter your number:\n");
	scanf("%lu", &longNumber);
	while (longNumber > 0)
	{
		//add the last digit to sum
		sum += longNumber % 10; 
		//divided the number and get new longNumber
		longNumber /= 10;
	}
	printf("%d\n", sum);
	
}

/************************************************************************
* function name: TwoMinPositiveNumber
* The Input: none
* The output: void
* The Function operation: the function gets series numbers from user,
  save the 2 minimal positive number and finally print to screen.
  every number entered, checked in relation to the minimum number
  *************************************************************************/

void TwoMinPositiveNumber()
{
	int min = 0, nextMin = 0, checkNum = 0;
	printf("Please enter your sequence:\n");
	while (checkNum != -1)
	{
		scanf("%d", &checkNum);
		if (checkNum > 0)
		{  
			// checkNum is the most smallest or min equal 0 in first iteration
			if (checkNum < min || min == 0)
			{ 
				nextMin = min;
				min = checkNum;
			}
			/*otherwise, if the number is bigger than the min number 
			but also smaller than nextMin or nextMin is equal 0*/
			else if ( checkNum > min && (checkNum < nextMin || nextMin == 0) )
			{
				nextMin = checkNum;
			}
		}
	}
	printf("%d %d\n", min, nextMin);
}

