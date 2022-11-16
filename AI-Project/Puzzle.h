//#pragma once
//#include<iostream>
//#include<vector>
//#include"Node.h"
//
//using namespace std;
//
//struct Point
//{
//	int x, y;
//	Point(int _x, int _y) : x(_x), y(_y) { }
//	Point operator+(const Point p) {
//		return Point(x + p.x, y + p.y);
//	}
//	bool operator>=(const Point p) {
//		return x >= p.x || y >= p.y;
//	}
//	bool operator<(const Point p) {
//		return x < p.x || y < p.y;
//	}
//};
//
//class Puzzle : public Node
//{
//private:
//	bool isPossibleMove(Point point);
//	Puzzle* move(Point point);
//public:
//	int id;
//	int n = 3;
//	vector<vector<int>> puzzle;
//	Point pivot;
//	int id() {
//		return id;
//	}
//	void setId(int _id) {
//		id = _id;
//	}
//	//bool isEqual(Node* node) {
//	//	for (int i = 0; i < n; i++) {
//	//		for (int j = 0; j < n; j++) {
//	//			if (puzzle[i][j] != static_cast<Puzzle*>(node)->puzzle[i][j])
//	//				return false;
//	//		}
//	//	}
//	//	return true;
//	//}
//	void print() {
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				cout << puzzle[i][j] << " ";
//			}
//			cout << endl;
//		}
//		cout << "-----" << endl;
//	}
//	Puzzle(vector<vector<int>> _puzzle, Point _pivot) : puzzle(_puzzle), pivot(_pivot) { }
//	vector<Edge*> extract(Edge* _prev) {
//		vector<Edge*> children;
//		if (isPossibleMove({ 1, 0 })) {
//			Puzzle* newPuzzle = move({ 1, 0 });
//			Node::create(newPuzzle);
//			children.push_back(new Edge(this, newPuzzle));
//		}
//		if (isPossibleMove({ 0, 1 })) {
//			Puzzle* newPuzzle = move({ 0, 1 });
//			Node::create(newPuzzle);
//			children.push_back(new Edge(this, newPuzzle));
//		}
//		if (isPossibleMove({ -1, 0 })) {
//			Puzzle* newPuzzle = move({ -1, 0 });
//			Node::create(newPuzzle);
//			children.push_back(new Edge(this, newPuzzle));
//		}
//		if (isPossibleMove({ 0, -1 })) {
//			Puzzle* newPuzzle = move({ 0, -1 });
//			Node::create(newPuzzle);
//			children.push_back(new Edge(this, newPuzzle));
//		}
//		return children;
//	}
//};
//
