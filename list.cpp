/* 
 * File:   list.cpp
 * Author: Brandan Tyler Lasley
 * Project: CS260 Project 1 (Lab 1)
 * 
 * Created on October 7, 2014, 8:39 AM
 */
#include "list.h"

list::list() {
    size = 0;
    node * headByName = NULL;
    node * headByRating = NULL;
}

list::list(const list& obj) {
    if (obj.headByName == NULL) {
        headByName = NULL;
    } else {
        headByName = new node;
        assert(headByName != NULL);
        headByName->item = obj.headByName->item;

        node * destNode = headByName;
        node * srcNode = obj.headByName;
        while (srcNode != NULL) {
            destNode->nextByName = new node;
            assert(destNode->nextByName != NULL);
            destNode = destNode->nextByName;
            srcNode = srcNode->nextByName;
        }
        destNode->nextByName = NULL;
    }

    if (obj.headByRating == NULL) {
        headByRating = NULL;
    } else {
        assert(headByRating != NULL);
        node * destNode = headByRating;
        node * srcNode = obj.headByRating;
        while (srcNode != NULL) {
            destNode->nextByRating = new node;
            assert(destNode->nextByRating != NULL);
            destNode = destNode->nextByRating;
            srcNode = srcNode->nextByRating;
        }
        destNode->nextByRating = NULL;
    }
}

list::~list() {
    if (size != 0) {
        node * curr = headByName;
        while (headByName) {
            curr = headByName->nextByName;
            delete headByName;
            headByName = curr;
        }
    }
}

list& list::operator=(const list& obj) {
    if (this == &obj)
        return *this;
    else {
        node * curr = headByName;
        while (headByName) {
            curr = headByName->nextByName;
            delete headByName;
            headByName = curr;
        }
        if (!obj.headByName)
            headByName = NULL;
        else {
            headByName = new node;
            assert(headByName != NULL);
            headByName->item = obj.headByName->item;
            node * destNode = headByName;
            node * srcNode = obj.headByName->nextByName;
            while (srcNode) {
                destNode->nextByName = new node;
                assert(destNode->nextByName);
                destNode = destNode->nextByName;
                destNode->item = srcNode->item;
                srcNode = srcNode->nextByName;
            }
            destNode->nextByName = NULL;
        }
        return *this;
    }
}

bool list::insert(const Winery& obj) {
    node * ByName_prev = NULL;
    node * ByName_curr = headByName;
    node * ByRating_prev = NULL;
    node * ByRating_curr = headByRating;

    while (ByName_curr != NULL && ByName_curr->item < obj) {
        ByName_prev = ByName_curr;
        ByName_curr = ByName_curr->nextByName;
    }

    while (ByRating_curr != NULL && ByRating_curr->item.compareRatingconst(obj)) {
        ByRating_prev = ByRating_curr;
        ByRating_curr = ByRating_curr->nextByRating;
    }

    if (ByName_curr && ByName_curr->item == obj) {
        return false;
    } else {
        // Create a new node
        node * newNode = new node;
        newNode->item = obj;
        newNode->nextByName = ByName_curr;
        if (ByName_prev == NULL) {
            headByName = newNode;
        } else {
            ByName_prev->nextByName = newNode;
        }
        if (ByRating_curr && ByRating_curr->item == obj) {
            return false;
        } else {
            newNode->nextByRating = ByRating_curr;
            if (ByRating_prev == NULL) {
                headByRating = newNode;
            } else {
                ByRating_prev->nextByRating = newNode;
            }
            size++;
            return true;
        }
    }
    return false;
}

bool list::remove(char * name) {
    if (size > 0) {
        node * prev = NULL;
        node * curr;
        bool found = false;

        if (size == 0) {
            return false;
        } else {

            for (curr = headByName; curr; curr = curr->nextByName) {
                if (strcmp(curr->item.getName(), name) == 0) {
                    found = true;
                    if (!prev) {
                        headByName = curr->nextByName;
                    } else {
                        prev->nextByName = curr->nextByName;
                    }
                    break;
                }
                prev = curr;
            }

            prev = NULL;
            curr = NULL;

            for (curr = headByRating; curr; curr = curr->nextByRating) {
                if (strcmp(curr->item.getName(), name) == 0) {
                    found = true;
                    if (!prev) {
                        headByRating = curr->nextByRating;
                    } else {
                        prev->nextByRating = curr->nextByRating;
                    }
                    break;
                }
                prev = curr;
            }

            if (found) {
                delete curr;
                size--;
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}

void list::display(bool byName) const {
    if (size != 0) {
        cout << "Name" << setw(29) << "Location" << setw(11) << "Acre" << setw(10) << "Rating" << setw(10) << "Year" << endl;
        
        if (byName) {
            node * curr;
            for (curr = headByName; curr; curr = curr->nextByName) {
                cout << curr->item << endl;
            }
        } else {
            node * curr;
            for (curr = headByRating; curr; curr = curr->nextByRating) {
                cout << curr->item << endl;
            }
        }
        
    }
}

int list::GetSize(void) {
    return this->size;
}

bool list::search(char * const name) const {
    if (size > 0) {
        node * curr;
        for (curr = headByName; curr; curr = curr->nextByName) {
            if (strcmp(curr->item.getName(), name) == 0) {
                return true;

            }
        }
        return false;
    }
	return false;
}

Winery * list::retrieve(char * const name) const {
    if (size > 0) {
        node * curr;
        for (curr = headByName; curr; curr = curr->nextByName) {
            if (strcmp(curr->item.getName(), name) == 0) {
                return &curr->item;
            }
        }
        return NULL;
    }
	return NULL;
}

bool list::WriteToDisk(void) {
    ofstream launchCodesFile;
    launchCodesFile.open("launch-codes", ios::trunc); // Truncate those codes, do not want spies stealing them.

    if (size != 0) {
        node * curr;
        for (curr = headByName; curr; curr = curr->nextByName) {
            launchCodesFile << curr->item.getName();
            launchCodesFile << ",";
            launchCodesFile << curr->item.getLocation();
            launchCodesFile << ",";
            launchCodesFile << curr->item.getAcre();
            launchCodesFile << ",";
            launchCodesFile << curr->item.getRating();
            launchCodesFile << ",";
            launchCodesFile << curr->item.getYear();
            launchCodesFile << "\n";
            cout << curr->item << endl;
        }
    }
    launchCodesFile.close();
    return true;
}

bool list::ReadFromDisk(void) {
    ifstream codes("launch-codes");
    while (codes) {
        string s;
        if (!getline(codes, s)) break;
        istringstream ss(s);
        while (ss) {
            Winery obj;
            string s;
            if (!getline(ss, s, ',')) break;
            obj.setName(s.c_str());
            if (!getline(ss, s, ',')) break;
            obj.setLocation(s.c_str());
            if (!getline(ss, s, ',')) break;
            obj.setAcre((float) atof(s.c_str()));
            if (!getline(ss, s, ',')) break;
            obj.setRating((float) atof(s.c_str()));
            if (!getline(ss, s, ',')) break;
            obj.setYear(atoi(s.c_str()));
            this->insert(obj);
        }
    }
    if (!codes.eof()) {
        return false;
    }
    return true;
}