//
// Created by Isaac on 20/11/2020.
//

// m = length of pattern; n = length of searchable text; needPos = size of alphabet
// Preprocessing time: O(m)
// Matching time: O(n)
// Space: O(m)

// Best used for text with small alphabets, like DNA, does not rely on alphabet size in quite the same way as BM

#include "KnuthMorrisPratt.h"

int KnuthMorrisPratt::StringSearch(std::string needle, std::string haystack) {
	//input:
	//    an array of characters, haystack (the text to be searched)
	//    an array of characters, needle (the word sought)
	//output:
	//    an array of integers, pos (positions in haystack at which needle is found)
	//    an integer, numPos (number of positions)
	//
	//define variables:
	//    an integer, hayPos = 0 (the position of the current character in haystack)
	//    an integer, needPos = 0 (the position of the current character in needle)
	//    an array of integers, table (the table, computed elsewhere)
	//
	//let numPos = 0
	//
	//while hayPos < length(haystack) do
	//    if needle[needPos] = haystack[hayPos] then
	//        let hayPos = hayPos + 1
	//        let needPos = needPos + 1
	//        if needPos = length(needle) then
	//            (occurrence found, if only first occurrence is needed, m = hayPos - needPos  may be returned here)
	//            let pos[numPos] = hayPos - needPos, numPos = numPos + 1
	//            let needPos = table[needPos] (table[length(needle)] can't be -1)
	//    else
	//        let needPos = table[needPos]
	//        if needPos < 0 then
	//            let hayPos = hayPos + 1
	//            let needPos = needPos + 1
}
