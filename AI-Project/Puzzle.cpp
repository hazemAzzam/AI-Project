//#include "Puzzle.h"
//
//
//bool Puzzle::isPossibleMove(Point point)
//{
//	Point oldPivot = pivot;
//	Point newPivot = pivot + point;
//	if (newPivot >= Point(3, 3) || newPivot < Point(0, 0))
//		return false;
//	return true;
//}
//Puzzle* Puzzle::move(Point point)
//{
//	Point newPivot = pivot + point;
//	vector<vector<int>> newPuzzle = puzzle;
//	int temp = newPuzzle[newPivot.x][newPivot.y];
//	newPuzzle[newPivot.x][newPivot.y] = newPuzzle[pivot.x][pivot.y];
//	newPuzzle[pivot.x][pivot.y] = temp;
//	return new Puzzle(newPuzzle, newPivot);
//}