// 
// Created by Isaac on 20/11/2020.
//

// With inspiration from and thanks to Adam Sampson of Abertay University

#include <iostream>
#include "BoyerMoore.h"

using std::string;

using std::cout;
using std::endl;

void BoyerMoore::StringSearch(const string& needle, string& haystack) {
    needleLen = needle.size();
    haystackLen = haystack.size();

    // lookup table
    for (bool & i : inPattern) {
        i = false;
    }
    for (char c : needle) {
        inPattern[int(c)] = true;
    }

    for (int i = 0; i < (haystackLen - needleLen); ++i) {
        if (!inPattern[int(haystack[i + needleLen - 1])]) {
            i += needleLen - 1;
            continue;
        }

        int j;
        int check = 0;
        for (j = 0; j < needleLen; ++j) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
            else
            {
                check++;
            }
            if (check == needleLen)
            {
                cout << "Found pattern \"" << needle << "\" at index: " << i << endl;
                found++;
            }
        }
    }
}