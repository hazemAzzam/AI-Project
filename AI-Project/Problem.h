#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include"Node.h"
class Problem
{
public:
	Node* initial;
	Node* goal;

	Problem(Node* _initial, Node* _goal) : initial(_initial), goal(_goal) { }
	bool isGoal(Node* node);
	vector<Edge*> extract(Node* node, Edge* prev);

	Edge* DFS();
};

