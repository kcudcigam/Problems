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
int a[100051],b[100051];
priority_queue<int> t;
int main(){
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
    int n,m,T,x,y,z,l1,r1,l2,r2;
    read(n);read(m);
    for (int i=1;i<=n;i++)
    {
    	read(a[i]);
	}
      
    for (int i=1;i<=n;i++)
    {
    	read(b[i]);
	}
    for (int i=1;i<=n;i++)
    {
    	read(T);
    	if (T==1)
    	{
    		read(x);read(y);read(z);
    		if (x==0) a[y]=z;
    		else b[y]=z;
		}
		else {
			read(l1);read(r1);read(l2);read(r2);
			while (!t.empty()) t.pop();
		    for (int i=l1;i<=r1;i++)
		      t.push(a[i]);
		    for (int i=l2;i<=r2;i++)
		      t.push(b[i]);
		    int mid=r1-l1+r2-l2+2>>1;
		    mid++;
		    int sum=1;
		    while (sum!=mid)
		    {
		    	t.pop();
		    	sum++;
			}
			cout<<t.top()<<endl;
		}
	}
    
	return 0;
}

