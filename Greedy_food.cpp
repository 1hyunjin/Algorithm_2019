//가치 high & 칼로리 낮은 것 부터
//sort는 내림차순
#include<iostream>
using namespace std;

int testGreedy(int constraint, int key){
	
	string food[8] = {"Wine", "Beer", " Pizza", "Burger", "Fires", "Coke" , "Apple","Donut"};
	
	double value[8] = {89, 90, 95, 100, 90, 79, 50 , 10 };
	double calorie[8] = {123, 154, 258, 354, 365, 150, 95, 195};
	double density[8];

	int total_value = 0;
	int arr[8];
	
	for(int i = 0 ; i < 8; i++){
		arr[i] = -1;
	}
	
	
	
	if(key == 1){
			cout << "Use greedy by value to allocate " << constraint << " calories" <<endl;
			for(int i = 0; i < 8; i++){
			int smallest = i;
			for(int j = i+1; j < 8; j++){
				if(value[smallest] < value[j]){
					swap(value[smallest],value[j]);
					swap(food[smallest],food[j]);
					swap(calorie[smallest], calorie[j]);
				}
			}
		}

		
 		for(int i =0 ; i < 8; i++){
			
			if(constraint > calorie[i]){
				constraint -= calorie[i];
				total_value += value[i];
				//cout << food[i] << " < " << value[i] << "," << calorie[i] << " > "<< endl;
				arr[i]=i;
			}
			else if(constraint < calorie[i]){
				calorie[i] = calorie[i+1];
			}
		}
		
		cout << "Total value of items taken = " << total_value <<endl;

	}
	
	if(key == 2){
		cout << "Use greedy by calorie to allocate " << constraint << " calories" <<endl;
		for(int i = 0; i < 8; i++){
			int max = i;
			for(int j = i+1; j < 8; j++){
				if(calorie[max] > calorie[j]){
					swap(value[max],value[j]);
					swap(food[max],food[j]);
					swap(calorie[max], calorie[j]);
				}
			}
		}
		for(int i = 0; i < 8; i++){
			constraint -= calorie[i];
			total_value += value[i];
			
			if(constraint > calorie[i]){
//				cout << food[i] << " < " << value[i] << "," << calorie[i] << " > "<< endl;
				arr[i]=i;
			}
		}
		cout << "Total value of items taken = " << total_value <<endl;
	}
	if(key == 3){
		cout << "Use greedy by density to allocate " << constraint << " calories" <<endl;
		for(int i = 0; i < 8; i++){
			density[i] = value[i]/calorie[i];
		}
		for(int i = 0; i < 8; i++){
			int smallest = i;
			for(int j = i+1; j < 8; j++){
				if(density[smallest] < density[j]){
					swap(density[smallest],density[j]);
					swap(food[smallest],food[j]);
					swap(value[smallest],value[j]);
					swap(calorie[smallest],calorie[j]);
				}
			}
		}
		for(int i = 0; i < 8; i++){
			if(constraint > calorie[i]){
				total_value += value[i];
				constraint -= calorie[i];
//				cout << food[i] << " < " << value[i] << "," << calorie[i] << " > "<< endl;
				arr[i]=i;
			}
			else{
				calorie[i] = calorie[i+1];
			}
		}
		cout << "Total value of items taken = " << total_value <<endl;
	}
	
	for(int i=0;i<8;i++){
		if(arr[i] != -1){
			cout << food[i] << " < " << value[i] << "," << calorie[i] << " > "<< endl;
		}
	}
	
}

int main(){
	
	testGreedy( 750, 1);
	cout <<"--------------------------"<<endl;
	testGreedy(750,2);
	cout <<"--------------------------"<<endl;
	testGreedy(750,3);
	

	
}
