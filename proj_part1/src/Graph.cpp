/*
 * Graph.cpp
 *
 *  Created on: Apr 18, 2016
 *      Author: epassos
 */

#include "Graph.h"
using namespace std;

const int INT_INFINITY = INT_MAX;

//******ROAD************
Road::Road(long id, string name, bool twoWay){
	this->id = id;
	this->name = name;
	this->twoWay = twoWay;
}


string Road::getName() const{
	return name;
}

long Road::getID() const{
	return id;
}

bool Road::isTwoWay() const{
	return twoWay;
}

//******EDGE************
Edge::Edge(Road *road){
	this->road = road;
}

Road Edge::getRoad() const{
	return *road;
}

void Edge::setDest(Node *from, Node *to){
	this->dest = to;
	this->weight = getDistance(from->getCoordinates(), to->getCoordinates());
}

Node Edge::getDest() const{
	return *dest;
}


//******NODE************

/**
 *\brief Constructor for the Node class
 */
Node::Node(long id, Coordinates *coords, Point *point) {
	this->id = id;
	this->coords = coords;
	this->point = point;
	this->visited = false;
}

long Node::getId() {
	return id;
}

Coordinates Node::getCoordinates() {
	return *coords;
}

Point Node::getPoint() {
	return *point;
}

bool Node::wasVisited() {
	return visited;
}

bool Node::addEdgeTo(Node *n, Edge *e){
	e->setDest(this,n);
	this->adj.push_back(e);
}

int Node::getIndegree(){
	return indegree;
}


//********GRAPH************
Graph::Graph(vector<Node *> vertexSet){
	this->vertexSet = vertexSet;
}

void Graph::resetIndegrees(){
	cout<<"Entrei\n"<<vertexSet.size()<<endl;

	for(unsigned int i=0; i<vertexSet.size(); i++){
		vertexSet[i]->indegree=0;
	}

	for(unsigned int i=0; i<vertexSet.size(); i++){
		for(unsigned int j=0; j<vertexSet[i]->adj.size(); j++){
			vertexSet[i]->adj[j]->dest->indegree++;
		}
	}

	cout<<"Estou a sair da funcao indegree\n";
}

void Graph::bellmanFordShortestPath(long id_dest){

	for(unsigned int i = 0; i < vertexSet.size(); i++) {
		vertexSet[i]->path = NULL;
		vertexSet[i]->dist = INT_INFINITY;
	}

	Node* v = getNode(id_dest);
	v->dist = 0;
	queue<Node*> q;
	q.push(v);

	while( !q.empty() ) {
		v = q.front(); q.pop();
		for(unsigned int i = 0; i < v->adj.size(); i++) {
			Node* w = v->adj[i]->dest;
			if(v->dist + v->adj[i]->weight < w->dist) {
				w->dist = v->dist + v->adj[i]->weight;
				w->path = v;
				q.push(w);
			}
		}
	}

/*	for(int i=0; i<2000; i++){
		cout << vertexSet[i]->getId()<<"   ";
		cout<< vertexSet[i]->dist<<endl;
	}*/

}

vector<Node*> Graph::getPath(long id_origin, long id_dest){
	list<Node *> buffer;
	Node* v = getNode(id_dest);

	buffer.push_front(v);
	while ( v->path != NULL &&  v->path->id != id_origin) {
		v = v->path;
		buffer.push_front(v);
	}
	if( v->path != NULL )
		buffer.push_front(v->path);


	vector<Node *> res;
	while( !buffer.empty() ) {
		res.push_back( buffer.front() );
		buffer.pop_front();
	}
	return res;
}

Node* Graph::getNode(long id){
	for(unsigned int i=0; i<vertexSet.size(); i++){
		if(vertexSet[i]->id == id)
			return vertexSet[i];
	}

	return NULL;
}
