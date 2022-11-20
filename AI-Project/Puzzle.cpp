#include "Puzzle.h"
//
//
bool Puzzle::isPossibleMove(Point point)
{
	Point oldPivot = pivot;
	Point newPivot = pivot + point;
	if (newPivot >= Point(3, 3) || newPivot < Point(0, 0))
		return false;
	return true;
}
Puzzle* Puzzle::move(Point point)
{
	Point newPivot = pivot + point;
	vector<vector<int>> newPuzzle = data;
	int temp = newPuzzle[newPivot.x][newPivot.y];
	newPuzzle[newPivot.x][newPivot.y] = newPuzzle[pivot.x][pivot.y];
	newPuzzle[pivot.x][pivot.y] = temp;
	return new Puzzle(newPuzzle, newPivot);
}

bool Puzzle::compare(Node* node)
{
	vector<vector<int>> temp = static_cast<Puzzle*>(node)->data;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (data[i][j] != temp[i][j])
				return false;
		}
	}
	return true;
}

void Puzzle::print()
{
	for (int i = 0; i < n; i++) {
		cout << "|";
		for (int j = 0; j < n; j++) {
			cout << data[i][j] << " ";
		}
		cout << "|";
		cout << endl;
	}

}

void Puzzle::getChildren()
{
	if (isPossibleMove(Point(1, 0))) {
		Puzzle* newPuzzle = move({ 1, 0 });
		Node* node = new Puzzle(newPuzzle->data, newPuzzle->pivot);
		children.push_back(new Edge(this, newPuzzle));
	}
	if (isPossibleMove({ 0, 1 })) {
		Puzzle* newPuzzle = move({ 0, 1 });
		Node* node = new Puzzle(newPuzzle->data, newPuzzle->pivot);
		children.push_back(new Edge(this, newPuzzle));
	}
	if (isPossibleMove({ -1, 0 })) {
		Puzzle* newPuzzle = move({ -1, 0 });
		Node* node = new Puzzle(newPuzzle->data, newPuzzle->pivot);
		children.push_back(new Edge(this, newPuzzle));
	}
	if (isPossibleMove({ 0, -1 })) {
		Puzzle* newPuzzle = move({ 0, -1 });
		Node* node = new Puzzle(newPuzzle->data, newPuzzle->pivot);
		children.push_back(new Edge(this, newPuzzle));
	}
}

