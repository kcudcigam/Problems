#include<bits/stdc++.h>
using namespace std;
int fa[500001],jc[500001];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int n,q,a,b,c,r=0,k[500001];
	read(n);
	read(q);
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=q;i++){
		read(c);
		if(c==1){
			read(a);
			read(b);
			for(int j=1;j<=n;j++){
				if(fa[j]==fa[b]){
					r++;
					k[r]=j;
				}
			}
			for(int j=1;j<=r;j++){
				fa[k[j]]=fa[a];
			}
			memset(k,0,sizeof(k));
			r=0;
		}else{
			read(a);
			read(b);
			for(int j=1;j<=n;j++){
				if(fa[j]==fa[a]){
					jc[j]+=b;
				}
			}
		}
	}
	for(int i=1;i<=n-1;i++){
		cout<<jc[i]<<" ";
	}
	cout<<jc[n]<<endl;
	return 0;
}


