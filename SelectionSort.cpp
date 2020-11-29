#include<iostream>
using namespace std;

int main(){

	int n;
	int S[5];
	int smallest;

	cin >> n;

	for(int i = 0 ; i < n; i++){
		cin >> S[i];
	}

	for( int i = 0; i < n ; i++){
		smallest = i;
	for( int j = i+1; j < n; j++){
		if(S[j] < S[smallest] ){

			int temp = S[smallest];
			S[smallest] = S[j];
			S[j] = temp;

			}
		}
	}

	for(int i= 0; i < n; i++){
		cout << S[i];
	}
}
