#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;

int bcj[300005], size[300005];

int root(int x) {
	if(bcj[x] == -1) return x;
	else {
		bcj[x] = root(bcj[x]);
		return bcj[x];
	}
}
bool join(int x, int y) {
	int rx = root(x), ry = root(y);
	if(rx == ry) return false;
	if(size[rx] > size[ry]) swap(rx, ry);
	bcj[rx] = ry; size[ry] += size[rx];
	return true;
}

struct edge {
	int s, e, v;
	const bool operator<(const edge other) const {
		return v < other.v;
	}
};

struct miniedge {
	int e, v;
};

vector<edge> edges;

vector<miniedge> MST[300005];

int n, m, Q;

int parent[300005][20], medge[300005][20], depth[300005];
int ltkid[300005];

void init() {
	memset(bcj, 255, sizeof bcj);
	memset(parent, 255, sizeof parent);
	memset(ltkid, 255, sizeof ltkid);
	for(int i=0; i<=300002; i++) size[i] = 1;
}

int makeMST() {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &Q);
	for(int i=0; i<m; i++) {
		int s, e, v; scanf("%d%d%d", &s, &e, &v);
		edges.push_back({s, e, v});
	}
	sort(edges.begin(), edges.end());
	int edgec = 0;
	for(edge e:edges)
		if(join(e.s, e.e)) {
			MST[e.s].push_back({e.e, e.v});
			MST[e.e].push_back({e.s, e.v});
			edgec++;
			if(edgec == n-1) break;
		}
}


int glca(int n, int p, int l, int d, int id) {
	ltkid[n] = id;
	parent[n][0] = p;
	medge[n][0] = l;
	depth[n] = d;
	int ind = 0;
	while(parent[n][ind] != -1) {
		parent[n][ind+1] = parent[parent[n][ind]][ind];
		medge[n][ind+1] = max(medge[n][ind],medge[parent[n][ind]][ind]);
		ind++;
	}
	for(int i=ind; i<=19; i++) {
		parent[n][ind] = -1;
		medge[n][ind] = medge[n][ind-1];
	}
	for(miniedge e:MST[n])
		if(e.e != p) glca(e.e, n, e.v, d+1, id);
}

int mxin(int i, int j) {
	if(ltkid[i] != ltkid[j]) return -1;
	int cmax = 0;
	while(depth[i] != depth[j]) {
		if(depth[i] < depth[j]) swap(i, j);
		int lv = 0;
		while(parent[i][lv] != -1 && depth[parent[i][lv]] >= depth[j]) lv++;
		lv--;
		cmax = max(cmax, medge[i][lv]);
		i = parent[i][lv];
	}
	while(i != j) {
		int adv = 0;
		while(parent[i][adv] != parent[j][adv]) adv++;
		adv--;
		if(adv == -1)
			return max(cmax, max(medge[i][0], medge[j][0]));
		cmax = max(cmax, max(medge[i][adv], medge[j][adv]));
		i = parent[i][adv]; j = parent[j][adv];
	}
	return cmax;
}

int main() {
	init();
	makeMST();
	for(int id=1; id<=n; id++)
		if(ltkid[id] == -1) glca(id, -1, 0, 0, id);
	while(Q --> 0) {
		int i, j; cin >> i >> j;
		printf("%d\n",mxin(i, j));
	}
}
