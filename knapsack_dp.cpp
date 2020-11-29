#include<iostream>
using namespace std;

int main(){
	int arr[30] = {0,};
	
	int profit[3] = { 50, 60, 140 };
	int weight[3] = { 5, 10, 20 };
	
	for(int i = 0; i < 3; i++){

 		for(int j = 1; j < 31; j++){
 			
				if( j-weight[i] >= 0 ){
					
					if(j/weight[i] < 2){

	 					if(arr[j] < arr[j-weight[i]] + profit[i]){

							arr[j] = arr[j-weight[i]] + profit[i];
						}
					}
					else {
	  						arr[j] = arr[j-weight[i]];
					}
				}
		}
	}
	cout << arr[10];
}

