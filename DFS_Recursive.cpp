#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

void dfs(int n, int m , int start);
int visit[1001]={0,};
vector<int> V[1001];

//void dfs(int start){
void dfs(int start){
	
	if(visit[start]){
		return;
	}
	visit[start] = 1;
	cout << start << " ";
	for(int i = 0; i < V[start].size(); i++){
		int tmp = V[start][i];
		dfs(tmp);
	}
}
int main(){
	
	int n;
	//간선의 개수
	int m;

	int start;

	cin >> n >> m >> start;

	for(int i = 0; i < m; i++){
	 	int u,v;
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}

	//그래프 정렬?
	for(int i=1; i<= n; i++){
		sort(V[i].begin(), V[i].end());
	}
	
	dfs(start);
}
