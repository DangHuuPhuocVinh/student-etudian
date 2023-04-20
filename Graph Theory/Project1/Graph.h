#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <limits.h>
#include <algorithm>

using namespace std;

// cau truc bieu dien canh cua do thi
struct Edge {
	int vertex1, vertex2;
	int weight;
};

struct Vertex {
	int distance;
	int previousVertex;
};

struct NODE {
	int data;
	NODE* pNext;
};

// Cau truc bieu dien mot do thi
struct Graph
{
	int nVertices;		// so dinh
	int nEdges;			// so canh
	int directed;		// do thi co huong hay vo huong
	int **adjMatrix;	// ma tran ke (cap phat dong)
};

// Ham tao do thi tu file van ban chua ma tran ke
// Tham so:
//   - g: chua do thi tao tu file
//   - fname: ten file van ban cua ma tran ke
// Tra ve: 1 neu tao duoc do thi, 0 neu nguoc lai
int loadGraphFromAdjMatrixFile(Graph &g, const char* fname);

// Ham giai phong bo nho cua do thi (khi khong dung do thi nua)
// Tham so: 
//   - g: chua do thi can giai phong (giai phong adjMatrix cua g)
void deleteGraph(Graph &g);

// Ham xuat mot vai thong tin cua do thi
// Tham so: 
//   - g: chua do thi can xuat thong tin
void printGraph(const Graph &g);

int loadGraphFromAdjListFile(Graph &g, const char* fname);

//-----------------------------------------------------------------------------
void DFS(Graph g, int vertex, bool *label);

void DFS(Graph g, int vertex);

void connectedComponents(Graph g);

void BFS(Graph g, int vertex);

void BFS(Graph g, int vertex, bool* label);

//bool* bfs(Graph g, int vertex);

bool reachable(Graph g, int vertex1, int vertex2);

bool isConnected(Graph g);

void connectedComponents(Graph g);

void PrimsAlgo(Graph g);

Edge* Sort(Graph g);

void KruskalAlgo(Graph g);

void BellmanFord(Graph g, int startVertex, int endVertex);

void PrintPath(Vertex *table, int vertex1, int vertex2);

void Dijsktra(Graph g, int startVertex, int endVertex);

int Eulerian(Graph g);

void EulerPath(Graph g);
