#include "Graph.h"

// Ham tao do thi tu file van ban chua ma tran ke
// Gia su file co noi dung hop le va du bo nho cap phat dong
int loadGraphFromAdjMatrixFile(Graph &g, const char* fname) {
	FILE *f = fopen(fname, "r");
	if (f == NULL)
		return 0;	// khong mo duoc file

	// Doc so dinh cua do thi
	fscanf(f, "%d", &g.nVertices);

	// Cap phat dong ma tran ke
	g.adjMatrix = new int*[g.nVertices];
	for (int i = 0; i < g.nVertices; i++)
		g.adjMatrix[i] = new int[g.nVertices];

	// Doc ma tran ke
	for (int i = 0; i < g.nVertices; i++)
		for (int j = 0; j < g.nVertices; j++)
			fscanf(f, "%d", &g.adjMatrix[i][j]);

	fclose(f);

	// kt do thi co huong hay vo huong
	g.directed = 0;
	for (int i = 0; i < g.nVertices; i++)
		for (int j = 0; j < g.nVertices; j++) {
			if (g.adjMatrix[i][j] != g.adjMatrix[j][i])
				g.directed = 1;
		}

	// Dem so canh
	g.nEdges = 0;
	for (int i = 0; i < g.nVertices; i++)
		for (int j = i; j < g.nVertices; j++)
			if (g.adjMatrix[i][j])
				g.nEdges++;

	return 1;
}

int loadGraphFromAdjListFile(Graph &g, const char* fname) {
	FILE *f = fopen(fname, "r");
	if (f == NULL)
		return 0;	// khong mo duoc file

	// Doc so dinh cua do thi
	fscanf(f, "%d", &g.nVertices);

	// Cap phat dong danh sach ke
	g.adjMatrix = new int*[g.nVertices];
	for (int i = 0; i < g.nVertices; i++)
		g.adjMatrix[i] = new int[g.nVertices];

	// Gan gia tri mac dinh cho du lieu danh sach = 0
	for (int i = 0; i < g.nVertices; i++) {
		for (int j = 0; j < g.nVertices; j++) {
			g.adjMatrix[i][j] = 0;
		}
	}

	// Doc danh sach ke va dem so canh
	int VertexNum;	// So dinh lien ket 

	int data;

	g.nEdges = 0;
	for (int i = 0; i < g.nVertices; i++) {
		fscanf(f, "%d", &VertexNum);
		g.nEdges += VertexNum;	// Dem so canh 
		for (int j = 0; j < VertexNum; j++) {
			fscanf(f, "%d", &data);
			g.adjMatrix[i][data] = 1;
		}
	}

	fclose(f);

	g.directed = 0;
	for (int i = 0; i < g.nVertices; i++)
		for (int j = 0; j < g.nVertices; j++) {
			if (g.adjMatrix[i][j] != g.adjMatrix[j][i])
				g.directed = 1;
		}

	return 1;
}

// Ham giai phong bo nho cua do thi (khi khong dung do thi nua)
void deleteGraph(Graph &g) {
	// Giai phong bo nho dong da cap phat cho adjMatrix
	for (int i = 0; i < g.nVertices; i++)
		delete[] g.adjMatrix[i];
	delete[] g.adjMatrix;
	g.adjMatrix = NULL;
}

// Ham xuat mot vai thong tin cua do thi
void printGraph(const Graph &g) {
	if (g.directed)
		cout << "Do thi co huong\n";
	else
		cout << "Do thi vo huong\n";
	
	cout << "So dinh: " << g.nVertices << endl;
	cout << "So canh: " << g.nEdges << endl;
	

	for (int i = 0; i < g.nVertices; i++) {
		for (int j = 0; j < g.nVertices; j++)
			cout << g.adjMatrix[i][j] << "  ";

		cout << endl;
	}
}

void DFS(Graph g, int vertex, bool *label) {
	label[vertex] = true;	//  gan nhan cho dinh da vieng

	cout << vertex << " ";

	for (int i = 0; i < g.nVertices; i++)
		for (int j = 0; j < g.nVertices; j++)
			if (g.adjMatrix[i][j] && label[j] == 0)			//  tim dinh tiep theo cua dinh i va dan nhan cho no
				DFS(g, j, label);
}

