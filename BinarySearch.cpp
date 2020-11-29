#include<iostream>
using namespace std;

int x;
int S[6];

int location(int low, int high){

	int mid;

	if(low < high){
		

		mid = (low + high)/2;

		if( x == S[mid] ){
			
			cout << S[mid];

		}
		else if( x < S[mid] ){

			location(low, mid - 1);
		}

		else
			location(mid + 1, high);

	}
}

int main(){
	
	
	for(int i = 1; i <= 5; i++){
		
		cin >> S[i];
		
	}
	
	cin >> x;
	
	location( 1 , 5 );
	
}





