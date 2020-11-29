#include<iostream>
using namespace std;

int gcd(int a, int b){
	
	if( a == b){
		return a;
	}
	else if( a > b ){
		return gcd(a-b,a);
	}
	else if( a < b ){
		return gcd(a, b-a);
	}
}
int main(){
	
	int a,b;
	int gcd(int a,int b);
	
	cin >> a >> b;
	
	cout << gcd(a,b);
	
}
