#include <iostream>
#include "Graphic_Exercise.h"
#include <queue>

using std::cout;
using std::endl;
using std::cin;

void GraphicExercise::createMatrix()
{
	int i, j;
	while(true)
	{
		cout << "input begin and end node of an edge:";
		cin >> i >> j;
		if ((_numEdge > MAXVEDGE) || (i < 0) || (j < 0)) break;
		_matrix[i][j] = 1;
		_numEdge++;
	}
}

void GraphicExercise::DFS(int vertIndex)
{
	_visited[vertIndex] = 1;
	cout << _vertex[vertIndex] << ' ';
	for (int i = 0; i < MAXVERTEX; i++)
	{
		if (_matrix[vertIndex][i] == 1 && _visited[i] == 0)
			DFS(i);
	}
}

void GraphicExercise::BFS(int vertIndex)
{
	_visited[vertIndex] = 1;
	std::queue<int> q;
	q.push(vertIndex);
	int front;
	int size = q.size();
	cout << _vertex[vertIndex] << ' ';
	while (size > 0)
	{
		for (int j = 0; j < size; j++)
		{
			front = q.front();
			q.pop();
			for (int i = 0; i < MAXVERTEX; i++)
			{
				if (_matrix[front][i] == 1 && _visited[i] == 0)
				{
					q.push(i);
					_visited[i] = 1;
					cout << _vertex[i] << ' ';\
				}
			}
		}
		size = q.size();
	}
}
