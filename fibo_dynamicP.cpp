#include<iostream>
using namespace std;


double fibo_dynamicP(int n){
	

	int fibo_memo[100];
	
	fibo_memo[0] = 0;
	fibo_memo[1]= 1;
	
	if( n > 1){
		
		fibo_memo[n] = fibo_dynamicP(n-1) + fibo_dynamicP(n-2);
	}
		return fibo_memo[n];
}

int main(){

	int n;

	cin >> n;
	
	
	fibo_dynamicP(n);
	
	cout << fibo_dynamicP(n) << "\n";
}


