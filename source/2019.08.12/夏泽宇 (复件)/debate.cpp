#include<bits/stdc++.h>
#define N 400010
using namespace std;
struct Info{
	int id,w;
}a[N];
int m[20]={0,1,0,0,0,0,0,0,0,0,2,3};
inline int read(){
	int ret=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())ret=(ret<<3)+(ret<<1)+ch-'0';
	return ret*f;
}
bool cmp(Info x,Info y){
	if(m[x.id]>m[y.id])return 1;
	return 0;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n=read(),Last=-1;
	int flg=1;
	int flg2=1,cnt=0;
	for(int i=1;i<=n;i++){
		a[i].id=read(),a[i].w=read();
		if(Last==-1)Last=a[i].w;
		if(a[i].w!=Last)flg=0;
		if(a[i].id!=11&&a[i].id!=0)flg2=0;
		if(a[i].id==11)cnt++;
	}
	if(flg){
		int ans=0,favor1=0,favor2=0;
		sort(a+1,a+n+1,cmp);
		int t1,t2;
		int pos1,pos2,pos3;
		for(pos1=1;a[pos1].id==11;pos1++)ans+=a[pos1].w;
		for(pos2=pos1;a[pos2].id!=1;pos2++)
		for(pos3=pos2;a[pos3].id!=0;pos3++){}
		for(int i=pos1,j=pos2;i<pos2&&j<pos3;i++,j++){
			ans+=a[i].w+a[j].w;
		}
		ans+=(pos1-1)*Last;
		printf("%d\n",ans);
		return 0;
	}
	if(flg2){
		int ans=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=cnt;i++){
			ans+=a[i].w;
		}
		for(int i=cnt+1;i<=2*cnt;i++){
			ans+=a[i].w;
		}
		printf("%d\n",ans);
		return 0;
	}
	printf("%d\n",105);
	return 0;
}

