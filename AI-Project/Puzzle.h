#pragma once
#include<iostream>
#include<vector>
#include"Node.h"

using namespace std;

struct Point
{
	int x, y;
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) { }
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
	vector<vector<int>> goal;
public:
	int cost = 0;
	int n = 3;
	vector<vector<int>> data;
	Point pivot;

	bool compare(Node* node);
	void print();
	Puzzle(vector<vector<int>> _puzzle, vector<vector<int>> _goal);

	void getChildren();	
};

