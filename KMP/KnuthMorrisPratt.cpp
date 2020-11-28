//
// Created by Isaac on 20/11/2020.
//

// m = length of pattern; n = length of searchable text; k = size of alphabet
// Preprocessing time: O(m)
// Matching time: O(n)
// Space: O(m)

// Best used for text with small alphabets, like DNA, does not rely on alphabet size in quite the same way as BM

#include "KnuthMorrisPratt.h"

std::string KnuthMorrisPratt::StringSearch(std::string needle, std::string haystack) {
	//input:
	//    an array of characters, S (the text to be searched)
	//    an array of characters, W (the word sought)
	//output:
	//    an array of integers, P (positions in S at which W is found)
	//    an integer, nP (number of positions)
	//
	//define variables:
	//    an integer, j ← 0 (the position of the current character in S)
	//    an integer, k ← 0 (the position of the current character in W)
	//    an array of integers, T (the table, computed elsewhere)
	//
	//let nP ← 0
	//
	//while j < length(S) do
	//    if W[k] = S[j] then
	//        let j ← j + 1
	//        let k ← k + 1
	//        if k = length(W) then
	//            (occurrence found, if only first occurrence is needed, m ← j - k  may be returned here)
	//            let P[nP] ← j - k, nP ← nP + 1
	//            let k ← T[k] (T[length(W)] can't be -1)
	//    else
	//        let k ← T[k]
	//        if k < 0 then
	//            let j ← j + 1
	//            let k ← k + 1
	return std::string();
}
