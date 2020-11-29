#include<iostream>
#include<vector>
#include<queue>
#define INF 9999
using namespace std;

int main()
{
    int n = 5;
    int m = 8;
    int start;
    int end;
	cout << "����: " ;
	cin >> start   ;    
	cout << "��: ";
	cin >> end;
	
	vector<pair<int,int> > arr[n+1];

    for(int i=0;i<m;i++){
        int from,to,val;
        cin >> from >> to >> val;
        arr[from].push_back({to,val});
    }
    int dist[n+1];    
    for(int i = 0; i < n+1; i++){
    	dist[i] = INF;
	}
    
    priority_queue<pair<int,int> > qu;

    qu.push({0,start});    
    dist[start]=0;    

    while(!qu.empty()){
        int length=-qu.top().first;    // length�� ���� �湮�� ���� dist��.
        int touch=qu.top().second;     // touch�� �湮�� ���� ��ȣ

        qu.pop();

        for(int i=0; i<arr[touch].size(); i++){
            int next=arr[touch][i].first;
            int nextlength=arr[touch][i].second;

            if(dist[next] > dist[touch] + nextlength){
                dist[next]=dist[touch]+nextlength;
				//������ ����� ���� ������ ��
                qu.push({-dist[next],next});
            }
        }
    }
	cout << "�� : " << dist[end];
}

