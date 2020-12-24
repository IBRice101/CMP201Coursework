//
// Created by Isaac on 20/11/2020.
//

// m = length of pattern; n = length of searchable text; needPos = size of alphabet
// Preprocessing time: O(m)
// Matching time: O(n)
// Space: O(m)

// Best used for text with small alphabets, like DNA, does not rely on alphabet size in quite the same way as BM
// Based on pseudocode from https://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm

#include <iostream>
#include <vector>

#include "KnuthMorrisPratt.h"

void KnuthMorrisPratt::TableGen() {
	for (int i = 0; i < 255; ++i) {
		table[i] = i;
	}
}

int KnuthMorrisPratt::StringSearch(std::string needle, std::string haystack) {
	int haystackPos = 0; // position of current character in haystack
	int needlePos = 0; // position of current character in needle
	TableGen();

	do {
		if (needle[needlePos] == haystack[haystackPos]) {
			haystackPos++;
			needlePos++;
			if (needlePos == needle.length()) {
			    pos[numPos] = haystackPos - needlePos;
			    numPos++;
				if (table[needle.length()] <= -1) {
					std::cout << "Error" << std::endl;
				} else {
                    needlePos = table[needlePos];
				}
			}
		} else {
            needlePos = table[needlePos];
			if (needlePos < 0) {
				haystackPos++;
				needlePos++;
			}
		}
	}while (haystackPos < haystack.length());

	std::cout << "Found " << needle << " in " << numPos << " positions" << std::endl;

    return numPos;
}
