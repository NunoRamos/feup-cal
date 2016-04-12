/*
 * Node.h
 *
 *  Created on: Apr 12, 2016
 *     Authors: Daniel Garrido, Edgar Passos, Nuno Ramos
 */

#ifndef SRC_NODE_H_
#define SRC_NODE_H_

using namespace std;

class Edge;

template <class T>
class Node{

	long id;
	int lat, lon;
	Edge* roads;
};



#endif /* SRC_NODE_H_ */
