#include<iostream>
using namespace std;

// $50 , 5
// $60 , 10
// $140, 20

int main(){
	
	int item_profit[3] = { 50, 60 , 140 };
	int item_weight[3] = { 5, 10, 20 };
	int back = 30;
	int profit = 0 ;
	int density[3];
	

	for(int i = 0; i < 3; i++){
		
		back-= item_weight[i];

		profit += item_profit[i];
		
		if( back < item_weight[2] ){
			break;
		}
	}
	cout << " # Weight"<< "\n"<<"score = "<< profit << endl;

	profit = 0;
	back = 30;
	
	for( int i = 2; i >= 0 ; i--){

		profit += item_profit[i];
		back -= item_weight[i];
		
		if(back < item_weight[0]){
			break;
		}
	}
	cout << "# Profit" << "\n" << "score = " << profit << endl;
	
	
	profit = 0;
	back = 30;
	int smallest;

	for(int i = 0 ; i < 3; i++){
		
		density[i] = (item_profit[i] / item_weight[i]);
	}
	
	for( int i = 0; i < 3 ; i++){
		smallest = i;
		for( int j = i+1; j < 3; j++){
			if(density[j] < density[smallest] ){

				int temp = density[smallest];
				density[smallest] = density[j];
				density[j] = temp;
				
				swap(item_profit[smallest],item_profit[j]);
				swap(item_weight[smallest],item_weight[j]);

			}
		}
	}

		for( int i = 2; i >= 0 ; i--){

		profit += item_profit[i];
		back -= item_weight[i];

		if(back < item_weight[0]){
			break;
		}
	}
		cout <<"\n" << "# Density" << "\n" << "score = " << profit << endl;
}
