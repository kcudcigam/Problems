#include<bits/stdc++.h>
#define N 10010
#define ll long long
using namespace std;
ll n,k,pre[50],qz[50],qzh[50],num[50],ans=1000000000000,p2,id,hash[50],tot=1;
template<typename T>inline void read(T &x)
{ x=0;
 int f=1;
 char c=getchar();
 while (!isdigit(c))
 {  if (c=='-') f=-1;
   c=getchar();}
while (isdigit(c))
{ x=(x<<3)+(x<<1)+(c^48);
  c=getchar();}
x*=f;}
ll write(ll x)
{   if (x<0)
	 {putchar('-');write(-x);}
	if (x/10)  write(x/10);
	putchar(x%10+48);
}
int main(){
  freopen("glass.in","r",stdin);
  freopen("glass.out","w",stdout);
   read(n);read(k);
   pre[1]=2;
   while (pre[tot]*2<=1000000000)
   {   tot++;  
     pre[tot]=pre[tot-1]*2;}
    tot++;pre[tot]=pre[tot-1]*2;
    memset(qz,0,sizeof(qz));
    memset(hash,0,sizeof(hash));
    id=tot;
   for (id;id>=1;id--)
      if (n>pre[id]) break;
   for (ll i=tot;i>id;i--)
         num[i]=0;
    while (id>=1)
    {   p2++; num[id]=pre[id];
        hash[id]=1;
        n-=pre[id];
        while (id>=1&&n<pre[id])  id--;
	}
	if (n+p2<=k)  {cout<<0<<endl;return 0;}
	qzh[0]=n;
	qz[0]=n;
	for (ll i=1;i<=tot;i++)
	  { qzh[i]=qzh[i-1]+num[i];
	   qz[i]=qz[i-1]+hash[i];}
	for (ll i=1;i<=tot;i++)
	{  ll o=(pre[i]-qzh[i-1]);
	    ll red=qz[i-1];
	   if (hash[i]) red++;
	   red--; 
	  if (qz[tot]-red<=k)
	     ans=min(ans,o);
	}
	write(ans);
	puts("");
	return 0;
}

