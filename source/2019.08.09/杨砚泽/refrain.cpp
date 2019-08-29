#include<bits/stdc++.h>
using namespace std;
const int p=1e9+7;
template <typename T>
inline void read(T &x)
{
  int f=1;x=0;
  char ch=getchar();
  for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
  for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
  x*=f;
}
struct node{
	int sun;
	int shade;
};
node f[10051];
int po(int k)
{
	long long l=1;
	for (int i=1;i<=k;i++)
      {
      	l=l*i;
      	l=l%p;
	  }
	return l;
}
int main(){
//	freopen("refrain.in","r",stdin);
//	freopen("refrain.out","w",stdout);
    int NUM,n,m1,m2,x,y;
    memset(f,0,sizeof(f));
    read(NUM);
    read(n);read(m1);read(m2);
    for (int i=1;i<=m1;i++)
      {
      	read(x);read(y);
      	f[x].shade=1;
      	f[y].shade=1;
	  }
	for (int i=1;i<=m2;i++)
	  {
	  	read(x);read(y);
	  	f[x].sun=1;
	  	f[y].sun=1;
	  }
	long long su=0,sh=0,e=0,o=0;
	for (int i=1;i<=n;i++)
	{
		if (f[i].shade==1&&f[i].sun==0) sh++;
		if (f[i].shade==0&&f[i].sun==1) su++;
		if (f[i].shade==0&&f[i].sun==0) e++;
		if (f[i].shade==1&&f[i].sun==1) o++;
	}
    long long ans1=1;
	if (sh>0)ans1+=(sh*(sh-1))/2;
	ans1=ans1%p;
	if (su>0)ans1+=(su*(su-1))/2;
	ans1=ans1%p;
	if (e>0) ans1+=((e-1)*e)/2;
	ans1=ans1%p;
	if (o>0) ans1+=((o-1)*o)/2;
    ans1=ans1%p;
    long long ans2=0;
	ans2=po(n);
    ans2=ans2%p;
    if (ans2<ans1) cout<<ans2+p-ans1;
    else cout<<ans2-ans1;
	return 0;
}