// ham nay duyet de in trong ham main
void BFS(Graph g, int vertex) {
	bool *label = new bool[g.nVertices];		// tao nhan de danh dau cac dinh da vieng

	//	Gan tat ca cac dinh co nhan false
	for (int i = 0; i < g.nVertices; i++)
		label[i] = false;

	queue <int> q;	// tao queue

	q.push(vertex);			// dua dinh lam moc vao queue
	label[vertex] = true;	// dan nhan cho dinh da vieng

	while (q.empty() != 1) {
		int temp = q.front();		// gan vi tri cua dinh dang vieng vao bien tam
		//cout << temp << " ";
		q.pop();	// lay dinh da vieng ra khoi queue 

		// tim cac dinh ke cua dinh da vieng
		// neu co dinh chua vieng thi dua dinh do vao queue
		// va danh dau da vieng cho dinh do
		for (int i = 0; i < g.nVertices; i++)
			if (g.adjMatrix[temp][i] && label[i] == false) {
				cout << temp << " - " << i << endl;
				q.push(i);
				label[i] = true;
			}
	}
	delete[]label;
}

// in trong ham main
void DFS(Graph g, int vertex) {
	// tao nhan de danh dau cac dinh da vieng
	bool *label = new bool[g.nVertices];

	for (int i = 0; i < g.nVertices; i++)
		label[i] = false;

	stack <int> s;

	// dua dinh duoc chon lam dinh bat dau vao stack
	// danh dau la da vieng
	s.push(vertex);
	label[vertex] = true;

	while (s.empty() != 1) {
		int temp = s.top(); // luu lai dinh da vieng 
		s.pop(); // lay dinh da vieng ra khoi stack

		// neu dinh da vieng ke voi 1 dinh chua duoc vieng
		// thi bo dinh do vao stack
		// danh dau la da vieng va cap nhat dinh
		for (int i = 0; i < g.nVertices; i++) {
			if (g.adjMatrix[temp][i] && label[i] == false) {
				cout << temp << " - " << i << endl;
				s.push(i);
				label[i] = true;
				temp = i;
			}
		}
	}
}

// duyet de lam cac ham khac
void BFS(Graph g, int vertex, bool* label) {
//	bool *label = new bool[g.nVertices];		// tao nhan de danh dau cac dinh da vieng

	//	Gan tat ca cac dinh co nhan false
	for (int i = 0; i < g.nVertices; i++)
		label[i] = false;

	queue <int> q;	// tao queue

	q.push(vertex);			// dua dinh lam moc vao queue
	label[vertex] = true;	// dan nhan cho dinh da vieng

	while (q.empty() != 1) {
		int temp = q.front();		// gan vi tri cua dinh dang vieng vao bien tam
		q.pop();	// lay dinh da vieng ra khoi queue 

		// tim cac dinh ke cua dinh da vieng
		// neu co dinh chua vieng thi dua dinh do vao queue
		// va danh dau da vieng cho dinh do
		for (int i = 0; i < g.nVertices; i++)
			if (g.adjMatrix[temp][i] && label[i] == false) {
				q.push(i);
				label[i] = true;
			}
	}
	//return label;
}

bool reachable(Graph g, int vertex1, int vertex2) {
	bool *label = new bool[g.nVertices];
	// Duyet tu dinh thu 1 den het do thi
	//label = bfs(g, vertex1);

	BFS(g, vertex1, label);

	// kiem tra nhan xem da vieng dinh thu 2 hay chua
	if (label[vertex2] == false) {
		delete[]label;
		return false;
	}

	delete[]label;
	return true;
}

bool isConnected(Graph g) {
	int count = 0;
	bool *label = new bool[g.nVertices];
	
	BFS(g, 0, label);

	for (int i = 0; i < g.nVertices; i++)
		if (label[i] == true)
			count++;

	delete[]label;

	if (count == g.nVertices)
		return true;

	return false;
}

void connectedComponents(Graph g) {
	bool *label = new bool[g.nVertices];		// tao nhan de danh dau cac dinh da vieng

	//	Gan tat ca cac dinh co nhan false
	for (int i = 0; i < g.nVertices; i++)
		label[i] = false;

	//	kiem tra nhan xem con thanh phan lien thong tren do thi
	for (int i = 0; i < g.nVertices; i++)
		if (label[i] == false) {
			cout << endl;
			DFS(g, i, label);
		}

	delete[]label;
}

