#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int main(){
	//정점의 개수
	int n;
	//간선의 개수
	int m;
	
	int start;
	
	cin >> n >> m >> start;
	
	vector <int> V[n+1];
	stack <int> S;

	int visit[n+1] = {0,};
	
	//양방향 그래프
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
	
	S.push(start);

	while(!S.empty()){
		
		int tmp = S.top();
		S.pop();
		if(visit[tmp]==0){

		cout << tmp << " ";
		}
		visit[tmp] = 1;
		
		
		while(V[tmp].size() > 0){
			
			if(visit[V[tmp].back()] == 1){
				V[tmp].pop_back();
				continue;
			}
			S.push(V[tmp].back());
			V[tmp].pop_back();
		}
	}
}
