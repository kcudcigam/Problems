#include<bits/stdc++.h>
using namespace std;
long long a,b,l,r,t,tt,p,pp,s,n[500010],nn[500010],c,ss[500010];
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(a);read(b);
	if (a<=1000)
	{
		for (int i=1;i<=b;i++)
		{
			read(l);read(r);read(t);read(tt);
			c=(tt-t)/(r-l);p=t;
			for (int j=l;j<=r;j++)
			{
				ss[j]+=p;
				p+=c;
			}
		}
		s=0;
		for (int i=1;i<=a;i++)	
		s=s^ss[i];
		cout<<s<<endl;		
	}
	else
	{
		for (int i=1;i<=b;i++)
		{
			read(l);read(r);read(t);read(tt);
			n[l]+=t;
			n[r+1]-=tt;
			nn[l]+=(tt-t)/(r-l);
			nn[r+1]-=(tt-t)/(r-l);
		} 
		p=0;pp=0;s=0;
		for (int i=1;i<=a;i++)
		{
			p+=n[i]+pp;
			pp+=nn[i];
			s=s^p;
		}
		cout<<s<<endl;		
	}
	return 0;
}


