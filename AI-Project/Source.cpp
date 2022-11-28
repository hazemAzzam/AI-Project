#include<iostream>
#include<vector>
#include"Edge.h"
#include"Node.h"
#include"Map.h"
#include"Problem.h"
#include"Puzzle.h"

using namespace std;
void traceBack(Edge* edge);
int main()
{
	// --- Start Map --- //
	/*Node* cairo = new Map("Cairo");
	Node* alex = new Map("Alex");
	Node* giza = new Map("Giza");
	Node* aswan = new Map("Aswan");

	
	Edge::create(cairo, alex, 10);
	Edge::create(cairo, giza, 5);
	Edge::create(alex, aswan, 5);
	Edge::create(alex, giza, 10);
	Edge::create(giza, aswan, 5); 

	Problem problem(cairo, aswan);*/     
	// --- End Map --- //


	// --- Start Puzzle --- //
	vector<vector<int>> initial = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 0},
	};
	vector<vector<int>> goal = {
		{1, 0, 2},
		{4, 5, 3},
		{7, 8, 6},
	};

	Node* initialNode = new Puzzle(initial, goal);
	Node* goalNode = new Puzzle(goal, goal);


	Problem problem(initialNode, goalNode);
	// --- End Puzzle --- //

	Edge* solution = problem.BFS();
	cout << "---------\n";

	traceBack(solution);
	return 0;
}
void traceBack(Edge* edge)
{
	edge->child->print();
	int totalCost = 0;
	
	while (edge != NULL) {
		cout << "<<" << endl;
		edge->child->print();
		totalCost += edge->cost;

		edge = edge->prev;
	}
	
	cout << "Total Cost: " << totalCost << endl;
}
//void traceBack(Edge* edge)
//{
//	if (edge == NULL)
//		return;
//
//	traceBack(edge->prev);
//	cout << "From: " << endl;
//	edge->parent->print(); 
//	cout << "To: " << endl;
//	edge->parent->print();
//}
