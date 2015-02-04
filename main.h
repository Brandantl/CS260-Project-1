/* 
 * File:   main.h
 * Author: Brandan Tyler Lasley
 * Project: CS260 Project 1 (Lab 1)
 * 
 * Created on October 10, 2014, 9:07 AM
 */
#ifndef MAIN_H
#define	MAIN_H
#include <iostream>
#include <cstdlib>
#include "list.h"
const int MAX_LEN = 100;
void displayMenu();
char getCommand();
int getInt(char * prompt);
float getFloat(char * prompt);
void getString(char * prompt, char * input);
void executeCmd(char command, list& aList);
void getWinery(Winery& obj);
void display(const list & aList);
bool fileExists(const char *fileName);
#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

