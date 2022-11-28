#pragma once
#include<iostream>
#include<vector>

using namespace std;

class Node;

class Edge
{
public:
	Node* parent = NULL;
	Node* child  = NULL;
	Edge* prev   = NULL;
	//bool visited = false;
	
	int cost = 0;
	Edge(Node* _parent = NULL, Node* _child = NULL, int _cost = 0, Edge* _prev = NULL);
	static Edge* create(Node* _parent = NULL, Node* _child = NULL, int _cost = 0, Edge* _prev = NULL);
};

