#pragma once
#include<iostream>
#include<vector>
#include"Node.h"

using namespace std;

struct Point
{
	int x, y;
	Point(int _x, int _y) : x(_x), y(_y) { }
	Point operator+(const Point p) {
		return Point(x + p.x, y + p.y);
	}
	bool operator>=(const Point p) {
		return x >= p.x || y >= p.y;
	}
	bool operator<(const Point p) {
		return x < p.x || y < p.y;
	}
};

class Puzzle : public Node
{
private:
	bool isPossibleMove(Point point);
	Puzzle* move(Point point);

public:
	int id;
	int n = 3;
	vector<vector<int>> data;
	Point pivot;

	bool compare(Node* node);
	void print();
	Puzzle(vector<vector<int>> _puzzle, Point _pivot) : data(_puzzle), pivot(_pivot) { }
	void getChildren();	
};

