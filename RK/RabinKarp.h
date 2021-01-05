//
// Created by isaac on 27/12/2020.
//

#ifndef STRINGSEARCHCOMPARISON_RABINKARP_H
#define STRINGSEARCHCOMPARISON_RABINKARP_H


class RabinKarp {
public:

    int found = 0; // incremented if text is found
    const int prime = 127; //for hash function
    #define d 256 // macro for ASCII charset


    void StringSearch(const std::string& needle, const std::string& haystack);
};


#endif //STRINGSEARCHCOMPARISON_RABINKARP_H