void PrimsAlgo(Graph g) {
	bool *label = new bool[g.nVertices];	// tao nhan de danh dau dinh da duoc chon	

	for (int i = 0; i < g.nVertices; i++)
		label[i] = false;

	cout << "Edge" << " : " << " Edge's weight";
	cout << endl;

	int SelectedEdge = 0, x, y;

	label[0] = true; // chon dinh bat ki lam dinh bat dau 
	int TotalWeight = 0;

	// thuat toan dung khi da chon du n - 1 canh
	while (SelectedEdge < g.nVertices - 1) {
		int min = INT_MAX;
		x = 0;
		y = 0;

		// tu dinh da duoc chon tim ra canh noi voi 1 dinh chua duoc chon
		// co canh noi co trong so nho nhat
		for (int i = 0; i < g.nVertices; i++) 
			if(label[i]) 
				for(int j = 0; j < g.nVertices; j++)
					if(!label[j] && g.adjMatrix[i][j] != 0)
						if (min > g.adjMatrix[i][j]) {
							min = g.adjMatrix[i][j];
							x = i; // luu dinh duoc chon vao bien tam
							y = j; // luu dinh chua duoc chon vao bien tam
						}

		cout << x << " - " << y << "  :  " << g.adjMatrix[x][y];
		cout << endl;
		TotalWeight += g.adjMatrix[x][y];
		label[y] = true;
		SelectedEdge++;
	}

	cout << "Trong so cay khung: " << TotalWeight << endl;
}

void Swap(Edge &a, Edge &b) {
	Edge t = a;

	a = b;
	b = t;
}

void SelectionSort(Edge *a, int n) {
	int i = 0;

	while (i < n) {
		int position = i;

		for (int j = i + 1; j < n; j++)	
			if (a[j].weight < a[position].weight)
				position = j;

		Swap(a[i], a[position]);
		i++;
	}
}

Edge* Sort(Graph g) {
	// khoi tao bang de luu canh cua do thi
	Edge* table = new Edge[g.nEdges];
	int i = 0;
	// luu tat ca canh cua do thi vao bang
	while(i < g.nEdges) {
		for (int j = 0; j < g.nVertices; j++)
			for (int k = j; k < g.nVertices; k++)
				if (g.adjMatrix[j][k]) {
					table[i].vertex1 = j;
					table[i].vertex2 = k;
					table[i].weight = g.adjMatrix[j][k];
					i++;
				}
	}

	// sap xep lai bang theo thu tu trong so tang dan
	SelectionSort(table, g.nEdges);

	return table;
}

void UpdateLabel(int v1, int v2, int *label) {
	if (v1 > v2)
		label[v1] = label[v2];
	else
		label[v2] = label[v1];
}

void KruskalAlgo(Graph g) {
	// bien label duoc dung de kiem tra canh duoc chon co tao
	// chu trinh hay khong
	int *label = new int[g.nVertices];

	// danh nhan tung dinh
	// mac dinh la dinh i co nhan la i
	for (int i = 0; i < g.nVertices; i++)
		label[i] = i;

	// chua bang cac canh da duoc sap xep theo thu tu trong so tang dan
	Edge *table = new Edge[g.nEdges];
	// sap xep canh theo thu tu trong so tang dan
	// va dua vao bang
	table = Sort(g);

	// khoi tao cay T rong
	Edge *T = new Edge[g.nVertices - 1];

	// duyet theo canh e thuoc bang da sap xep
	// neu them canh e khong lam cho cay T co chu trinh
	// thi bo e vao T
	int j = 0;
	for (int i = 0; i < g.nEdges; i++) {
		Edge e = table[i];
		int v1 = e.vertex1, v2 = e.vertex2;
		// kiem tra nhan de biet khi them e co tao chu trinh hay khong 
		// neu nhan v1 giong nhan v2 nghia la canh them vao tao chu trinh cho T
		// moi lan them canh e vao T ta cap nhat lai nhan
		// nhan cua dinh co index lon thanh nhan cua dinh co index nho hon
		if (label[v1] != label[v2]) {
			T[j] = e;
			j++;
			UpdateLabel(v1, v2, label);
		}
		// thuat toan dung khi T du so dinh - 1 phan tu
		if (j == g.nVertices - 1)
			break;
	}

	// xuat cay khung nho nhat
	int TotalWeight = 0;
	for (int i = 0; i < g.nVertices - 1; i++) {
		cout << T[i].vertex1 << " - " << T[i].vertex2 << ": " << T[i].weight << endl;
		TotalWeight += T[i].weight;
	}

	cout << "Trong so cay khung: " << TotalWeight << endl;
}

