#include<bits/stdc++.h>
using namespace std;
int n,m,a,a1,a2,a3,fro[10000000],q[10000000],b;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
void hb(int n,int m)
{
	while (m!=fro[m])
	  m=fro[m];
	while (n!=fro[n])
	  {
	  	int p=n;
	  	n=fro[n];
	  	fro[p]=m;
	  } 
	fro[n]=m;
}
void cz(int m,int n)
{
	while (m!=fro[m])
	  m=fro[m];
	for(int i=1;i<=a;i++)
	   if (fro[i]==m)
	    q[i]+=n;
} 
int main ()
{
	ios::sync_with_stdio(false);
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	read(a);
	read(b);
	for (int i=1;i<=a;i++)
	  {
	  	fro[i]=i;
	  	q[i]=0;
	  }
	for (int i=1;i<=b;i++)
	  {
	  	read(a1);
		read(a2);
		read(a3);
		if (a1==1)
		hb(a2,a3);
		else cz(a2,a3);
	  }
	for (int i=1;i<a;i++)
	  cout<<q[i]<<" ";
	cout<<q[a]<<endl; 
	return 0;  
}

