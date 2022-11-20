#pragma once
#include<iostream>
#include<vector>
#include"Node.h"

using namespace std;
class Map : public Node
{
public:
	string name;
	bool compare(Node* map) {
		return (this->name == static_cast<Map*>(map)->name);
	}
	Map(string _name) : name(_name) { }
	void print();
};

