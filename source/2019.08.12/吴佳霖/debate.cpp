#include<bits/stdc++.h>
using namespace std;
const int maxn=400000+5;
int N;
int m0[maxn],m1[maxn],m2[maxn],m3[maxn];
int tot0,tot1,tot2,tot3;
int ans;
int g1,g2;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		string u;
		cin>>u;	
		int x;
		scanf("%d",&x);
		if(u[0]=='0'&&u[1]=='0')m0[++tot0]=x;
		if(u[0]=='0'&&u[1]=='1')m1[++tot1]=x;
		if(u[0]=='1'&&u[1]=='0')m2[++tot2]=x;
		if(u[0]=='1'&&u[1]=='1')m3[++tot3]=x;
	}
	int gm;
//	g1=min(tot0,tot3);
	g2=min(tot1,tot2);
	if(g2==tot1)gm=tot2;
	else gm=tot1;
	sort(m0+1,m0+tot0+1,cmp);
	sort(m1+1,m1+tot1+1,cmp);
	sort(m2+1,m2+tot2+1,cmp);
	sort(m3+1,m3+tot3+1,cmp);
	for(int i=1;i<=tot3;i++)ans+=m3[i];
	for(int i=1;i<=g2;i++){ans+=m1[i];ans+=m2[i];}
	int k1=0,k2=0;
	if(gm==tot1)for(int i=1;i<=tot3;i++){
		k2++;k1++;
		if(m1[tot2+k2]<m0[k1]){ans+=m0[k1];k2--;}
		else {ans+=m1[tot2+k2];k1--;}
		}
	else for(int i=1;i<=tot3;i++){
		k2++;k1++;	
		if(m2[tot1+k2]<m0[k1]){ans+=m0[k1];k2--;}
		else {ans+=m2[tot1+k2];k1--;}
		}
	printf("%d",ans);
	return 0;
}


