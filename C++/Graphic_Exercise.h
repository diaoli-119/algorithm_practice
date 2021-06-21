#pragma once

#define MAXVERTEX	10
#define MAXVEDGE	10

//struct edgeNode
//{
//	int adjNode;
//	edgeNode* next;
//};
//
//struct vertex
//{
//	int value;
//	edgeNode* beginEdge;
//};

class GraphicExercise
{
public:
	//for matrix
	GraphicExercise(int numVer)
	{
		_numVer = numVer;
		_numEdge = 0;
		for (int r = 0; r < MAXVERTEX; r++)
			for (int c = 0; c < MAXVERTEX; c++)
				_matrix[r][c] = 0;

		for (int i = 0; i < MAXVERTEX; i++)
		{
			_vertex[i] = i + 1;
			_visited[i] = 0;
		}
	}
	//for table
	/*GraphicExercise(int numVer, int numEdge)
	{

	}*/
	void createMatrix();
	void DFS(int vertIndex);
	void BFS(int vertIndex);

private:
	int _vertex[MAXVERTEX];
	int _matrix[MAXVERTEX][MAXVERTEX];
	int _numVer, _numEdge, _visited[MAXVERTEX];
};

