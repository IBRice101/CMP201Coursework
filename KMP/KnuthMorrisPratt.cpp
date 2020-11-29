//
// Created by Isaac on 20/11/2020.
//

// m = length of pattern; n = length of searchable text; needPos = size of alphabet
// Preprocessing time: O(m)
// Matching time: O(n)
// Space: O(m)

// Best used for text with small alphabets, like DNA, does not rely on alphabet size in quite the same way as BM

#include <iostream>
#include "KnuthMorrisPratt.h"

char table[256]; // table of ASCII values, filled in TableGen();

// todo: add a vector of integers called pos (for positions in haystack at which needle is found)
int numPos = 0;

void KnuthMorrisPratt::TableGen() {
	for (int i = 0; i < 255; ++i) {
		table[i] = i;
	}
}

int KnuthMorrisPratt::StringSearch(std::string needle, std::string haystack) {
	int hayPos = 0; // position of current character in haystack
	int needPos = 0; // position of current character in needle

	do {
		if (needle[needPos] == haystack[hayPos]) {
			hayPos++;
			needPos++;
			if (needPos == needle.length()) {
				// pos<numPos> = hayPos - needPos, numPos++
				if (table[needle.length()] <= -1) {
					std::cout << "Error" << std::endl;
				} else {
					needPos = table[needPos];
				}
			}
		} else {
			needPos = table[needPos];
			if (needPos < 0) {
				hayPos++;
				needPos++;
			}
		}
	}while (hayPos < haystack.length());
}
