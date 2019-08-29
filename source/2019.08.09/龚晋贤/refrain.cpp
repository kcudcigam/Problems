#include<bits/stdc++.h>
using namespace std;
long long n,a[100][100],h[100],s,b[100][100],x,y,c,d,t,i;
int read()
{
  int f=1,s=0;
  char c;
  c=getchar();
  while ('9'<c||c<'0') {
  if (c=='-') f=-1;
  c=getchar();
  }
  while ('0'<=c&&c<='9') {
  s=s*10+c-'0';
  c=getchar();
  }
  return s*f;
}
void wr(int n)
{
  if (n<0) {
  	putchar('-');
  	n*=-1;
  }
  if (n>10) {
  wr(n/10);
  putchar(char(n%10+48));
  }
  else {
  	putchar(char(n%10+48));
  }
}
void dg(int p)
{
	if (p>n) { 
		for (int i=1;i<=n-1;i++)
		for (int j=i+1;j<=n;j++)
		{
			if (a[i][j]==1) {
				if (a[h[i]][h[j]]==0) {
				s++;
				return;
			    }
			}
			if (b[i][j]==1) {
			if (b[h[i]][h[j]]==0) 
			{s++;
			return;
		    }
			}
		} 
	}
	else {
		for (int i=1;i<=n;i++)
		{
			if (h[i]==0) {
				h[i]=p;
				dg(p+1);
				h[i]=0; 
			}
		}
	}
}
int main(){
    freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	cin>>t;
	cin>>n>>x>>y;
	for (i=1;i<=x;i++)
	{
		cin>>c>>d;
		a[c][d]=1;
		a[d][c]=1;
	}
	for (i=1;i<=y;i++)
	{
		cin>>c>>d;
		b[c][d]=1;
		b[d][c]=1;
	}
	dg(1);
	cout<<s%1000000007<<endl;
	return 0;
}


