// 
// Created by Isaac on 20/11/2020.
//

// With thanks to Tutorialspoint for providing pseudocode for algorithm


#include <iostream>
#include "BoyerMoore.h"

using std::string;

using std::cout;
using std::endl;

void BoyerMoore::FullSuffixMatch(int shiftArr[], int borderArr[], std::string needle) const {
    int i = needleLen;
    int j = needlePlusOne;
    borderArr[i] = j;

    while (i > 0) {
        while (j <= i && needle[i - 1] != needle[j - 1]) {
            if (shiftArr[j] == 0) {
                shiftArr[j] = j-i;
            }
            j = borderArr [j];
        }

        i--; j--;
        borderArr[i] = j;
    }
}

void BoyerMoore::PartialSuffixMatch(int shiftArr[], const int borderArr[]) const {
    int n = needleLen;
    int j = borderArr[0];

    for (int i = 0; i < n; ++i) {
        if (shiftArr[i] == 0) {
            shiftArr[i] = j;
        }
        if (i == j) {
            j = borderArr[j];
        }
    }
}

void BoyerMoore::StringSearch(const string& needle, string& haystack) {
    needleLen = needle.length();
    haystackLen = haystack.length();
    needlePlusOne = needleLen + 1;

    int borderArray[needlePlusOne];
    int shiftArray[needlePlusOne];

    for (int i = 0; i < needlePlusOne; ++i) {
        shiftArray[i] = 0;
    }

    FullSuffixMatch(shiftArray, borderArray, needle);
    PartialSuffixMatch(shiftArray, borderArray);
    int shift = 0;

    while (shift <= (haystackLen - needleLen)) {
        int j = needleLen - 1;
        while (j >= 0 && needle[j] == haystack[shift + j]) {
            j--;
        }

        if (j < 0) {
            cout << "Pattern found at position: " << j << endl;
            shift += shiftArray[0];
            found++;
        } else {
            shift += shiftArray[j + 1];
        }
    }
}
