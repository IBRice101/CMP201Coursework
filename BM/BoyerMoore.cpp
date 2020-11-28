// 
// Created by Isaac on 20/11/2020.
// 

// m = length of pattern; n = length of searchable text; k = size of alphabet
// Preprocessing time: O(m + k)
// Matching time:
    // best: O(n / m)
    // worst: O(mn)
// Space: O(k)

// Best used for human language (written text etc)

#include "BoyerMoore.h"

std::string BoyerMoore::StringSearch(std::string needle, std::string haystack) {
	// start at beginning of string
	// start at beginning of match
	// while not at the end of the string:
		// if match_position is 0:
			// Jump ahead m characters
			// Look at character, jump back based on table 1
			// If match the first character:
				// advance match position
			// advance string position
		// else if I match:
			// if I reached the end of the match:
			// FOUND MATCH - return
			// else:
				// advance string position and match position.
		// else:
			// pos1 = table1[ character I failed to match ]
			// pos2 = table2[ how far into the match I am ]
			// if pos1 < pos2:
				// jump back pos1 in string
				// set match position at beginning
			// else:
				// set match position to pos2
	// FAILED TO MATCH
	return std::string();
}
