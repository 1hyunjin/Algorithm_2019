#include<iostream>
#include<utility>
#include<vector>
#include<string>

using namespace std;
//가장 무게가 많이 나가는 것부터
string name[4] = {"jesse","maybel","callie","maggie"};
int weight[4] = {6,3,2,5};


int main(){

	int ship_w = 10;
	int n = 4;

	for(int i = 0; i < n; i++){
			int min = i;
			for(int j = i+1; j < n; j++){
				if(weight[min] < weight[j]){
					swap(name[min],name[j]);
					swap(weight[min], weight[j]);
				}
			}
	}
	int total_w = 0;
	vector<string> trip;
	int gone[4] = {0,};
	int cnt = 0;
		
	while(true){
		
		if(cnt == n){
			cout << cnt;
			break;
		}
		for(int i=0;i<n;i++){
			if(total_w + weight[i] <= ship_w && gone[i] != 1){
				total_w += weight[i];
				trip.push_back(name[i]);
				gone[i] = 1;
			}
		}
		for(int i = 0; i < trip.size(); i++){
			cout << trip[i] << " ";
		}
		trip.clear();
		cout << endl;
		cnt++;
		total_w = 0;
	}
}

