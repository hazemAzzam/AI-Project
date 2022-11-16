#include<iostream>
#include<vector>
#include"Edge.h"
#include"Node.h"
#include"Map.h"
#include"Problem.h"


using namespace std;
void traceBack(Edge* edge);
int main()
{
	Node* cairo = new Map("Cairo");
	Node* alex = new Map("Alex");
	Node* giza = new Map("Giza");
	Node* aswan = new Map("Aswan");

	
	Edge::create(cairo, alex, 10);
	Edge::create(cairo, giza, 5);
	Edge::create(alex, aswan, 5);
	Edge::create(alex, giza, 10);
	Edge::create(giza, aswan, 5);

	Problem problem(cairo, aswan);


	//vector<vector<int>> initial = {
	//	{1, 2, 3},
	//	{4, 5, 6},
	//	{7, 8, 0},
	//};
	//vector<vector<int>> goal = {
	//	{1, 2, 3},
	//	{4, 5, 6},
	//	{7, 0, 8},
	//};
	//Node* initialNode = new Puzzle(initial, Point(2, 2));
	//Node* goalNode = new Puzzle(goal, Point(2, 1));
	///*Node::create(initialNode);
	//Node::create(goalNode);*/
	//Problem problem(initialNode, goalNode);
	Edge* solution = problem.DFS();

	traceBack(solution);
	return 0;
}

void traceBack(Edge* edge)
{
	if (edge == NULL)
		return;
	traceBack(edge->prev);
	cout << static_cast<Map*>(edge->parent)->name << " -> " << static_cast<Map*>(edge->child)->name << endl;
}
