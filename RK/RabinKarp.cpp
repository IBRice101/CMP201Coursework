//
// Created by isaac on 27/12/2020.
//

// With thanks to Tutorialspoint for providing pseudocode for algorithm and
// [NAME HERE] for providing inspiration for hash function

#include <string>
#include <iostream>
#include "RabinKarp.h"

void RabinKarp::StringSearch(const std::string& needle, const std::string& haystack) {

    int needleLen = needle.length(); // m
    int haystackLen = haystack.length(); // n
    int charIndex = 0; // character index

    // Hash variables (needle, haystack, needle+haystack, in that order)
    int needleHash = 0; int haystackHash = 0; int hash = 0;

    // hashing
    for (int i = 0; i < needleLen - 1; ++i) {
        hash = (hash * a) % prime;
    }

    for (int i = 0; i < needleLen; ++i) {
        needleHash = (a * needleHash + needle[i]) % prime;
        haystackHash = (a * haystackHash + haystack[i]) % prime;
    }

    // searching
    for (int i = 0; i < (haystackLen - needleLen); ++i) {
        if (needleHash == haystackHash) {
            for (charIndex = 0; charIndex < needleLen - 1; ++charIndex) {
                if (haystack[i + charIndex] != needle[charIndex]) {
                    break;
                }
            }
            if (charIndex == needleLen) {
                std::cout << "Pattern found at index: " << i << std::endl;
                found++;
            }
        }
        if (i < (haystackLen - needleLen)) {
            haystackHash = (a * (haystackHash - haystack[i] * hash) + haystack[i + needleLen]) % prime;
            if (haystackHash < 0) {
                haystackHash = haystackHash + prime;
            }
        }
    }
}
