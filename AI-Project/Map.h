#pragma once
#include<iostream>
#include<vector>
#include"Node.h"

using namespace std;
class Map : public Node
{
public:
	string name;
	Map(string _name) : name(_name) { }
	void print();
};

