#include "Problem.h"
#include"Map.h"
#include"Puzzle.h"

#include<omp.h>
#include<stack>
using namespace std;
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
    vector<Edge*> fringe = initial->extract(NULL);
    vector<Node*> visited = { initial };
    cout << "   Not Found! Fringe Space Is " << fringe.size() << endl;
    int i = 0;

    for (Edge* edge = fringe[i]; /*hi*/ ; edge = fringe[++i]) {
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
        vector<Edge*> children = edge->child->extract(edge);

        fringe.insert(fringe.end(), children.begin(), children.end());
        cout << "   Not Found! Fringe Space Is " << fringe.size() << endl;
    }
    return nullptr;
}
bool found = false;

void assignStack(stack<Edge*>* s, vector<Edge*> e) {
    for (auto i : e) {
        (*s).push(i);
    }
}

Edge* Problem::PBFS()
{
    /*int num = 2;
    cout << "Threads: "; cin >> num;*/
    //cout << "Check: \n"; initial->print();
    if (isGoal(initial))
        return new Edge(NULL, initial, 0, NULL);
    vector<Edge*> fringe = initial->extract(NULL);
    vector<Node*> visited = { initial };
    //cout << "   Not Found! Fringe Space Is " << fringe.size() << endl;
    int i = 0;
    Edge* solution = NULL;
    
    while(true)
    {
        if (solution != NULL)
            return solution;
        
        #pragma omp parallel num_threads(5)
        {
            #pragma omp task 
            {
                int j;
                #pragma omp critical
                {
                    cout << "#" << omp_get_thread_num() << " grapping i" << endl;
                    i++;
                    j = i - 1;
                    cout << "#" << omp_get_thread_num() << " grapped " << j << endl;
                }

                Edge* edge;

                while (j >= fringe.size());
                cout << j << " / " << fringe.size() << endl;
                edge = fringe[j];         
                
                
                //cout << "#" << omp_get_thread_num() << endl;
                
                
                //cout << " Check: \n"; edge->child->print();
#pragma omp critical
                {
                    if (!find(visited, edge->child)) {
                        if (isGoal(edge->child)) {
                            //      cout << "   Found! After " << j << " Iterations" << endl;
                            solution = edge;
                        }
//#pragma omp critical
//                        {
                            //    cout << "Visited " << visited.size() << endl;
                            visited.reserve(visited.size());
                            visited.push_back(edge->child);
                        //}
                        vector<Edge*> children = edge->child->extract(edge);
//#pragma omp critical
//                        {
                            fringe.reserve(fringe.size() + children.size() - 1);
                            fringe.insert(fringe.end(), children.begin(), children.end());
                            //cout << "   Not Found! Fringe Space Is " << fringe.size() << endl;
                        //}
                    }
                }
            }
        }
    }
    return nullptr;
}
