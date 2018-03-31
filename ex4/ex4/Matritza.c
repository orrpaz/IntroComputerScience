/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: Exercise 4
******************************************/
#include <stdio.h>
#include "Matritza.h"
#define SIZE_MAT 15
#define SIZE 2

/************************************************************************
* function name: MainMatrix
* The Input: none
* The output: return 0
* The Function operation: the function ask for row and col for array building.
then then the function continue to menuOperation function
*************************************************************************/
int MainMatrix()
{
	int runningFlag = 1;
	int firstMatrix[SIZE_MAT][SIZE_MAT];
	int row, col;

	printf("Welcome to the Matrix calculator\n");

	while (runningFlag)
	{
		do
		{
			printf("Please enter first matrix dimensions (row col):\n");
			scanf("%d %d", &row, &col);
		} while (CheckRowCol(row, col));

		MatrixBuild(firstMatrix, row, col);
		runningFlag = MenuOperation(firstMatrix,row, col);
	}	
	return 0;
}

/************************************************************************
* function name: CheckRowCol
* The Input: row and col type int
* The output: return 1 if row and col not ok else return 0
* The Function operation: the function check if the row or the col
is bigger than 15 or smaller than.if yes, it is print a error and resquet
another row and col.
*************************************************************************/
int CheckRowCol(int row,int col)
{
	int retval = 0;
	if (row <= 0 || row > 15 || col <= 0 || col > 15)
	{
		printf("Error\n");
		retval = 1;
	}
	return retval;
}

/************************************************************************
* function name: MatrixBuild
* The Input: get an array,row and col type int
* The output: none
* The Function operation: the function array and size(row/col) and
built on it a matrix
*************************************************************************/
void MatrixBuild(int Matrix[][SIZE_MAT], int row, int col)
{
	int i, j;
	printf("Please enter matrix elements(%dx%d):\n", row, col);
	// run all over the matrix and get a number
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			scanf("%d", &Matrix[i][j]);
		}
	}
}


/************************************************************************
* function name: SumMatrix
* The Input: array(matrix), row and col type int
* The output: none
* The Function operation: the function get 2 array and build anoter matrix
in order to add it to first matrix and put the result in result matrix.
*************************************************************************/
void SumMatrix(int firMatrix[][SIZE_MAT], int row, int col)
{
	int i, j;
	int secMatrix[SIZE_MAT][SIZE_MAT];
	MatrixBuild(secMatrix, row, col);
	printf("The answer is:\n");
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			firMatrix[i][j] += secMatrix[i][j];
			printf("%4d", firMatrix[i][j]);
		}
		printf("\n");
	}

}

/************************************************************************
* function name: Subtraction
* The Input: array(first matrix), row and col type int
* The output: none
* The Function operation: the function get 2 array and build anoter matrix
in order to subtract from first matrix and put the result in result matrix.
*************************************************************************/
void Subtraction(int firMatrix[][SIZE_MAT], int row, int col)
{
	int i, j;
	int secMatrix[SIZE_MAT][SIZE_MAT];
	MatrixBuild(secMatrix, row, col);
	printf("The answer is:\n");
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			firMatrix[i][j] -= secMatrix[i][j];
			printf("%4d", firMatrix[i][j]);
		}
		printf("\n");
	}

}

/************************************************************************
* function name: MultiMat
* The Input: matrix(array),row and col type int
* The output: int ColMult
* The Function operation: the function ask for new col and second matrix
it runs all over array and calculate the matrix multifacion.
*************************************************************************/
int MultiMat(int firMatrix[][SIZE_MAT], int row, int col)
{
	int colMult, sum = 0;
	int i, j, k;
	int secMatrix[SIZE_MAT][SIZE_MAT], resMatrix[SIZE_MAT][SIZE_MAT];
	// check if col of multifaction isnt biger than 15 or smaller than 0.
	do 
	{
		printf("Please enter column dimension of second matrix:\n");
		scanf("%d", &colMult);
	}
	while (CheckRowCol(row, colMult));
	MatrixBuild(secMatrix, col, colMult);
	printf("The answer is:\n"); 
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < colMult; ++j)
		{
			resMatrix[i][j] = 0;
			//add the multifaction of row from first an col from second to result.
			for (k = 0; k < col; ++k)
			{
				resMatrix[i][j] += firMatrix[i][k] * secMatrix[k][j];
			}
			printf("%4d", resMatrix[i][j]);
		} //end of for
		printf("\n");
	} //end of for
	CopyResultToFirstMat(firMatrix, resMatrix, row, colMult);
	return colMult;
}

/************************************************************************
* function name:  CopyResultToFirstMat
* The Input: two array(matrix),row and col type int
* The output: none
* The Function operation: the function copy the result array to first array
*************************************************************************/
void CopyResultToFirstMat(int firMatrix[][SIZE_MAT], int resMatrix[][SIZE_MAT], int row, int col)
{
	int i, j;
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
			firMatrix[i][j] = resMatrix[i][j];
	}
}

/************************************************************************
* function name: TransposeMat
* The Input:  get matrix(array),row and col type int
* The output: none
* The Function operation: the function run all over the array
and then change place in array according transpose rules.
*************************************************************************/
void TransposeMat(int firMatrix[SIZE_MAT][SIZE_MAT], int row, int col)
{
	int i, j ;
	int resMatrix[SIZE_MAT][SIZE_MAT];
	// run all over the number in matrix
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			// change the position according to the instruction
			resMatrix[j][i] = firMatrix[i][j];

		}
	}
	MatrixPrint(resMatrix, col, row);
	CopyResultToFirstMat(firMatrix,resMatrix, col, row );
}

/************************************************************************
* function name: MatrixPrint
* The Input: get matrix(array),row and col type int
* The output: none
* The Function operation: the function run all over the matrix and print it.
*************************************************************************/
void MatrixPrint(int matrix[][SIZE_MAT], int row, int col)
{
	int i, j;
	printf("The answer is:\n");
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			printf("%4d ", matrix[i][j]);
		}
		printf("\n");
	}
}

/************************************************************************
* function name: menuOperation
* The Input: matrix(array) ,row and col type int
* The output: return retval-to exit from while in MainMatrix function.
* The Function operation: the function get a operaion from user and then
continue with switch-case to other function
*************************************************************************/
int MenuOperation(int matrix[][SIZE_MAT], int row, int col)
{
	int clear = 0, temp, retval = 1;
	char operation;
	while (!clear)
	{
		printf("Please enter operation:(+,-,*,t,c,q)\n");
		scanf(" %c", &operation);		switch (operation)
		{
		case '+':
			SumMatrix(matrix, row, col);
			break;
		case '-':
			Subtraction(matrix, row, col);
			break;
		case '*':
			col = MultiMat(matrix,  row, col);
			break;
		case 't':
			TransposeMat(matrix, row, col);
			/* the row and col has change in Transpose
			therefore we need change between them*/
			temp = row;
			row = col;
			col = temp;
			break;
		case 'q':
			//exit from program and back to menu
			retval = 0;
			clear = 1;
			break;
		case 'c':
			//exit from last while and resquet a new matrix
			clear = 1;
			break;
		default:
			printf("This operation does not exist!\n");
			break;
		}
	} // end of while
	// to exit from while in MainMatrix function
	return retval;
}

