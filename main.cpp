#include <iostream>
#include <fstream>

#include "Utils/utilities.h"
#include "BM/BoyerMoore.h"
#include "KMP/KnuthMorrisPratt.h"

std::string fileOpen(const std::string& file) {
    std::string text;
    std::ifstream readFile(file);

    getline(readFile, text);

    readFile.close();

    return text;
}

int main() {
    std::cout << "CMP 201 String Search Algorithm Comparison - 2020/1 Isaac Basque-Rice" << std::endl;
    std::cout << "Boyer-Moore vs Knuth-Morris-Pratt" << std::endl;

    std::string needle; // pattern
    std::string haystack; // searched text
    std::string haystackLocation; // location of searched text if in a txt file

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

    std::cout << "Boyer-Moore: " << std::endl;
    // BoyerMoore(needle, haystack)
    // measure time taken in ms
    // put value in int timeBM
    // print "Pattern \"" + needle + "\" found at position " BoyerMoore.pos
    // Display diagram showing this (like the one adam wrote, found in Utils)

    std::cout << "Knuth-Morris-Pratt" <<std::endl;
    // KnuthMorrisPratt(needle, haystack)
    // measure time taken in ms
    // put value in int timeKMP
    // print "Pattern \"" + needle + "\" found at position " KnuthMorrisPratt.pos
    // Display diagram showing this (like the one adam wrote, found in Utils)

    // print: "BM" + \tab + ":" + \tab + "KMP"
    // print: timeBM + "ms" + \tab + ":" + \tab + timeKMP + "ms"
}
