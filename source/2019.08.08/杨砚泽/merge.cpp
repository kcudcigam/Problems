#include<bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x)
{
  int f=1;x=0;
  char ch=getchar();
  for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
  for (;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
  x=x*f;
}
long long p[10051],sum[10051];
string s[10051]={""};
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
    int n,q,x,y,z;
    read(n);read(q);
    memset(sum,0,sizeof(sum));
    for (int i=1;i<=n;i++)
      {
      	p[i]=i;
      	s[i]+=char(i+48);
	  }
    for (int i=1;i<=q;i++)
    {
    	read(x);
        if (x==1)
        {
        	read(y);read(z);
        	if (y>z) swap(y,z);
		   if (p[y]!=p[z]){
		   	for (int j=0;j<s[y].size();j++)
		     p[s[y][j]-48]=p[z];
		    s[z]=s[z]+s[y];
		    s[y]="";
		   }
		}
	    if (x==2)
		{
			read(y);read(z);
			int k=p[y];
			for (int j=0;j<s[k].size();j++)
			  sum[s[k][j]-48]+=z;
			}	
	}
	for (int i=1;i<=n;i++)
	  cout<<sum[i]<<" ";
	  cout<<endl;
	
	return 0;
}

