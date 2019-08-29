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
int a[1051],x[1051],y[1051],s1[1051],s2[1051];
int sum=0;
int n,c;
int hash1[10051];
void dfs(int num,int dep)
{	
	if (dep>n)
	{
		if (num==c) {
			int flag=1,p=0;
			for (int i=1;i<=a[n];i++)
			  if (hash1[i]>0) p=p+i*hash1[i];
			p=p-c;
			for (int i=1;i<=a[n];i++)
			  if (hash1[i]>0) {
			  	if (i<=p) flag=0;
			  	break;
			  } 
			if (flag==1)sum++;
		}
		return ;
	}
	if (num+s1[dep]<0) return ;
	if (num-s2[dep]>0) return ;
	for (int i=-y[dep];i<=x[dep];i++)
	  {
	  	hash1[a[dep]]=i;
	  	dfs(num+a[dep]*i,dep+1);
	  }
}
int main(){
    freopen("deal.in","r",stdin);
    freopen("deal.out","w",stdout);
    read(n);read(c);
    for (int i=1;i<=n;i++)
      {read(a[i]);  
	  read(x[i]);  
	  read(y[i]);
	   } 
	   memset(s1,0,sizeof(s1));
	   memset(s2,0,sizeof(s2));
    for (int i=n;i>=1;i--)
      {
      	s1[i]=s1[i+1]+x[i]*a[i];
      	s2[i]=s2[i+1]+y[i]*a[i];
	  }
    dfs(0,1);
    cout<<sum<<endl;
	return 0;
}


