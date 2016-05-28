/*
 * stringMatch.h
 *
 *  Created on: May 28, 2016
 *      Author: epassos
 */

#ifndef SRC_STRINGMATCH_H_
#define SRC_STRINGMATCH_H_

using namespace std;

/**
 *\brief prefix function that preprocesses the pattern used in the Knuth-Morris-Pratt algorithm
 */
vector<int> KMPcomputePrefix(string P);

/**
 * \brief implementation of the Knuth-Morris-Pratt algorithm that returns the number of occurrences
 * of a pattern on a text
 */
int numStringMatching(string text, string pattern);

/**
 * \brief function that returns the edit distance between two strings
 */
int editDistance(string  pattern, string text);


#endif /* SRC_STRINGMATCH_H_ */
