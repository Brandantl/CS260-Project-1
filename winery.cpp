/* 
 * File:   winery.cpp
 * Author: Brandan Tyler Lasley
 * Project: CS260 Project 1 (Lab 1)
 * 
 * Created on October 7, 2014, 8:39 AM
 */
#include "winery.h"

Winery::Winery(void) {
    name = NULL;
    location = NULL;
    acre = 0;
    rating = 0;
    year = 0;
}

bool Winery::operator<(const Winery& obj) const {
    if (strcmp(obj.name, this->name) < 0) {
        return true;
    } else {
        return false;
    }
}

bool Winery::operator==(const Winery& obj) const {
    if ((strcmp(obj.name, this->name) < 0) && (strcmp(obj.location, this->location) < 0) && (obj.acre == this->acre) && (obj.rating == this->rating) && (obj.year == this->year)) {
        return true;
    } else {
        return false;
    }
}

const Winery& Winery::operator=(const Winery& obj) {
	this->name = new char[strlen(obj.name) + 1];
	this->location = new char[strlen(obj.location) + 1];
    strcpy(this->name, obj.name);
    strcpy(this->location, obj.location);
    this->acre = obj.acre;
    this->rating = obj.rating;
    this->year = obj.year;
    return *this;
}

ostream& operator<<(ostream& out, const Winery& obj) {
    out << setw(25) << left;
    if (obj.getName()) {
        out << obj.getName();
    } else {
        out << " ";
    }
    out << setw(15) << left;
    if (obj.getLocation()) {
        out << obj.getLocation();
    } else {
        out << " ";
    }
    out << setw(10) << left;
    out << obj.getAcre();
    out << setw(10) << left;
    out << obj.getRating();
    out << setw(10) << left;
    out << obj.getYear();
    return out;
}

bool Winery::compareRatingconst(const Winery& obj) {
    if (this->rating < obj.rating) {
        return true;
    } else {
        return false;
    }
}

float Winery::getAcre(void) const {
    return this->acre;
}

char * Winery::getName(void) const {
    return this->name;
}

char * Winery::getLocation(void) const {
    return this->location;
}

int Winery::getYear(void) const {
    return this->year;
}

float Winery::getRating(void) const {
    return this->rating;
}

void Winery::setAcre(float _acre) {
    this->acre = _acre;
}

void Winery::setName(const char * _name) {
    if (this->name) {
        delete [] this->name;
    }
	this->name = new char[strlen(_name) + 1];
    strcpy(this->name, _name);
}

void Winery::setLocation(const char * _location) {
    if (this->location) {
        delete [] this->location;
    }
    this->location = new char[strlen(_location) + 1];
    strcpy(this->location, _location);
}

void Winery::setYear(int _year) {
    this->year = _year;
}

void Winery::setRating(float _rating) {
    this->rating = _rating;
}

Winery::~Winery(void) {
    if (this->name) {
        delete [] this->name;
    }
    if (this->location) {
        delete [] this->location;
    }
}