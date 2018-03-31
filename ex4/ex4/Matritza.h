/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: Exercise 4
******************************************/

#ifndef MATRITZA_H
#define MATRITZA_H
#define SIZE_MAT 15


void MatrixBuild(int Matrix[][SIZE_MAT], int row, int col);
void SumMatrix(int firMatrix[][SIZE_MAT], int row, int col);
void Subtraction(int firMatrix[][SIZE_MAT], int row, int col);
int MultiMat(int firMatrix[][SIZE_MAT], int row, int col);
void CopyResultToFirstMat(int firMatrix[][SIZE_MAT], int resMatrix[][SIZE_MAT], int row, int col);
void TransposeMat(int firMatrix[SIZE_MAT][SIZE_MAT], int row, int col);
void MatrixPrint(int matrix[][SIZE_MAT], int row, int col);
int CheckRowCol(int row, int col);
int MainMatrix();
int MenuOperation(int matrix[][SIZE_MAT], int row, int col);

#endif
