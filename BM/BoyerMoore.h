//
// Created by Isaac on 20/11/2020.
//

#ifndef STRINGSEARCHCOMPARISON_BOYERMOORE_H
#define STRINGSEARCHCOMPARISON_BOYERMOORE_H

#include "../utilities.h"

class BoyerMoore {
public:
    int found = 0; // incremented if text is found
    int needleLen = 0; // length of pattern
    int haystackLen = 0; // length of text

    bool inPattern[256];

    #define a 256 // macro for ASCII charset

	void StringSearch(const std::string& needle, std::string& haystack);
};


#endif //STRINGSEARCHCOMPARISON_BOYERMOORE_H
