#include<iostream>
#include<vector>
#include <algorithm>
#include <cmath>
#include<map>
using namespace std;

//21이 최소 경로
//cost 가 지금까지의 비용이고
//total_cost 가 최소비용

// visited 지금 0111 -> -0번째 도시를 출발한거듸

int D[4][4] = {0,2,9,100, 1,0,6,4, 100,7,0,8, 6,3,100,0};
vector<int> path;
int array[4];
//map에 cost+D[path.back()][0]랑 path를 기억
map<int,vector<int> > s;

int TSP(vector<int> path, int visited, int cost){

	int total_cost  = 999999;
	int end;

	//path의 길이가 4가 될 때 지금까지의 비용과 마지막에서 0으로 다시 가는 비용 더해서 return.
	
	if(path.size() == 4){
		s.insert(make_pair(cost+ D[path.back()][0],path));
		return cost + D[path.back()][0];
	}

	for(int i = 0; i < 4; i++){

		if((visited & array[i]) == 0){
			continue;
		}

		visited = (visited ^ array[i]);

		end = path.back();
		cost += D[end][i];
		path.push_back(i);
		
		//계속 비교하기
		total_cost = min(total_cost, TSP(path, visited, cost));

		//path 끝까지 오고나서 뒤로 다시 올라갈 때 cost에서 그 거리를 빼고 path 에서 마지막 경로를 0으로 바꾸고 path에서 뺸다.
		cost -= D[end][i];
		
		visited = (visited | array[i]);
		
		path.pop_back();
	}
	return total_cost;
}

int main(){

	int cost = 0;
	path.push_back(0);
	//0111로 시작하니까 visitied 값은 7
	int visited = 7;
	//1000,0100,0010,0001
	for(int i=3;i>=0;i--){
		array[3-i] = pow(2,i);
	}
	int tmp =TSP(path,visited,cost);
	cout << tmp << endl;
	
	for(int i = 0; i < 4; i ++){
		cout << s[tmp][i] << " -> ";
	}
	cout<< "0"<<endl;
}

