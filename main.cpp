#include <iostream>
#include <fstream>
#include <chrono>

#include "Utils/utilities.h"
#include "BM/BoyerMoore.h"
#include "RK/RabinKarp.h"

using namespace std::chrono;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;

using std::string;

using std::ifstream;

using std::cout;
using std::endl;
using std::cin;

BoyerMoore BM;
RabinKarp RK;

string fileOpen(const string& file) {
    string text;
    text = nullptr;

    ifstream readFile(file);

    getline(readFile, text);

    readFile.close();

    return text;
}

int main() {
    cout << "CMP 201 String Search Algorithm Comparison - 2020/1 Isaac Basque-Rice" << endl;
    cout << "Boyer-Moore vs Rabin-Karp" << endl;

    string needle; // pattern
    string haystack; // searched text
    string haystackLocation; // location of searched text if in a txt file
    haystackLocation = nullptr;

    char answer; // y or n, will assume y if no input
    bool fileInput; // if true user will define which text file they would like to search

    cout << "Would you like to load data from a file? (y/n)";
    cin >> answer;

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
        cout << "which text file would you like to test on?" << endl;
        cin >> haystackLocation;

        haystack = fileOpen(haystackLocation);
    } else {
        cout << "Please input the text you would like to search: " << endl;
        cin >> haystack;
    }

    cout << "What string would you like to search for?" << endl;
    cin >> needle;

    if (!haystackLocation.empty()) {
        cout << "Searching for \"" << needle << "\" in " << haystackLocation << endl;
    } else {
        cout << "Searching for \"" << needle << "\" in " << haystack << endl;
    }

    cout << "Boyer-Moore: " << endl;

    auto BMStart = high_resolution_clock::now();
    BM.StringSearch(needle, haystack);
    auto BMStop = high_resolution_clock::now();

    auto BMDuration = duration_cast<milliseconds>(BMStop - BMStart);
    // print "Pattern \"" + needle + "\" found at positions " BoyerMoore.pos
    // Display diagram showing this (like the one adam wrote, found in Utils)

    cout << "Rabin-Karp" <<endl;

    auto RKStart = high_resolution_clock::now();
    RK.StringSearch(needle, haystack);
    auto RKStop = high_resolution_clock::now();

    auto RKDuration = duration_cast<milliseconds>(RKStop - RKStart);
    // print "Pattern \"" + needle + "\" found at positions " RabinKarp.pos
    // Display diagram showing this (like the one adam wrote, found in Utils)

    cout << "BM \t : \t RK" << endl;
    cout << BMDuration.count() << "ms \t : \t" << RKDuration.count() << "ms" << endl;
    cout << "Boyer-Moore found \"" << needle << "\" " << BM.found << "times" << endl;
}
