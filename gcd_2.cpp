#include<iostream>
using namespace std;

int main() {


	int a,b;
	
	cin >> a >> b;
	
	
	while(1){

		if( a == 0 || b == 0){
			if(a == 0){
				cout << b << endl;
				break;
				
			}
			else if( b == 0 ){
				cout << a << endl;
				break;
			}
		}
		else if( a > b ){
			a = a%b;
		}
		else if( a < b){
			b = b%a;
		}
	}

}

