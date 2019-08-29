#include <fstream>
#include <set> 
using namespace std;

ifstream cin("number.in");
ofstream cout("number.out");

int main() {
	int t; cin >> t;
	while(t --> 0) {
		int v; cin >> v;
		set<int> uniq;
		while(v != 0) {
			uniq.insert(v%10);
			v /= 10;
		}
		if(uniq.size() <= 2) cout << 1 << endl;
		else cout << 2 << endl;
	}
}
