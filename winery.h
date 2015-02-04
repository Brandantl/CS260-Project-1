/* 
 * File:   winery.h
 * Author: Brandan Tyler Lasley
 * Project: CS260 Project 1 (Lab 1)
 * 
 * Created on October 8, 2014, 10:09 PM
 */

#ifdef _MSC_VER // Disables Microsofts Cross-platform restriction warning. 
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef WINERY_H
#define	WINERY_H
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

class Winery {
public:
    Winery(void);
    ~Winery(void);
    float getAcre(void) const;
    char * getName(void) const;
    char * getLocation(void) const;
    int getYear(void) const;
	float getRating(void) const;
    void setAcre(float _acre);
    void setName(const char * _name);
    void setLocation(const char * _location);
    void setYear(int _year);
    void setRating(float rating);
    bool operator<(const Winery& obj) const;
    bool operator==(const Winery& obj) const;
    const Winery& operator=(const Winery& obj);
    friend ostream& operator<< (ostream& , const Winery&);
    bool compareRatingconst(const Winery& obj);
private:
    char * name;
    char * location;
    float acre;
    float rating;
    int year;
};
#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* WINERY_H */