#include<bits/stdc++.h>
using namespace std;
long long a,b,c,t,tt,n[10000010],p,pp;
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(a);
	for (int i=1;i<=a;i++)
	{
		read(b);read(c);
		n[1]=0%c;n[2]=2%c;n[3]=12%c;n[4]=58%c;t=14%c;tt=16%c;
		p=6%c;pp=10%c;
		for (int j=5;j<=b;j++)
		{
			if (j%2==1)
			{
				p=(p+t)%c;
				n[j]=(n[j-1]*j+p)%c;
				t=(t+8)%c;			
			}
			else
			{
				pp=(pp+tt)%c;
				n[j]=(n[j-1]*j+pp)%c;
				tt=(tt+8)%c;
			}
		}
		cout<<n[b]<<endl;
	}
	return 0;
}


