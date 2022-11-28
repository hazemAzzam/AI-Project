#include "Problem.h"
#include"Map.h"
#include"Puzzle.h"
#include<omp.h>
bool Problem::find(vector<Node*> vec, Node* node)
{
    for (auto i : vec) {
        if (i->compare(node))
            return true;
    }
    return false;
}
bool Problem::isGoal(Node* node)
{
    if (node->compare(goal))
        return true;
    /*if (node == goal)
        return true;*/
    return false;
}

vector<Edge*> Problem::extract(Node* node, Edge* prev)
{
    return node->extract(prev);
}

Edge* Problem::BFS()
{
    cout << "Check: \n"; initial->print();
    if (isGoal(initial))
        return new Edge(NULL, initial, 0, NULL);
    vector<Edge*> edges = initial->extract(NULL);
    vector<Node*> visited = { initial };
    cout << "   Not Found! Total Children Is " << edges.size() << endl;
    int i = 0;

    for (Edge* edge = edges[i]; /*hi*/ ; edge = edges[++i]) {
        cout << "Check: \n"; edge->child->print();

        if (find(visited, edge->child)) {
            cout << "   Skip! visited before!\n";
            continue;
        }

        if (isGoal(edge->child)) {
            cout << "   Found! After " << i << " Iterations" << endl;
            return edge;
        } 
        
        visited.push_back(edge->child);
        vector<Edge*> newEdges = edge->child->extract(edge);

        edges.insert(edges.end(), newEdges.begin(), newEdges.end());
        cout << "   Not Found! Total Children Is " << edges.size() << endl;
    }
    return nullptr;
}
bool found = false;
Edge* search(Problem* problem, Edge* edge)
{
    if (problem->isGoal(edge->child)) {
        edge->child->print();
        cout << "!!!!!!!!!Found!!!!!!!!!" << endl;
        found = true;
        return edge;
    }
    cout << "Not Found" << endl;
    vector<Edge*> children = edge->child->extract(edge);
    #pragma omp task
    {
        for (auto i : children)
            search(problem, i);
    }
}

Edge* Problem::PBFS()
{
    cout << "Check: \n"; initial->print();
    if (isGoal(initial))
        return new Edge(NULL, initial, 0, NULL);
    vector<Edge*> edges = initial->extract(NULL);
    vector<Node*> visited = { initial };
    cout << "   Not Found! Total Children Is " << edges.size() << endl;
    #pragma omp parallel num_threads(4)
    {
        Edge* solution = search(this, edges[0]);
        if (solution != NULL)
            return solution;
    }
}
