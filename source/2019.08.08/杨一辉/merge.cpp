#include<bits/stdc++.h>
using namespace std;
int n,q,b,c,d;
struct node
{
	int id;
	int ans;
	int dui;
}a[500005];
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(n);
	read(q);
	for(int i=1;i<=n;i++)
	{
		a[i].id=i;
		a[i].dui=i;
	}
	for(int i=1;i<=q;i++)
	{
		read(b);
		read(c);
		read(d);
		if(b==1)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j].dui==a[d].dui)a[j].dui=a[c].dui;
			}
		}
		if(b==2)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j].dui==a[c].dui)a[j].ans+=d;
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<a[i].ans<<" ";
	return 0;
}

