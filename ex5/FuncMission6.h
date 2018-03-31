/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: Exercise 5
******************************************/
#ifndef FUNCMISSION6_H
#define FUNCMISSION6_H


void PrintMenu();
int** AddItem(int **queue, int *numOfElement);
int** RemoveItem(int **queue, int *numOfElement);
void ShiftLeft(int **queue, int numOfElement);
void PrintQueue(int **queue, int numOfElement);
void PrintMax(int **queue, int numOfElement);
void PrintMin(int **queue, int numOfElement);
void PrintIndex(int **queue, int numOfElement);
int** ClearQueue(int **queue, int *numOfElement);
void DestroyQueue(int **queue, int numOfElement);



#endif