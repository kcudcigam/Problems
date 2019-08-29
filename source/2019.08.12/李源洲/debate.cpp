#include <algorithm>
#include <fstream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

ifstream cin("debate.in");
ofstream cout("debate.out");

priority_queue<int> YY, YN, NY, NN, etc;

inline int daru(int a, int b) {
	return (a/b) + (int)((bool)(a%b));
}

int main() {
	int n; cin >> n;
	for(int i=0; i<n; i++) {
		string sup; int v; cin >> sup >> v;
		if(sup == "11") YY.push(v);
		if(sup == "10") YN.push(v);
		if(sup == "01") NY.push(v);
		if(sup == "00") NN.push(v);
	}
	int score = 0, sup1 = 0, sup2 = 0, tot = 0;
	while(!YY.empty()) {
		score += YY.top(); YY.pop();
		sup1++; sup2++; tot++;
	}
	while(!YN.empty() && !NY.empty()) {
		score += YN.top(); YN.pop();
		score += NY.top(); NY.pop();
		sup1++; sup2++; tot += 2;
	}
	while(!YN.empty()) { etc.push(YN.top()); YN.pop(); }
	while(!NY.empty()) { etc.push(NY.top()); NY.pop(); }
	while(!NN.empty()) { etc.push(NN.top()); NN.pop(); }
	while(((double)sup1)/((double)(tot+1)) >= 0.5) {
		score += etc.top(); etc.pop();
		tot++;
	}
	cout << score << endl;
}
