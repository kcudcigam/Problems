#include<bits/stdc++.h>
using namespace std;
int n,q;
int f[500001],p[500001];
vector <int> wa[500001];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int fat(int nowx){
	if(f[nowx]==nowx)return nowx;
	return f[nowx]=fat(f[nowx]);
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n);read(q);
	for(int i=1;i<=n;++i){
		f[i]=i;
		wa[i].push_back(i);
	}
	for(int i=1;i<=q;++i){
		int k,x,y;
		read(k);read(x);read(y);
		if(k==1){
			if(fat(x)!=fat(y)){
				for(int i=0;i<wa[fat(y)].size();++i){
					wa[fat(x)].push_back(wa[fat(y)][i]);
				}
				wa[fat(y)].clear();
				f[fat(y)]=fat(x);
			}
		}
		else {
			for(int i=0;i<wa[fat(x)].size();++i){
				p[wa[fat(x)][i]]+=y;
			}
		}
	}
	for(int i=1;i<=n;++i)cout<<p[i]<<' ';
	return 0;
}


