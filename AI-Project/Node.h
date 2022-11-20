#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Edge.h"

using namespace std;
class Node
{
private:
	virtual void getChildren() { };
public:
	vector<Edge*> children;
	virtual void print() = 0 { }
	virtual bool compare(Node* node) = 0 { return false; };

	vector<Edge*> extract(Edge* _prev) // return children, and set prev to each element in children
	{
		getChildren();
		for (auto child : children) {
			child->prev = _prev;
		}
		return children;
	}
};