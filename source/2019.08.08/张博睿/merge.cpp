#include<bits/stdc++.h>
using namespace std;
int n,q,k,x,y,a[500002],h[500002],lm[500002];
vector<int> b[500002];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
	 h[i]=i;
	 b[i].push_back(i);	
	}
	memset(a,0,sizeof(a));
	for(int i=1;i<=q;i++)
	{
		read(k);read(x);read(y);
		if(k==2) lm[h[x]]+=y;
		else
		{
			if(h[x]!=h[y])
			{
			for(int j=0;j<b[h[x]].size();j++) a[b[h[x]][j]]+=lm[h[x]];
			lm[h[x]]=0;	
			for(int j=0;j<b[h[y]].size();j++) a[b[h[y]][j]]+=lm[h[y]];
			lm[h[y]]=0;	
			int l=b[h[y]].size();int d=h[y];
			for(int j=0;j<l;j++) 
			{
				b[h[x]].push_back(b[d].back());
				h[b[d].back()]=h[x];
				b[d].pop_back();
			}
			}
		}
	}
	for(int i=1;i<=n;i++) 
	{
		if(lm[i]!=0)
			for(int j=0;j<b[i].size();j++) a[b[i][j]]+=lm[i];
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	cout<<endl;
	return 0;
}

