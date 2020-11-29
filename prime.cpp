#include<iostream>
using namespace std;
void accept(int G[7][7], int n, int e);
void prim(int G[7][7], int , int e);
int main() {
	int G[7][7], n, e;
	cin >> n >> e;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <n; j++) {
			G[i][j] = 0;
		}
	}
	accept(G,n,e);
	prim(G,n,e);
	return 0;
}
void accept(int G[7][7], int n, int e) {
	int start, final, cost;
	for (int i = 0; i < e; i++) {
		cin >> start >> final >> cost;
		G[start][final] = cost;
		G[final][start] = cost;
	}
}
void prim(int G[7][7], int n, int e) {
	int visited[7];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(G[i][j] == 0) {
				G[i][j] = 9999;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}
	int start, final;
	start = 0;
	int total = 0;
	visited[start] = 1;
	e = 0;
	while( e < n-1) {
		int min = 9999;
		for (int i = 0; i < n; i++) {
			if(visited[i] == 1) {
				for (int j = 0; j < n; j++) {
					if(visited[j] != 1) {
						if(min > G[i][j]) {
							min = G[i][j];
							start = i;
							final = j;
						}
					}
				}
			}
		}
		visited[final] = 1;
		total = total + G[start][final];
		cout << start << "--------" << final <<"\n";
		e++;
	}
}









