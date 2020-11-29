#include<iostream>
#include<vector>
using namespace std;

int loop = 100;

int D[5][5] = {0 ,1 ,loop, 1, 5 , 9, 0, 3, 2, loop, loop, loop, 0, 4, loop, loop, loop, 2, 0, 3, 3, loop, loop, loop, 0};
int P[5][5] = {};

vector<int> v;


int find(int x, int y){
	
	int z;
	
	if( P[x][y] != 0){
		
		z = P[x][y] - 1;
		
		find(x,z);
		find(z,y);
	}
	if( P[x][y] == 0){

		v.push_back(y+1);
	}
}

int main(){

	for(int k = 0; k < 5; k++){

		for(int i = 0; i < 5; i++){

			for(int j = 0; j < 5; j++){

				if(D[i][j] > D[i][k] + D[k][j]){
					P[i][j] = k+1;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
	v.push_back(4+1);
	
	find(4,2);
	
	cout << v[0] ;
	
	for (vector<int>::size_type i = 1; i < v.size(); ++i)
        cout << " -> " << v[i];
}
