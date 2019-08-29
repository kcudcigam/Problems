#include <fstream>
#include <algorithm>
using namespace std;

int forwardMSUM[100005], backwardMSUM[100005];
int aray[100005];

ifstream fin("sum.in");
ofstream fout("sum.out");

int main() {	
	int n; fin >> n;
	for(int i=0; i<n; i++) fin >> aray[i];
	// Do Kadane's algorithm twice; forwards and backward
	int cur = aray[0];
	for(int i=0; i<n; i++) {
		if(i == 0) forwardMSUM[i] = aray[i];
		else {
			cur = max(cur+aray[i], aray[i]);
			forwardMSUM[i] = max(forwardMSUM[i-1], cur);
		}
	}
	cur = aray[n-1];
	for(int i=n-1; i>=0; i--) {
		if(i == n-1) backwardMSUM[i] = aray[i];
		else {
			cur = max(cur+aray[i], aray[i]);
			backwardMSUM[i] = max(backwardMSUM[i+1], cur);
		}
	}
	int ans = aray[0];
	for(int C=0; C<n-1; C++)
		ans = max(ans, forwardMSUM[C] + backwardMSUM[C-1]);
	fout << ans << endl;
}
