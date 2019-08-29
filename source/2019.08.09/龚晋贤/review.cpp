#include<bits/stdc++.h>
using namespace std;
long long y,cnt,k,a[2000000],b[2000000],i;
string x;
long long read()
{
  long long f=1,s=0;
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
int main(){
    freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	y=read();
	while (y!=0) {
		x+=char(y%3+'0');
		y=y/3;
	}
	cnt=1;
	k=0;
	for (i=0;i<x.size();i++)
	{
		k++;
		a[k]=cnt; b[k]=cnt+1;
		k++;
		a[k]=cnt; b[k]=cnt+2;
		k++;
		a[k]=cnt; b[k]=cnt+3;
		k++;
		a[k]=cnt+1; b[k]=cnt+4;
		k++;
		a[k]=cnt+2; b[k]=cnt+4;
		k++;
		a[k]=cnt+3; b[k]=cnt+4; 
		if (x[i]=='1') {
			k++;
			a[k]=cnt+1; b[k]=0;
		}
		if (x[i]=='2') {
			k++;
			a[k]=cnt+1; b[k]=0;
			k++;
			a[k]=cnt+2; b[k]=0;
		}
		cnt+=4;
	}
	cnt+=1;
	printf("%d",cnt); putchar(' ');printf("%d\n",k);
	for (i=1;i<=k;i++)
	{
	  printf("%d",a[i]); putchar(' ');if (b[i]==0) printf("%d\n",cnt);
	  else printf("%d\n",b[i]);	
	} 
	return 0;
}


