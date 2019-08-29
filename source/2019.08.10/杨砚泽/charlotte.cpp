#include<bits/stdc++.h>
using namespace std;
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
	int t;
	int x;
	int y;
};
node p[100051];
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
    int NUM,n;
    read(NUM);
    for (int P=1;P<=NUM;P++)
    {
    	read(n);
    	for (int i=1;i<=n;i++)
    	  {
    	  	read(p[i].t);read(p[i].x);read(p[i].y);
		  }
		int xx=0,yy=0;
		bool flag=true;
		p[0].t=0;
		for (int i=1;i<=n;i++)
		{
			int low=abs(p[i].x-xx)+abs(p[i].y-yy);
			if (p[i].t-p[i-1].t<low) {
				flag=false;
				break;
			} 
			if ((p[i].t-p[i-1].t-low)%2==1)
			{
				flag=false;
				break;
							}
			xx=p[i].x;
			yy=p[i].y;
		} 
	    if (flag==false) cout<<"No"<<endl;
	    else cout<<"Yes"<<endl;
	}
	return 0;
}
/*
3
2
3 1 2
6 1 1
1
2 100 100
2
5 1 1
100 1 1
*/

