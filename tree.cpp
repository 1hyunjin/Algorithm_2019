#include<iostream>
#include<list>
#include<vector>
using namespace std;

int main(){

	vector<int> I[7];

	I[1].push_back(2);
	I[1].push_back(3);

	I[2].push_back(1);
	I[2].push_back(4);

	I[3].push_back(1);
	I[3].push_back(4);
	I[3].push_back(5);

	I[4].push_back(2);
	I[4].push_back(3);
	I[4].push_back(5);
	I[4].push_back(6);

	I[5].push_back(3);
	I[5].push_back(4);

	I[6].push_back(4);


	for(int i =0; i < 7; i++){

		vector <int>::iterator begin_iter = I[i].begin();
		for(int j=0;j<I[i].size();j++){
			cout << " - >" << *begin_iter;
			begin_iter++;
		}
		cout << endl;
	}

}
