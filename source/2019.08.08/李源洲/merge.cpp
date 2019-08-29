#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("merge.in");
ofstream fout("merge.out");

int _parent[1000005], _root[1000005], _incr[1000005], totincr[1000005], size[1000005];
int nodes;

int root(int x) {
	if(_root[x] == x) return x;
	else {
		_root[x] = root(_root[x]);
		return _root[x];
	}
}

void join(int x, int y) {
	int rx = root(x), ry = root(y);
	if(rx == ry) return;
	nodes++;
	_root[rx] = nodes; _root[ry] = nodes;
	_parent[rx] = nodes; _parent[ry] = nodes;
	size[ry] += size[rx];
}

void incr(int x, int v) {
	_incr[root(x)] += v;
}

int getTotIncr(int x) {
	if(totincr[x] != -1) return totincr[x];
	if(_parent[x] == x) totincr[x] = _incr[x];
	else totincr[x] =  _incr[x] + getTotIncr(_parent[x]);
	return totincr[x];
}

int main() {
	int n, q; fin >> n >> q; nodes = n;
	for(int i=1; i<=(n+q); i++) {
		_parent[i] = i;
		_root[i] = i;
		_incr[i] = 0;
		totincr[i] = -1;
		size[i] = 1;
	}
	while(q --> 0) {
		int com, v1, v2; fin >> com >> v1 >> v2;
		if(com == 1) join(v1, v2);
		if(com == 2) incr(v1, v2);
	}
	for(int i=1; i<=n; i++) {
		if(i != 1) fout << ' ';
		fout << getTotIncr(i);
	}
	fout << endl;
}
