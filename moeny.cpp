//dynamicP
#include<iostream>
using namespace std;

int main(){

	int coin[4] = { 1, 4, 5, 6 };
	int count[4];

	int num = 0;
	int money;
	cin >> money;


	for(int i = 3; i >= 0; i--){

//	cout << coin[i] <<endl ;
		for(;;){
			if(money - coin[i] >= 0){
				money -= coin[i];
				cout << coin[i] <<"원" << " , 남은 금액 :  " << money << "\n";
				num ++;
			}
			else break;
		}

	}
	cout << "최소" << num << "개";

}


