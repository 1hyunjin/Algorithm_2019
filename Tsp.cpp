#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//21이 최소 경로
//cost 가 지금까지의 비용이고
//total_cost 가 최소비용

int D[4][4] = {0,2,9,100, 1,0,6,4, 100,7,0,8, 6,3,100,0};
bool visited[4] = {1,0,0,0}; //1,0,0,0
vector<int> path;

int TSP(vector<int> path, bool visited[], int cost){
	
	int total_cost  = 999999;
	int end;
	
	//path의 길이가 4가 될 때 지금까지의 비용과 마지막에서 0으로 다시 가는 비용 더해서 return.
	if(path.size() == 4){
		return cost + D[path.back()][0];
	}
	
	for(int i = 0; i < 4; i++){


		if(visited[i] == 1){
			continue;
		}
		
		visited[i] = 1;

		end = path.back();
		cost += D[end][i];
		path.push_back(i);
		//계속 비교하기
		total_cost = min(total_cost, TSP(path, visited, cost));
		
		//path 끝까지 오고나서 뒤로 다시 올라갈 때 cost에서 그 거리를 빼고 path 에서 마지막 경로를 0으로 바꾸고 path에서 뺸다.
		cost -= D[end][i];
		visited[path.back()]=0;
		path.pop_back();
	}
	return total_cost;
}

int main(){
	
	int cost = 0;
	path.push_back(0);
	cout << TSP(path,visited,cost);

}

