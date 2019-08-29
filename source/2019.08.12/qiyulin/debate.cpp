#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100+(int)(4e5);

int n,ans,cnt,u,v,w,x,opt;
int a[N],b[N],c[N];

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

bool cmp(int x,int y){
	return (x>y);
}

int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	n=rd();
	ans=cnt=0;
	u=v=w=0;
	for (int i=1;i<=n;++i){
		opt=rd();x=rd();
		if (opt==11){
			ans+=x;
			++cnt;
		}else
			if (opt==1) a[++u]=x;else
				if (opt==10) b[++v]=x;else
					c[++w]=x;
	}
	sort(a+1,a+u+1,cmp);
	sort(b+1,b+v+1,cmp);
	for (int i=1;(i<=u)&&(i<=v);++i) ans+=a[i]+b[i];
	if (u>v)
		for (int i=v+1;i<=u;++i) c[++w]=a[i];else
			if (u<v)
				for (int i=u+1;i<=v;++i) c[++w]=b[i];
	sort(c+1,c+w+1,cmp);
	for (int i=1;(i<=cnt)&&(i<=w);++i) ans+=c[i];
	cout<<ans<<'\n';
	return 0;
}
