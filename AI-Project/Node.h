#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Edge.h"

using namespace std;
class Node
{
public:
	vector<Edge*> children;
	virtual void print() = 0 { }
	virtual vector<Edge*> extract(Edge* _prev) // return children, and set prev to each element in children
	{
		for (auto child : children) {
			child->prev = _prev;
		}
		return children;
	}
};