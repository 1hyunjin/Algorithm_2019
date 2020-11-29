#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//21�� �ּ� ���
//cost �� ���ݱ����� ����̰�
//total_cost �� �ּҺ��

int D[4][4] = {0,2,9,100, 1,0,6,4, 100,7,0,8, 6,3,100,0};
bool visited[4] = {1,0,0,0}; //1,0,0,0
vector<int> path;

int TSP(vector<int> path, bool visited[], int cost){
	
	int total_cost  = 999999;
	int end;
	
	//path�� ���̰� 4�� �� �� ���ݱ����� ���� ���������� 0���� �ٽ� ���� ��� ���ؼ� return.
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
		//��� ���ϱ�
		total_cost = min(total_cost, TSP(path, visited, cost));
		
		//path ������ ������ �ڷ� �ٽ� �ö� �� cost���� �� �Ÿ��� ���� path ���� ������ ��θ� 0���� �ٲٰ� path���� �A��.
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

