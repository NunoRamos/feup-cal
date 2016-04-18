/*
 * BinarySearch.h
 *
 *  Created on: Apr 18, 2016
 *      Author: epassos
 */

#ifndef SRC_BINARYSEARCH_H_
#define SRC_BINARYSEARCH_H_

#include <vector>
using namespace std;

template <class T>
int BinarySearch(const vector<T> &v, T x){
	int left = 0, right = v.size() - 1;

	while (left <= right){
		int middle = (left + right) / 2;

		if(v[middle]<x)
			left = middle + 1;

		else if (x < v[middle])
			right = middle -1;

		else return middle;
	}
	return -1; //not found
}

#endif /* SRC_BINARYSEARCH_H_ */