bool compare(Vertex *a, Vertex *b, Graph g) {
	for (int i = 0; i < g.nVertices; i++)
		if (a[i].distance != b[i].distance)
			return false;
	return true;
}

void PrintPath(Vertex *table, int vertex1, int vertex2) {
	if (vertex2 == vertex1)
		cout << vertex1;
	else {
		int temp = table[vertex2].previousVertex;
		PrintPath(table, vertex1, temp);
		cout << "-->" << vertex2;
	}
}

void BellmanFord(Graph g, int startVertex, int endVertex) {
	Vertex *table = new Vertex[g.nVertices];

	// khoi tao bang luu thong tin cua cua cac dinh bao gom dinh lien truoc va 
	// khoang cach tu startVertex den dinh hien tai
	// mac dinh cac dinh khac startVertex co duong di tu startVertex
	// den chinh no co khoang cach rat lon
	for (int i = 0; i < g.nVertices; i++) {
		table[i].distance = 999;
		table[i].previousVertex = -1;
	}
	// startVertex co khoang cach tu no den chinh no va
	// khong co dinh lien truoc
	table[startVertex].distance = 0;

	// tao them mot bang de luu thong tin sau moi lan cap nhat bang
	Vertex *UpdatedTable = new Vertex[g.nVertices];
	int k = 0;
	bool flag = 0;

	// tai moi thoi diem kiem tra dinh u tren bang roi do tren ma tran ke xem
	// dinh u co dan den dinh v nao khong
	// neu co va khoang cach tu u den v + khoang cach tu startVertex den v nho hon 
	// khoang cach tu startVertex den v thi cap nhat lai bang 
	while (k <= g.nVertices) {
		for (int i = 0; i < g.nVertices; i++) {
			UpdatedTable[i] = table[i];
			for (int j = 0; j < g.nVertices; j++)
				if (g.adjMatrix[j][i] != 0) {
					Vertex temp;
					temp.distance = table[j].distance + g.adjMatrix[j][i];
					temp.previousVertex = j;
					if (temp.distance < UpdatedTable[i].distance) {
						UpdatedTable[i] = temp;
						// so sanh bang vua cap nhat voi bang cu xem co giong nhau khong
						// neu giong thi thuat toan ket thuc do da tim duoc duong di ngan nhat
						// tu u den v
						if (compare(UpdatedTable, table, g)) {
							flag = 1;
							break;
						}
						table[i] = UpdatedTable[i];
					}
				}
		}
		if (flag == 1)
			break;
		k++;
	}
	if (k == g.nVertices)
		cout << "Dinh chu trinh am!" << endl;
	else 
		PrintPath(UpdatedTable, startVertex, endVertex);
}

bool hasNegativeEdge(Graph g) {
	for (int i = 0; i < g.nVertices; i++)
		for (int j = 0; j < g.nVertices; j++)
			if (g.adjMatrix[i][j] < 0)
				return true;
	return false;
}

int FindVertex(Graph g, bool * BelongT, Vertex *table) {
	int min = 999, v;

	for (int i = 0; i < g.nVertices; i++) {
		if (table[i].distance < min && BelongT[i]) {
			min = table[i].distance;
			v = i;
		}
	}

	return v;
}

