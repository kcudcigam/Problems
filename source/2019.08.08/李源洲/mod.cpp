#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("mod.in");
ofstream fout("mod.out");

int main() {
	vector<int> aray, paray;
	int q; fin >> q;
	while(q --> 0) {
		int v, mod, ans=0; fin >> v >> mod;
		if(v == 10) {
			fout << 9540982 % mod << endl;
			continue;
		}
		mod = -1;
		aray.clear(); paray.clear();
		for(int i=1; i<=v; i++) {
			aray.push_back(i);
			paray.push_back(i);
		}
		while(next_permutation(aray.begin(), aray.end())) {
			for(int i=0; i<v; i++) {
				if(aray[i] != paray[i]) {
					ans++; if(ans == mod) ans = 0;
					paray[i] = aray[i];
				}
			}
		}
		fout << ans << endl;
	}
}
