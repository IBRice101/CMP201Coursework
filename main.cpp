#include <iostream>
#include <fstream>
#include <chrono>

#include "Utils/utilities.h"
#include "BM/BoyerMoore.h"
#include "RK/RabinKarp.h"

using namespace std::chrono;

BoyerMoore BM;
RabinKarp RK;

std::string fileOpen(const std::string& file) {
    std::string text;
    text = nullptr;

    std::ifstream readFile(file);

    getline(readFile, text);

    readFile.close();

    return text;
}

int main() {
    std::cout << "CMP 201 String Search Algorithm Comparison - 2020/1 Isaac Basque-Rice" << std::endl;
    std::cout << "Boyer-Moore vs Rabin-Karp" << std::endl;

    std::string needle; // pattern
    std::string haystack; // searched text
    std::string haystackLocation; // location of searched text if in a txt file
    haystackLocation = nullptr;

    char answer; // y or n, will assume y if no input
    bool fileInput; // if true user will define which text file they would like to search

    std::cout << "Would you like to load data from a file? (y/n)";
    std::cin >> answer;

    switch (answer) {
        case 'Y': case 'y':
            fileInput = true;
            break;

        case 'N': case 'n':
            fileInput = false;
            break;

        default:
            fileInput = true;
            break;
    }

    if (fileInput) {
        std::cout << "which text file would you like to test on?" << std::endl;
        std::cin >> haystackLocation;

        haystack = fileOpen(haystackLocation);
    } else {
        std::cout << "Please input the text you would like to search: " << std::endl;
        std:: cin >> haystack;
    }

    std::cout << "What string would you like to search for?" << std::endl;
    std::cin >> needle;

    if (!haystackLocation.empty()) {
        std::cout << "Searching for \"" << needle << "\" in " << haystackLocation << std::endl;
    } else {
        std::cout << "Searching for \"" << needle << "\" in " << haystack << std::endl;
    }

    int timeBM = 0;
    int timeRK = 0;

    std::cout << "Boyer-Moore: " << std::endl;

    auto BMStart = high_resolution_clock::now();
    BM.StringSearch(needle, haystack);
    auto BMStop = high_resolution_clock::now();

    auto BMDuration = duration_cast<milliseconds>(BMStop - BMStart);
    // print "Pattern \"" + needle + "\" found at positions " BoyerMoore.pos
    // Display diagram showing this (like the one adam wrote, found in Utils)

    std::cout << "Rabin-Karp" <<std::endl;

    auto RKStart = high_resolution_clock::now();
    RK.StringSearch(needle, haystack);
    auto RKStop = high_resolution_clock::now();

    auto RKDuration = duration_cast<milliseconds>(RKStop - RKStart);
    // print "Pattern \"" + needle + "\" found at positions " BoyerMoore.pos
    // Display diagram showing this (like the one adam wrote, found in Utils)

    std::cout << "BM \t : \t RK" << std::endl;
    std::cout << BMDuration.count() << "ms \t : \t" << RKDuration.count() << "ms" << std::endl;
}
