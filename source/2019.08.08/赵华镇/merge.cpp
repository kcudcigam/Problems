#include<bits/stdc++.h>
using namespace std;
long long f[1000005],s[1000005];
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
long long find(long long x)
{
	if(f[x]==x){
		return x;
	}
	else{
		f[x]=find(f[x]);
	}
}
void hb(long long p,long long q)
{
	long long p1,q1;
	p1=find(p);
	q1=find(q);
	if(p1!=q1){
		f[p1]=q1;
	}
}
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	long long n,q,i,j,k,x,y;
	read(n);read(q);
	for(i=1;i<=n;i++){
		f[i]=i;
	}
	for(i=1;i<=q;i++){
		read(k);read(x);read(y);
		if(k==1){
			hb(x,y);
		}
		else{
			for(j=1;j<=n;j++){
				if(find(j)==find(x)){
					s[j]+=y;
				}
			}
		}
	}
	for(i=1;i<=n;i++){
		printf("%lld ",s[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

