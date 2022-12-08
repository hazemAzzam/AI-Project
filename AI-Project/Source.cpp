#include<iostream>
#include<vector>
#include"Edge.h"
#include"Node.h"
#include"Map.h"
#include"Problem.h"
#include"Puzzle.h"
#include <omp.h>

using namespace std;
void traceBack(Edge* edge);
int main()
{
	// --- Start Map --- //
	/*Node* cairo = new Map("Cairo");
	Node* alex = new Map("Alex");
	Node* giza = new Map("Giza");
	Node* aswan = new Map("Aswan");
	Node* fayoum = new Map("fayoum");
	
	
	Edge::create(cairo, alex, 10);
	Edge::create(cairo, giza, 5);
	Edge::create(alex, aswan, 5);
	Edge::create(alex, giza, 10);
	Edge::create(giza, aswan, 5); 
	Edge::create(aswan, fayoum, 50);
	

	Problem problem(cairo, fayoum);*/
	// --- End Map --- //


	// --- Start Puzzle --- //
	vector<vector<int>> initial = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 0},
	};
	vector<vector<int>> goal = {
		{1, 7, 2},
		{4, 5, 3},
		{0, 8, 6},
	};

	Node* initialNode = new Puzzle(initial, goal);
	Node* goalNode = new Puzzle(goal, goal);


	Problem problem(initialNode, goalNode);
	// --- End Puzzle --- //

	double time1 = omp_get_wtime();
	Edge* solution = problem.PBFS();
	double time2 = omp_get_wtime();
	
	cout << "---------\n";

	traceBack(solution);
	cout << "Time:" << time2 - time1 << endl;
	return 0;
}
void traceBack(Edge* edge)
{
	int totalCost = 0;
	edge->child->print();

	while (edge != NULL) {
		cout << "<<" << endl;
		edge->parent->print();
		totalCost += edge->cost;

		edge = edge->prev;
	}
	
	cout << "Total Cost: " << totalCost << endl;
}