void Dijsktra(Graph g, int startVertex, int endVertex) {
	if (hasNegativeEdge(g))
		cout << "Do thi khong hop le!" << endl;
	else {
		Vertex *table = new Vertex[g.nVertices]; 
		bool *BelongT = new bool[g.nVertices];			// mang nay thong bao dinh v co bi loai khoi table hay chua

		// khoi tao bang luu thong tin cua cua cac dinh bao gom ten dinh lien truoc va 
		// khoang cach tu startVertex den dinh hien tai
		// mac dinh cac dinh khac startVertex co duong di tu startVertex
		// den chinh no co khoang cach rat lon
		for (int i = 0; i < g.nVertices; i++) {
			table[i].distance = 999;
			table[i].previousVertex = -1;
			BelongT[i] = true;
		}
		// startVertex co khoang cach tu no den chinh no va
		// khong co dinh lien truoc
		table[startVertex].distance = 0;

		// tai moi lan lap ta do trong bang table de tim ra dinh v co khoang cach
		// tu v den startVertex la nho nhat
		// loai v ra khoi table bang cach tat nhan BelongT tai v
		for (int i = 0; i < g.nVertices; i++) {
			int v = FindVertex(g, BelongT, table);
			BelongT[v] = false;
			// voi moi dinh j trong table va co canh noi tu v den j
			// neu duong di startVertex den v + khoang canh v toi j < khoang cach
			// duoc luu trng table thi cap nhat lai table
			for (int j = 0; j < g.nVertices; j++)
				if (BelongT[j] && g.adjMatrix[v][j]) {
					int dist = table[v].distance + g.adjMatrix[v][j];
					if (table[j].distance == 999 || table[j].distance > dist) {
						table[j].distance = dist;
						table[j].previousVertex = v;
					}
				}
		}
		PrintPath(table, startVertex, endVertex);
	}
}

NODE* Createnode(int data) {
	NODE* p = new NODE;

	p->data = data;
	p->pNext = NULL;

	return p;
}

void AddHead(NODE* &pHead, int data) {
	NODE* p = Createnode(data);

	if (pHead == NULL) {
		pHead = p;
		return;
	}

	p->pNext = pHead;
	pHead = p;
}

void PrintList(NODE* pHead) {
	NODE* temp = pHead;

	while (temp != NULL) {
		cout << " --> " << temp->data;
		temp = temp->pNext;
	}
}

int Eulerian(Graph g) {
	if (isConnected(g)) {
		int countOnLine = 0, count = 0;

		for (int i = 0; i < g.nVertices; i++) {
			for (int j = 0; j < g.nVertices; j++)
				if (g.adjMatrix[i][j] != 0)
					countOnLine++;
			if (countOnLine % 2 != 0)
				count++;
		}
		if (count == 0)
			return 0;	// co chu trinh Euler
		else if (count == 2)
			return 1;	// co duong di Euler
	}

	return -1;	// khong co duong di Euler
}

void EulerPath(Graph g) {
	if (Eulerian(g) < 0) {
		cout << "Khong co duong di Euler!" << endl;
		return;
	}
	else {
		stack<int> s;
		NODE *LinkedList = NULL;

		// neu do thi co chu trinh euler chon dinh dau tien bo vao stack
		if (Eulerian(g) == 0) {
			s.push(0);
			cout << "0";
		}
		// neu do thi co duong di euler chon 1 dinh co bac le bo vao stack
		else if (Eulerian(g) == 1) 
			for (int i = 0; i < g.nVertices; i++) {
				int countOnLine = 0;

				for (int j = i; j < g.nVertices; j++)
					if (g.adjMatrix[i][j] != 0)
						countOnLine++;
				if (countOnLine % 2 != 0) {
					s.push(i);
					cout << i;
					break;
				}
			}
		
		while (!s.empty()) {
			// lay dinh tren cung cua stack lam dinh dang xet
			int temp = s.top();
			bool hasNeighbor = false;
			// tim xem dinh dang xe co dinh lan can khong 
			// neu co thi bo vao stack va xoa canh giua 2 dinh do 
			for(int i = 0; i < g.nVertices; i++)
				if (g.adjMatrix[temp][i] != 0) {
					g.adjMatrix[temp][i]--;
					g.adjMatrix[i][temp]--;
					s.push(i);
					hasNeighbor = true;
					break;
				}
			// neu dinh dang xet khong co dinh lan can thi pop ra khoi stack
			if (!hasNeighbor) {
				int temp1 = s.top();
				s.pop();
				if (s.empty())
					break;
				AddHead(LinkedList, temp1);
			}
		}
		// luu dau vet sau moi lan duyet vao danh sach lien ket roi in ra
		PrintList(LinkedList);
	}
}