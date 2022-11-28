#include"Node.h"
#include"Edge.h"
using namespace std;


vector<Edge*> Node::extract(Edge* _prev)
{
	getChildren();
	for (auto child : children) {
		child->prev = _prev;
	}
	return children;
}

//vector<Edge*> Node::extract(Edge* _prev, Node* goal)
//{
//	getChildren(goal);
//	for (auto child : children) {
//		child->prev = _prev;
//	}
//	return children;
//}
