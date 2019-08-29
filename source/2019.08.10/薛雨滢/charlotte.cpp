#include<bits/stdc++.h>

using namespace std;
const int MAXN=100005;
int n,T;

struct Pla
{
	int t,x,y;
	bool operator <(const Pla &b)
	const
	{
		return t<b.t;
	}
}pla[MAXN];

void read(int &p)
{
	char s=getchar();int flag=1;p=0;
	while(!isdigit(s))
	{
		if(s=='-') flag=-1;
		s=getchar();
	}
	for(;isdigit(s);s=getchar()) p=p*10+s-'0';
	p*=flag;
 } 


bool check(int num)
{
	if(num==n+1) return 1;
	int tem=abs(pla[num].x-pla[num-1].x)+abs(pla[num].y-pla[num-1].y);
	int t=pla[num].t-pla[num-1].t;
	
	if(t<tem||t==0) return 0;
	else
	{
		if(t>=tem&&(t-tem)%2==0) return check(num+1);
		else return 0;
	}
}



int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	read(T);
	while(T)
	{
		T--;
		read(n);
		for(int i=1;i<=n;i++)
		{
			read(pla[i].t);read(pla[i].x);read(pla[i].y);
		}
		//sort(pla+1,pla+n+1);
		if(check(1)) puts("Yes");
		else puts("No");
	}
	return 0;
}
