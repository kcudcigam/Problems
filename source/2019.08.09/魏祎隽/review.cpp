#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct st{int x,y;};basic_string<st> e;
ll y,x=1;int t=2,f=0;
int main(){
	freopen("review.in","r",stdin),freopen("review.out","w",stdout);
	cin>>y;
	for(;x<y;x*=2,t++);
	printf("%d ",t);
	for(int i=2;i<t;i++)for(int j=1;j<i;j++)e+={j,i};
	if(!(y&y-1))y--,f=1;
	for(int k=t-1;k>=2;k--)if(y>>k-2&1)e+={k,t};
	if(f)e+={1,t};
	printf("%zu\n",e.size());
	for(st&x:e)printf("%d %d\n",x.x,x.y);
	return 0;
}
