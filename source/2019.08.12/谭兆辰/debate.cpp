#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
#define N 400400
int a[5][N],tot1=0,tot2=0,tot3=0,tot4=0;
inline void read(int &x){
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	x=s*w;
	return ;
}
#include <algorithm>
int l[N],r[N];
char s[3];
inline bool cmp(int x,int y){
	return x>y;
}
int ans=0;
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		l[i]=s[1]-'0',r[i]=s[2]-'0';
		if(!l[i]){
			if(!r[i]) read(a[1][++tot1]);//00 
			else read(a[2][++tot2]);//01
		}
		else{
			if(!r[i]) read(a[3][++tot3]);//10
			else read(a[4][++tot4]);//11
		}
	}
	sort(a[1]+1,a[1]+1+tot1,cmp),sort(a[2]+1,a[2]+1+tot2,cmp),sort(a[3]+1,a[3]+1+tot3,cmp),sort(a[4]+1,a[4]+1+tot4,cmp);
	for(int i=1;i<=tot4;i++){
		ans+=a[4][i];
	}
	for(int i=1;i<=min(tot2,tot3);i++){
		ans+=a[2][i]+a[3][i];
	} 
	int k=tot4,le,ri;
	if(tot2<tot3){
		le=1,ri=tot2+1;
		while(k>0&&le<=tot1&&ri<=tot3){
			if(a[1][le]>a[3][ri]) ans+=a[1][le],le++;
			else ans+=a[3][ri],ri++;
			k--;
		}
		if(k>0){
			if(le<=tot1){
				for(int i=le;i<=tot1&&k>0;i++) ans=ans+a[1][i],k--;
			}
			if(ri<=tot3){
				for(int i=ri;i<=tot3&&k>0;i++) ans=ans+a[3][i],k--;
			}
		}
	}
	else{
		le=1,ri=tot3+1;
		while(k>0&&le<=tot1&&ri<=tot2){
			if(a[1][le]>a[2][ri]) ans+=a[1][le],le++;
			else ans+=a[2][ri],ri++;
			k--;
		}
		if(k>0){
			if(le<=tot1){
				for(int i=le;i<=tot1&&k>0;i++) ans=ans+a[1][i],k--;
			}
			if(ri<=tot2){
				for(int i=ri;i<=tot2&&k>0;i++) ans=ans+a[2][i],k--;
			}
		}
	}
	cout<<ans;
	return 0;
}
