/******************************************
* Student name: Or Paz
* Student: 311250708
* Course Exercise Group: 01
* Exercise name: Exercise 5
******************************************/
#ifndef MISSION5_H
#define MISSION5_H

char** GetInputsAndStore(int *numOfItem);
void SwapString(char** x, char** y);
void PrintString(char **ptr, int numOfItem);
void SortingWords(char **ptr, int numOfItem);
char** SaveWordToArray(char **arrayWords, char *word, int *countWords);
void FreeMemory(char **ptr, int numberOfItem);
char* GetNewWords();

#endif