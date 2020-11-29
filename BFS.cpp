#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	//정점의 개수
	int n;
	//간선의 개수
	int m;

	int start;

	cin >> n >> m >> start;
	int visit[n+1] = {0,};
	vector<int> V[n+1];
	queue<int> q;
	//양방향 그래프
	for(int i = 1; i <= m; i++){
	 	int u,v;
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
		//그래프 정렬?
	for(int i=1; i<= n; i++){
		sort(V[i].begin(), V[i].end());
	}
	
	q.push(start);
	visit[start] = 1;
	
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
  		cout << tmp << " ";

		for(int i = 0; i < V[tmp].size(); i++){
			
			if(visit[V[tmp][i]] == 0){
				q.push(V[tmp][i]);
				visit[V[tmp][i]] = 1;
			}
		}
	}
}
