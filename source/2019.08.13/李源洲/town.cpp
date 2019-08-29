#include <fstream>
using namespace std;

ifstream cin("town.in");
ofstream cout("town.out");

// Test cases 1 through 5

#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> elist[2005];

struct dffs { int dn, ss; };

dffs dfs(int node, int parent, int depth) {
	dffs ans; ans.dn = depth; ans.ss = 0;
	if(elist[node].size() == 1 && parent != -1)
		return ans;
	vector<int> subtrees;
	for(int i=0; i<elist[node].size(); i++) {
		if(elist[node][i] == parent) continue;
		dffs sans = dfs(elist[node][i], node, depth+1);
		ans.dn = max(ans.dn, sans.dn);
		ans.ss = max(ans.ss, sans.ss);
		subtrees.push_back(sans.dn);
	}
	ans.ss = max(ans.ss, ans.dn-depth);
	if(subtrees.size() != 1) {
		sort(subtrees.begin(), subtrees.end(), greater<int>());
		ans.ss = max(ans.ss, subtrees[0]+subtrees[1]-2*depth);
	}
	return ans;
}
	

int mainFirstFifty(int N) {
	for(int i=0; i<N-1; i++) {
		int s, e; cin >> s >> e;
		elist[s].push_back(e); elist[e].push_back(s);
		dffs ans = dfs(s, -1, 0);
		cout << max(ans.dn, ans.ss) << endl;
	}
	return 0;
}

// Test cases 6 and 7

#include <cstring>
#include <algorithm>
using namespace std;

int bcj[300005], size[300005];
int root(int x) {
	if(bcj[x] == -1) return x;
	else { bcj[x] = root(bcj[x]); return bcj[x]; }
}
void join(int x, int y) {
	int rx = root(x), ry = root(y);
	if(rx == ry) return;
	if(size[rx] > size[ry]) swap(rx, ry);
	bcj[rx] = ry; size[ry] += size[rx];
}

int mainNextTwenty(int N) {
	for(int i=0; i<=N; i++) {
		bcj[i] = -1;
		size[i] = 1;
	}
	for(int i=0; i<N-1; i++) {
		int s, e; cin >> s >> e;
		join(s, e);
		cout << size[root(s)]-1 << endl;
	}
	return 0;
}

// Communist things

int main() {
	int N; cin >> N;
	if(N <= 2000) mainFirstFifty(N);
	else mainNextTwenty(N);
	return 0;
}
