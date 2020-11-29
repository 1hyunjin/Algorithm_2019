#include<iostream>
using namespace std;

void quicksort(int *arr, int low, int high );
int partition(int *arr, int low, int high);
int main(){
	
	int arr[5] = {2,5,3,1,4};
	quicksort(arr,0,4);
	
	for(int i = 0; i < 5; i++){
		cout << arr[i];
	}
	
}
void quicksort(int *arr, int low, int high ){
	

	int pivotpoint;
	
	if(high >= low){
		
		pivotpoint = partition(arr,low,high);
		quicksort(arr,low, pivotpoint - 1);
		quicksort(arr, pivotpoint + 1, high);
	}
	
}

int partition(int *arr, int low, int high){
	
	int i, j;
	
	int pivot;
	
	i = low;
	j = high;
	
	pivot = (i+j)/2;
	
	while( i < j ){
		
		if(arr[i] >= arr[pivot] && arr[j] <= arr[pivot] ){
			if(pivot == j){
				pivot = i;
			}
			else if ( pivot ==i){
				pivot = j;
			}
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
		else if( arr[i] < arr[pivot] && arr[j] < arr[pivot]){
			
			i++;
		}else j--;
	}
	return pivot;
}
