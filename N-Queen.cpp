#include<iostream>
#include<stdlib.h>
using namespace std;

int n;
void queens(int i);
bool promising(int i);

int col[255];
int cnt =0 ;

void queens(int i){

	int j;
	
	if(promising(i)){
		if(i == n){
			cnt++;
			for( i = 1; i <= n; i++){
				cout << col[i];
			}
			cout << "\n";
		}
		else{
			for(j = 1; j <= n; j++){
				col[i+1] =j;
				queens(i+1);
			}
		}
	}
}
bool promising(int i){
	//이전 값들 = k
	int k;
	
	k = 1;
	bool change = true;
	while(k < i && change){
		if(col[i] == col[k] || abs(col[i] - col[k]) == abs( i-k )){
			change = false;
		}
		k++;
	}
	return change;
}
int main(){

	cin >> n;

	queens(0);

	cout << cnt;
}
