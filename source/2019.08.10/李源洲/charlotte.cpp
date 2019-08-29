#include <fstream>
#include <cmath>
using namespace std;

ifstream cin("charlotte.in");
ofstream cout("charlotte.out");

// Manhattan distance

inline int md(int x1, int y1, int x2, int y2) {
	return abs(x2-x1) + abs(y2-y1);
}

// Calculates whether or not you can arrive at TSC (x2, y2, t2) provided you were at (x1, y1, t1) just before.

inline bool ok(int x1, int y1, int t1, int x2, int y2, int t2) {
	int mdto = md(x1, y1, x2, y2);
	return ((t2-t1) >= mdto) && ((t2-t1) % 2 == mdto % 2);
}

int main() {
	int T; cin >> T;
	while(T --> 0) {
		bool OK = true;
		int d; cin >> d;
		int x1 = 0, y1 = 0, t1 = 0, x2, y2, t2;
		while(d --> 0) {
			cin >> t2 >> x2 >> y2;
			if(!OK) continue;
			if(!ok(x1, y1, t1, x2, y2, t2)) OK = false;
		}
		cout << (OK?"Yes":"No") << endl;
	}
}
