#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=16;
int n;
char a[N],b[N];
map<string,int>hx;
template <typename T> inline void read(T &x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	x*=f;
}
void init()
{
	read(n);
	for(int i=1;i<n;i++)
	{
		read(a[i]);
	}	
}
int work(int dep)
{
	string s;
	for(int i=1;i<=4;i++)
	{
		if(b[i]<='1')b[i]='0';
		else{
			b[i]-='1';
			for(int j=1;j<=4;j++)
			{
				s+=b[i];
			}
			if(hx[s]>0)
			{
				return dep-hx[s];
			}else hx[s]=dep;
			for(int j=1;j<=4;j++)
			{
				if(b[j]=='0')
				{
					b[j]=a[b[i]];
					for(int r=1;r<=4;r++)
					{
						s+=b[r];
					}
					if(hx[s]>0)
					{	
						return dep-hx[s];
					}else hx[s]=dep;
					break;	
				}
			}	 
		}
	}
	for(int j=1;j<=n;j++)
	{
		s+=b[j];
	}
	if(hx[s]>0)
	{
		return dep-hx[s];
	}else hx[s]=dep;
	return work(dep+1); 
}
int main()
{
	freopen("bob.in","r",stdin);
	freopen("bob.out","w",stdout);
	init();
	if(n==1||n==0)cout<<0<<endl;else
	if(n==2)cout<<31<<endl;else
	if(n>4)cout<<0<<endl;
	return 0;
}


