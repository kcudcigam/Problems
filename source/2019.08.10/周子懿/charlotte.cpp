#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=11;
const int P=100010;
typedef struct node
{
	int x,y,t;
}Note;
Note n[N][P];
int T,num[N];
template <typename T> inline void read(T &x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(f!='-')f=-f;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	x*=f;
}
bool cmp(Note p,Note q)
{
	if(p.t<q.t)return true;
	return false;
}
void init()
{
	read(T);
	for(int i=1;i<=T;i++)
	{
		read(num[i]);
		for(int j=1;j<=num[i];j++)
		{
			read(n[i][j].t);
			read(n[i][j].x);
			read(n[i][j].y);
		}
	}
}
void work()
{
	int nowx,nowy,nowt,pd;
	for(int i=1;i<=T;i++)
	{
		pd=0;nowx=0;nowy=0;nowt=0;
	//	sort(n[i]+1,n[i]+num[i]+1,cmp);
		for(int j=1;j<=num[i];j++)
		{
			if(abs(nowx-n[i][j].x)+abs(nowy-n[i][j].y)>n[i][j].t-nowt)
			{
				pd=1;break;
			}else if((n[i][j].t-nowt-abs(nowx-n[i][j].x)-abs(nowy-n[i][j].y))%2>0){
				pd=1;break;
			}else
			{
				nowx=n[i][j].x;nowy=n[i][j].y;nowt=n[i][j].t;
			}
		}
		if(pd==1)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	init();
	work();
	return 0;
}


