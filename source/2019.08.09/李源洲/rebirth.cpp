#include <queue>
#include <algorithm>
//#include <iostream>
#include <fstream>
#include <vector>
#include <cstring> 
#include <utility>
using namespace std;

ifstream fin("rebirth.in");
ofstream fout("rebirth.out");

#define cin fin
#define cout fout

struct edge {
	int v; long long w;
}; vector<edge> emat[1005];

struct qel {
	int loc; long long dist;
	const bool operator< (const qel other) const {
		return dist < other.dist;
	}
};

long long dist[1005];
long long DijkstraToNeighborWithoutpassingthroughItItselfandWhyamImakingsuchaterriblylongname(int node) {
	memset(dist, 1, sizeof dist);
	const long long INF = dist[0];
	dist[1] = 0;
	priority_queue<qel> q; q.push({1, 0});
	while(!q.empty()) {
		qel top = q.top(); q.pop();
		if(top.loc == node)
			continue;
		for(edge e:emat[top.loc])
			if(e.v != node && dist[e.v] > top.dist + e.w) {
				dist[e.v] = top.dist + e.w;
				q.push({e.v, dist[e.v]});
			}
	}
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for(edge e:emat[node]) pq.push(dist[e.v]+e.w);
	if(pq.size() == 0 || pq.size() == 1) return -1;
	pq.pop();
	if(pq.top() >= INF) return -1;
	return pq.top();
}

int main() {
	int tc, N, M; cin >> tc >> N >> M;
	for(int i=0; i<M; i++) {
		int s, e, v; cin >> s >> e >> v;
		emat[s].push_back({e, v});
		emat[e].push_back({s, v});
	}
	cout << '0';
	for(int i=2; i<=N; i++)
		cout << ' ' <<  DijkstraToNeighborWithoutpassingthroughItItselfandWhyamImakingsuchaterriblylongname(i);
	cout << endl;
}
