#include<iostream>
#include<vector>
#include <algorithm>
#include <cmath>
#include<map>
using namespace std;

//21�� �ּ� ���
//cost �� ���ݱ����� ����̰�
//total_cost �� �ּҺ��

// visited ���� 0111 -> -0��° ���ø� ����Ѱŵ�

int D[4][4] = {0,2,9,100, 1,0,6,4, 100,7,0,8, 6,3,100,0};
vector<int> path;
int array[4];
//map�� cost+D[path.back()][0]�� path�� ���
map<int,vector<int> > s;

int TSP(vector<int> path, int visited, int cost){

	int total_cost  = 999999;
	int end;

	//path�� ���̰� 4�� �� �� ���ݱ����� ���� ���������� 0���� �ٽ� ���� ��� ���ؼ� return.
	
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
		
		//��� ���ϱ�
		total_cost = min(total_cost, TSP(path, visited, cost));

		//path ������ ������ �ڷ� �ٽ� �ö� �� cost���� �� �Ÿ��� ���� path ���� ������ ��θ� 0���� �ٲٰ� path���� �A��.
		cost -= D[end][i];
		
		visited = (visited | array[i]);
		
		path.pop_back();
	}
	return total_cost;
}

int main(){

	int cost = 0;
	path.push_back(0);
	//0111�� �����ϴϱ� visitied ���� 7
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

