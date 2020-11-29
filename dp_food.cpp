#include<iostream>
#include<list>
using namespace std;

	list<int> end_val;
	list<list> end_menu;

void tree(list taken[], list left[], int value, int remain){


	if(left[0].size() ==0 || remain == 0){
		
		end_menu = taken[0];
		end_val.push_back(value);
		
		return ;
	}


	string now_menu = left[0].pop_front();
	int now_value = left[1].pop_front();
	int now_cal = left[2].pop_front();
	
	//선택 안했을 때
	tree(taken,left,value,remain);
	
	taken[0].push_back(now_menu);
	taken[1].push_back(now_value);
	taken[2].push_back(now_cal);
	
	//선택을 했을 때
	if(now_cal <= remain){
		tree(taken, left, value+now_value, remain-now_cal);
	}
	
	
}


int main(){
	
	list <int> taken[3];
	
	list <int> left[3];
	left[0].push_back(1);
	left[0].push_back(2);
	left[0].push_back(3);
	left[0].push_back(4);
	
	left[1].push_back(6);
	left[1].push_back(7);
	left[1].push_back(8);
	left[1].push_back(9);
	
	left[2].push_back(3);
	left[2].push_back(3);
	left[2].push_back(2);
	left[2].push_back(5);
	
	
	tree(taken, left, 0, 5);
	
	
	max = end_val.pop_front;
	
	list <int> an;
	
	
	an = end_menu.pop_front();
	
	for(int i = 1; i < end_val.size(); i++){
		
		int now_val = end_val.pop_front();
		list <int> now_menu = end_menu.pop_front();
		if( max < now ){
			an = now menu;
			max = now;
		}
	}
	
}
