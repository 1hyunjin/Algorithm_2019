#include<iostream>
using namespace std;

int main(){
	int loop = 100;

	int D[5][5] = {0 ,1 ,loop, 1, 5 , 9, 0, 3, 2, loop, loop, loop, 0, 4, loop, loop, loop, 2, 0, 3, 3, loop, loop, loop, 0};
	
	int P[5][5] = {};
	
//P[i][j] 안거쳤을 때는 k = 

//전체 정점을 다 계산해야해서 k가 정점이니까 정점을 기준으로 한다.
	for(int k = 0; k < 5; k++){
		
		for(int i = 0; i < 5; i++){

			for(int j = 0; j < 5; j++){
				
				if(D[i][j] > D[i][k] + D[k][j]){
					//P[i][j] = k+1;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
	for(int i = 0; i < 5; i ++){
		for(int j = 0; j < 5; j++){
			cout << D[i][j] << " ";
			//cout << P[i][j]<< " ";
		}
		cout << "\n";
	}
}
