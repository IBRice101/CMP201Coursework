//
// Created by Isaac on 20/11/2020.
//

#ifndef STRINGSEARCHCOMPARISON_KNUTHMORRISPRATT_H
#define STRINGSEARCHCOMPARISON_KNUTHMORRISPRATT_H

#include "../Utils/utilities.h"

class KnuthMorrisPratt {
public:
    unsigned char table[256]; // table of ASCII values, filled in TableGen();

    std::vector<int> pos; // positions in haystack at which needle is found
    int numPos = 0; // number of positions

	void TableGen();
	int StringSearch(std::string needle, std::string haystack);

};


#endif //STRINGSEARCHCOMPARISON_KNUTHMORRISPRATT_H
