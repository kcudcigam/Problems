#include <algorithm>
#include <fstream>
#include <vector> 
using namespace std;

ifstream cin("stand.in");
ofstream cout("stand.out");

struct interval {
	int s, e;
	const bool operator< (const interval other) const {
		return e < other.e;
	}
};

// j ovelap i?

inline bool doesOvl(interval i, interval j) {
	return i.s <= j.e && j.s <= i.e;
}

vector<interval> peaple;

int main() {
	int n, m; cin >> n >> m;
	long long co1, co2, co3, co4, co5; cin >> co1 >> co2 >> co3 >> co4 >> co5;
	long long ans = 0;
	while(n --> 0) {
		int s, e; cin >> s >> e;
		peaple.push_back({s, e});
	}
	sort(peaple.begin(), peaple.end());
	interval current = {0, m}; long long c = 0;
	for(interval i:peaple) {
		if(doesOvl(i, current)) {
			current.s = max(current.s, i.s);
			current.e = min(current.e, i.e);
		} else {
			current = i;
			ans += (co1*c + co2*c*c + co3*c*c*c + co4*c*c*c*c + co5*c*c*c*c*c);
			c = 0;
		}
		c++;
	}
	ans += (co1*c + co2*c*c + co3*c*c*c + co4*c*c*c*c + co5*c*c*c*c*c);
	cout << ans << endl;
}
