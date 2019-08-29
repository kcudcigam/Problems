#include<bits/stdc++.h>
using namespace std;
int n,q,lemon[500001],f[500001];
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int find(int k){
	if(f[k]==k)return k;
	return f[k]=find(f[k]);
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int o,a,b;
	read(n);read(q);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=q;i++){
		read(o);
		if(o==1){
			read(a);read(b);
			int x1=find(a),x2=find(b);
			if(x1!=x2){
				f[x1]=x2;
			}
		}
		if(o==2){
			read(a);read(b);lemon[a]+=b;
			for(int j=1;j<=n;j++){
				if(j!=a){
					int x1=find(a),x2=find(j);	
					if(x1==x2){
						lemon[j]+=b;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",lemon[i]);
	return 0;
}
