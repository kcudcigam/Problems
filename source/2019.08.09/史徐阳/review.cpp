#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned LL
using namespace std;
LL n;
ULL f[105]={0, 1};
vector<int>vv;
void inti(){
	ULL tmp = 1;
	for (int i = 2;i <= 64;i ++){
		f[i] = tmp;
		tmp += f[i];
	}
}
int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);	
	inti();
	cin >> n;
	LL point = 0, m = n, num = 0;
	for (int i = 64;i >= 1;i --)
		if (m >= f[i]){
			m -= f[i];
			vv.push_back(i);
			point = max(point, (LL)i);
		}
	cout<< point + 1 << ' '<< vv.size() + point * (point - 1) / 2 << endl;
	for (int i = 1;i <= point;i ++)
		for (int j = i + 1;j <= point;j ++)
			printf("%d %d\n", i, j);
	for (size_t i = 0;i < vv.size();i ++)
		printf("%d %d\n", vv[i], point + 1);
	return 0;
}

