#include<iostream>
#include <cmath>
#include<vector>
#include <algorithm>
using namespace std;

int W[4][4] = {0,2,9,999, 1,0,6,4, 999,7,0,8, 6,3,999,0};
int bitarr[4];

int D(int n, int c){
	if(c == 0){
		return W[n][0];
	}
	int fi = 99;
	for(int i = 0; i < 4; i++){
		if(i == n){
			continue;
		}
		//1이 갈 수 있는거 0이 이미 간거
		if((c & bitarr[i]) == 0){
			continue;
		}
		fi = min(fi,W[n][i] + D(i,c-bitarr[i]));
	}
	return fi;
}
int main(){
	
	for(int i = 0; i < 4; i++){
		bitarr[i] = pow(2,i);
	}
	cout << D(0,14);
}

