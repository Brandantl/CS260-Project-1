/* 
 * File:   list.h
 * Author: Brandan Tyler Lasley
 * Project: CS260 Project 1 (Lab 1)
 * 
 * Created on October 7, 2014, 8:40 AM
 */


#ifndef LIST_H
#define	LIST_H

#ifdef	__cplusplus
#include "winery.h"
#include <iostream>
#include <assert.h>
#include <string.h>
#include <iomanip>
#include <fstream>
#include <sstream> 
#include <stdlib.h> 
using namespace std;

class list {
public:
    list(void);
    list(const list &obj);
    ~list();
    list& operator=(const list &obj);
    bool insert(const Winery& obj);
    bool remove(char * name);
    void display(bool byName) const;
    int Length(void) const;
    bool WriteToDisk(void);
    bool ReadFromDisk(void);
    int GetSize(void);
    Winery* retrieve(char * const name) const;
    bool search(char * const name) const;
private:

    struct node {
        Winery item;
        node * nextByName;
        node * nextByRating;
    };

    node * headByName;
    node * headByRating;
    int size;
};
extern "C" {
#endif



#ifdef	__cplusplus


}
#endif

#endif	/* LIST_H */
