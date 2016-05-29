/*
 * stringMatch.cpp
 *
 *  Created on: May 28, 2016
 *      Author: epassos
 */

#include "stringMatch.h"


using namespace std;


/**
 * @brief utilitary funcion that returns the minimum of three ints
 * used in approximate string matching
 */
inline int min(int a, int b, int c){
	return a < b ? a < c ? a : c :  b < c ?  b : c;
}

vector<int> KMPcomputePrefix(string P) {

	vector<int> pi(P.size());
	int m, k, q;

	m = P.size();
	k = 0;
	pi[0] = 0;

	for (q = 2; q < m; q++) {						//iterate the whole string
		while (k > 0 && P[k + 1] != P[q])
			k = pi[k];					//gets the length of the current prefix
		if (P[k + 1] == P[q])		//if it finds a bigger prefix, update
			k++;
		pi[q] = k;
	}

	return pi;
}


int numStringMatching(string pattern,string text) {

	vector<int> pi(pattern.size());
	pi = KMPcomputePrefix(pattern);


	int n, m, q, ret = 0;

	n = text.size();
	m = pattern.size();
	q = 0;


	for (int i = 1; i < n; i++) {

		while (q > 0 && pattern[q+1] != text[i]){
			q = pi[q];
		}

		if (pattern[q+1] == text[i]){
			q++;
		}

		if (q == m-1) {
			q = pi[q];
			ret++;
		}


	}

	return ret;

}


int editDistance(string  pattern, string text){

	int **distance;
	unsigned int m = pattern.size();
	unsigned int n = text.size();

	distance = (int**) malloc (m * sizeof(int*) + 1);
	for (unsigned int i = 0; i <= m; i++){
		distance[i] = (int*) malloc (n * sizeof(int) + 1);
	}

	//initializing
	for(unsigned int i = 0; i <= m; i++){
		distance[i][0] = i;
	}

	for(unsigned int j = 0; j <= n; j++){
		distance[0][j] = j;
	}

	for(unsigned int i = 1; i <= m; i++){
		for(unsigned int j = 1; j <= n; j++){
			if(pattern[i-1] == text[j-1])
				distance[i][j] = distance[i-1][j-1];
			else
				distance[i][j] = 1 + min(distance[i-1][j-1],distance[i-1][j],distance[i][j-1]);
		}
	}

	return distance[pattern.size()][ text.size()];
}

