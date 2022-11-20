#include "Problem.h"
#include"Map.h"
#include"Puzzle.h"
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

Edge* Problem::DFS()
{
    cout << "Check: \n"; initial->print();
    if (isGoal(initial))
        return new Edge(NULL, initial, 0, NULL);
    vector<Edge*> edges = initial->extract(NULL);
    vector<Node*> visited = { initial };
    cout << " it is not the goal, so extract its children, total is " << edges.size() << endl;
 
    int i = 0;
    for (Edge* edge = edges[i]; ; edge = edges[++i]) {
        cout << "Check: \n"; edge->child->print();
        if (find(visited, (edge->child))) {
           
            continue;
        }
        /*if (edge->child->visited) {
            cout << "VISITED BEFORE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
            continue;
        }*/
        if (isGoal(edge->child)) {
            return edge;
        } 
        edge->visited = true;
        visited.push_back(edge->child);
        vector<Edge*> newEdges = edge->child->extract(edge);

        edges.insert(edges.end(), newEdges.begin(), newEdges.end());
        cout << " it is not the goal, so extract its children, total is " << edges.size() << endl;
    }

    return nullptr;
}
