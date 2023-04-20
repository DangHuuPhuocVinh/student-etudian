#include "Graph.h"

int main() {
	Graph g, DuLieuDSKe;
	char fname[] = "graph7.txt";	// ten file van ban chua ma tran ke cua do thi

	if (loadGraphFromAdjMatrixFile(g, fname)) {
		printGraph(g);	// xuat mot vai thong tin cua g

		bool Connected = isConnected(g);

		if (Connected == false)
			cout << "Do thi khong lien thong" << endl;
		else
			cout << "Do thi lien thong" << endl;

		cout << "Cay khung dfs: " << endl;
		DFS(g, 0);
		cout << endl;
		cout << "Cay khung bfs: " << endl;
		BFS(g, 0);
		cout << endl;
		cout << "Prim: " << endl;
		PrimsAlgo(g);
		cout << "Kruskal: " << endl;
		KruskalAlgo(g);

		/*cout << endl << "Duong di ngan nhat tu dinh 0 den 5 bang thuat toan Bellman Ford: " << endl;
		BellmanFord(g, 0, 5);
		cout << endl;

		cout << endl << "Duong di ngan nhat tu dinh 0 den 5 bang thuat toan Dijsktra: " << endl;
		Dijsktra(g, 0, 5);
		cout << endl;*/

		//cout << Eulerian(g) << endl;
		cout << endl << "Duong di euler: ";
		EulerPath(g);
		cout << endl;

		deleteGraph(g);	// giai phong bo nho dong g giu
	}
	else
		printf("Khong tao duoc do thi!");

	cout << endl;

	system("pause");

	_getch;

	return 0;
}
