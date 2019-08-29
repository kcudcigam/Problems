//#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

ifstream fin("review.in");
ofstream fout("review.out");

#define cin fin 
#define cout fout

vector<int> base2(long long i) {
	vector<int> a;
	while(i) {
		a.push_back(i%2);
		i /= 2;
	}
	return a;
}

bool AdjMat[500][500];
int EDGES;

inline void j(int x, int y) {
	AdjMat[x][y] = 1; EDGES++;
}

int QUACKQUACK = -1;
int nodes;

inline void initqq() {
	if(QUACKQUACK != -1) return;
	QUACKQUACK = nodes++;
	j(QUACKQUACK, 0);
}

int main() {
	long long X; cin >> X;
	nodes = 2;
	int pbase = -1;
	vector<int> b2 = base2(X);
	for(int i=0; i<b2.size(); i++) {
		int cnode = nodes++;
		for(int jl=1; jl<cnode; jl++)
			if(jl != QUACKQUACK) j(jl, cnode); 
		if(b2[i] == 1) {
			initqq();
			j(cnode, QUACKQUACK);
		}
	}
	cout << nodes << ' ' << EDGES << endl;
	for(int i=1; i<=nodes; i++)
		for(int j=0; j<=nodes; j++)
			if(AdjMat[i][j])
				cout << i << ' ' << ((j == 0)?nodes:j) << endl;
}
