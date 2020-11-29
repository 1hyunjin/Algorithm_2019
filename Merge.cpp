#include<iostream>
using namespace std;

void mergeSort(int n, int S[]);
void merge(int h, int m, int U[], int V[], int S[]);

int main(){
	
	int n;
	int S[1000];
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> S[i];
	}

	mergeSort(n,S);
	
	cout << "결과: ";
	for(int i = 0; i < n; i++){
		cout << S[i] << " ";
	}

}
void mergeSort(int n, int S[]){
	
	if(n > 1){
		int h = n/2;
		int m = n-h;
		
		int U[h];
		int V[m];
		
		for(int i = 0; i < h; i++){
			U[i] = S[i];
			cout << U[i];
		}
		cout << " ";
		for(int i = 0; i < m; i++){
			V[i] = S[h+i];
			cout << V[i];
		}
		cout << "\n";
		mergeSort(h,U);
		mergeSort(m,V);
		merge(h,m,U,V,S);
	}
}
void merge(int h, int m, int U[], int V[], int S[]){
	int i = 0;
	int j = 0;
 	int k = 0;
 	while( h > i && m > j){
		if( U[i] > V[j] ){
			S[k++] = V[j++];
		}else{
			S[k++] = U[i++];
		}
	}
	while( h > i){
		S[k++] = U[i++];
	}
	while( m > j ){
		S[k++] = V[j++];
	}
	
	for(int i = 0; i < k; i++) {
		cout << S[i] << " ";
	}
	cout << "\n머지완료" << endl;
}



