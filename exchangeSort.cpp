#include<iostream>
using namespace std;

int main(){

	int n;
	int S[5];
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> S[i];
	}

	for( int i = 0; i < n ; i++){
		for( int j = i+1; j < n; j++){
			if(S[j] < S[i] ){
				
				int temp = S[i];
				S[i] = S[j];
				S[j] = temp;
			}
		}
	}
	
	for(int i= 0; i < n; i++){
		cout << S[i];
	}

}
