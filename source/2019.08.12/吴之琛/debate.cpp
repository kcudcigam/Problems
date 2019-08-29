#include<bits/stdc++.h>
#define N 400010
using namespace std;
template<typename T> void read(T &x){
	x=0;char c=getchar();T sig=1;
	for (;!isdigit(c);c=getchar()) if (c=='-') sig=-1;
	for (; isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=sig;
}
int n;
struct node{
	int t,w;
};
node a[N];
int ans,k;
int len1,len2,len3;
int s1[N],s2[N],s3[N];
int change(int x){
	if (x==11) return 3;
	if (x==10) return 2;
	return x;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	read(n);
	for (int i=1;i<=n;i++){
		read(a[i].t);
		read(a[i].w);
		a[i].t=change(a[i].t);
	}
	for (int i=1;i<=n;i++){
		if (a[i].t==3){
			ans+=a[i].w;
			k++;
		}
		else
			if (a[i].t==2) s1[++len1]=a[i].w;
			else if (a[i].t==1) s2[++len2]=a[i].w;
			else s3[++len3]=a[i].w;
	}
	sort(s1+1,s1+len1+1,cmp);
	sort(s2+1,s2+len2+1,cmp);
	for (int i=1;i<=min(len1,len2);i++) ans+=s1[i]+s2[i];
	if (len1<len2) for (int i=len1+1;i<=len2;i++) s3[++len3]=s2[i];
	else for (int i=len2+1;i<=len1;i++) s3[++len3]=s1[i];
	sort(s3+1,s3+len3+1,cmp);
	for (int i=1;i<=min(k,len3);i++) ans+=s3[i];
	printf("%d\n",ans);
	return 0;
}

