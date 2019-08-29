#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=11;
string n[N];
int t,hx[18];
template <typename T> inline void read(T &x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(f=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
void init()
{
	read(t);
	for(int i=1;i<=t;i++)
	{
		cin>>n[i];
	}
}
void work()
{
	int tot=0;
	for(int i=1;i<=t;i++)
	{
		tot=0;
		memset(hx,0,sizeof(hx));
		for(int j=0;j<n[i].length();j++)
		{
			if(hx[n[i][j]-'0']==0)tot++;
			hx[n[i][j]-'0']=1;
		}
		if(tot==2||tot==1)
		cout<<1<<endl;
		else if(tot==3)
		cout<<2<<endl;
		else cout<<(tot-1)/2+1<<endl;
	}
		
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	init();
	work();
	return 0;
}


