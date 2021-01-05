//
// Created by isaac on 27/12/2020.
//

// With thanks to Tutorialspoint for providing pseudocode for algorithm and
// Adam Sampson for providing inspiration for hash function

#include <string>
#include <iostream>
#include "RabinKarp.h"

using std::string;

using std::cout;
using std::endl;

void RabinKarp::StringSearch(const string& needle, const string& haystack) {

    int needleLen = needle.length(); // m
    int haystackLen = haystack.length(); // n

    // Hash variables (needle, haystack, needle+haystack, in that order)
    int needleHash = 0; int haystackHash = 0; int hash = 1;

    int i;

    // hashing
    for (i = 0; i < needleLen; ++i) {
        hash = (hash * d) % prime;
    }

    for (i = 0; i < needleLen; ++i) {
        needleHash = (d * needleHash + needle[i]) % prime;
        haystackHash = (d * haystackHash + haystack[i]) % prime;
    }

    // searching
    for (i = 0; i < (haystackLen - needleLen); ++i) {
        if (needleHash == haystackHash) {
        	int j;
            for (j = 0; j < needleLen; ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == needleLen) {
				cout << "Found pattern \"" << needle << "\" at index: " << i << endl;
				found++;
            }
        }
        if (i < (haystackLen - needleLen)) {
            haystackHash = (d * (haystackHash - haystack[i] * hash) + haystack[i + needleLen]) % prime;
            if (haystackHash < 0) {
                haystackHash = haystackHash + prime;
            }
        }
    }
}
