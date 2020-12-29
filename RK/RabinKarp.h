//
// Created by isaac on 27/12/2020.
//

#ifndef STRINGSEARCHCOMPARISON_RABINKARP_H
#define STRINGSEARCHCOMPARISON_RABINKARP_H


class RabinKarp {
public:

    bool found; // returns true if text is found
    int timeTaken; // the amount of time (in ms) the algorithm took
    int prime = 127; //for hash function
    #define a 256 // macro for ASCII charset


    void StringSearch(const std::string& needle, const std::string& haystack);
};


#endif //STRINGSEARCHCOMPARISON_RABINKARP_H
