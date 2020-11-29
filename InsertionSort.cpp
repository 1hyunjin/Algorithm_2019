#include<iostream>
using namespace std;

int main(){
	
	int n;
	int x;

	int S[10] = { 9,8,7,6,5,4,3,2,1,0 };
	
	for( int i = 1; i < 10; i++){
		x = S[i];
		int j = i-1;
		
		while( j >= 0 && S[j] > x){
			S[j+1] = S[j];
			j--;
		}
		
		S[j+1] = x;
		
	}
	
	for(int i = 0; i < 10; i++){
		cout << S[i];
	}

}
