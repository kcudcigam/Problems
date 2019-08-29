#include <fstream>
#include <vector>
#include <set>
#include <vector>
using namespace std;

ifstream cin("sibyl.in");
ofstream cout("sibyl.out");

long long val[300005];

vector<int> elist[300005];

// (._. )

int main() {
	int n, m, q; cin >> n >> m >> q;
	for(int edgar=0; edgar<m; edgar++) {
		int s, e; cin >> s >> e;
		elist[s].push_back(e); 
		elist[e].push_back(s);
	}
	while(q --> 0) {
		int type; cin >> type;
		if(type == 0) {
			int v; cin >> v;
			cout << val[v] << endl;
		} else {
			int v, delta; cin >> v >> delta;
			val[v] += delta;
			for(int neighbor:elist[v]) val[neighbor] += delta;
		}
	}
}
