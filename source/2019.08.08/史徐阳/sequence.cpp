#include<bits/stdc++.h>
#define LL long long
using namespace std;
template<class T>inline void read(T &n){
	n = 0;T f = 1;char ch;
	for (;!(ch >= '0' && ch <= '9');ch = getchar())if (ch == '-')f = -1;
	for (;ch >= '0' && ch <= '9';ch =getchar())n = (n<<1) + (n<<3) + (ch^48);
	n *= f;
}
struct Node{
	int x, y, e;
	Node(int a,int b,int c){
		x = a,y = b,e = c;
	}
};
vector<Node>s[500005];
vector<Node>now;
int head = 0;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n, T;
	LL ans, tmp = 0;
	read(n),read(T);
	while(T --){
		int l, r, b, e;
		read(l),read(r),read(b),read(e);
		s[l].push_back(Node(b, (e - b) / (r - l), r));	
	}
	for (size_t i = 0;i < s[1].size();i ++)
		now.push_back(s[1][i]);
	for (size_t i = 0;i < now.size();i ++){
		tmp += now[i].x;
		now[i].x += now[i].y;
	}
	ans = tmp;
	for (int i = 2;i <= n;i ++){
		tmp = 0;
		for (size_t j = 0;j < now.size();j++)
			if (now[j].e < i)now.erase(now.begin()+j);
		for (size_t j = 0;j < s[i].size();j ++)
			now.push_back(s[i][j]);
		for (size_t j = 0;j < now.size();j ++){
			tmp += now[j].x;
			now[j].x += now[j].y;
		}
		ans ^= tmp;
	}
	printf("%lld\n", ans);
	return 0;
}

