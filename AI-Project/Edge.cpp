#include<iostream>
#include<vector>
#include "Edge.h"
#include "Node.h"

using namespace std;


Edge::Edge(Node* _parent, Node* _child, int _cost, Edge* _prev)
{
	parent = _parent;
	child = _child;
	cost = _cost;
	prev = _prev;
}

Edge* Edge::create(Node* _parent, Node* _child, int _cost, Edge* prev)
{
	Edge* newEdge = new Edge(_parent, _child, _cost, prev);
	_parent->children.push_back(newEdge);

	return newEdge;
}
