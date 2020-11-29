#include<iostream>
#include<queue>
#include<functional>
#include<vector>
#include<algorithm>

#define N 5
using namespace std;

struct e_ {
	int final;
	int weight;
};

struct e {

	int start;
	int final;
	int weight;

};


auto compare = [](e a, e b) {
	return (a.weight > b.weight);
};

using priority_t = priority_queue<e, vector<e>, decltype(compare) >;



bool visited[N];

vector<e> result;

void prim(vector<e_>(&gr)[N], priority_t &q) {

	for (int i = 0; i < gr[0].size(); i++) {
		struct e e_info;
		e_info.start = 0;
		e_info.final = gr[0][i].final;
		e_info.weight = gr[0][i].weight;

		q.push(e_info);
	}
	visited[0] = true;

	while (q.empty() == false) {
		struct e eI = q.top();
		q.pop();

		if (visited[eI.final] == true) continue;

		visited[eI.final] = true;


		for (auto v : gr[eI.final]) {

			if (visited[v.final] != true) {
				struct e ed;
				ed.start = eI.final;
				ed.final = v.final;
				ed.weight = v.weight;
				q.push(ed);
			}

		}

		result.push_back(eI);

	}
}

int main() {
	priority_t priorityQ(compare);

	vector <e_> gr[N];

	struct e ed[] = {

		{ 0,1,1 },
	{ 0,2,3 },

	{ 1,0,1 },
	{ 1,2,3 },
	{ 1,3,6 },

	{ 2,0,3 },
	{ 2,1,3 },
	{ 2,3,4 },
	{ 2,4,2 },

	{ 3,1,6 },
	{ 3,2,4 },
	{ 3,4,5 },

	{ 4,2,2 },
	{ 4,3,5 },

	};

	int size = sizeof(ed) / sizeof(ed[0]);

	int v;
	for (int i = 0; i<size; i++) {
		struct e_ ed_t;
		v = ed[i].start;
		ed_t.final = ed[i].final;
		ed_t.weight = ed[i].weight;

		gr[v].push_back(ed_t);
	}

	prim(gr, priorityQ);


	for (int i = 0; i < result.size(); i++) {
		cout << result[i].start << " " << result[i].final<< endl;
	}

	system("pause");
}

