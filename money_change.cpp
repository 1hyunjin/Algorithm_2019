#include<iostream>
using namespace std;
//예전의 것을 가져다 사용하는 것이 중요하다!
int main(){
	
	int arr[15] = {0,};

	for(int i =1;i<15;i++){
		arr[i] = 987654321;
	}
	int coin[4] = {1,4,5,6};
	
	for(int i = 0; i < 4; i++){
		
		for(int j = 1; j < 15; j++){
			
			if(arr[j] > arr[j - coin[i]] + 1){
	   			arr[j] = arr[j - coin[i]]+1;
			}
		}
	}

	cout << arr[14];
	
}

