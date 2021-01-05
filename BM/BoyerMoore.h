//
// Created by Isaac on 20/11/2020.
//

#ifndef STRINGSEARCHCOMPARISON_BOYERMOORE_H
#define STRINGSEARCHCOMPARISON_BOYERMOORE_H

#include "../utilities.h"

class BoyerMoore {
public:
    int found = 0; // incremented if text is found

    bool inPattern[256]{}; // represents 256 ascii chars, if inPattern[x] == true, ascii x is in pattern

	void StringSearch(const std::string& needle, std::string& haystack);
};


#endif //STRINGSEARCHCOMPARISON_BOYERMOORE_H
