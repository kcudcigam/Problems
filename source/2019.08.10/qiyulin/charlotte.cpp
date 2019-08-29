#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int te,n,u,v,w,p,t,x,y,ch,s;

int Abs(int x){
	return ((x>=0)?x:(-x));
}

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	te=rd();
	for (;te>0;--te){
		n=rd();
		u=v=w=p=0;
		for (int i=1;i<=n;++i){
			t=rd();x=rd();y=rd();
			ch=t-w;s=Abs(u-x)+Abs(v-y);
			p=((ch>=s)&&(((ch-s)%2)==0))?p:1;
			w=t;u=x;v=y;
		}
		if (p==0) cout<<"Yes\n";else cout<<"No\n";
	}
	return 0;
}
