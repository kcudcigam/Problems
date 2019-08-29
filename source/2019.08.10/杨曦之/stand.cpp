#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10;
int st[maxn],info[maxn][maxn],n,m,cnt=0,maxq[maxn],tmp[maxn],jojo=0;
struct JOJO{
	int l,r;
}jo[maxn];
bool vis[maxn];
long long fun[7];
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int i,f,j,k,cnm,tcnm,det;
	long long ans=0,Max;
	scanf("%d%d",&n,&m);
	for(i=1;i<=5;i++) scanf("%lld",&fun[i]);
	for(i=1;i<=n;i++){
		scanf("%d%d",&jo[i].l,&jo[i].r);
		if(jo[i].l==1&&jo[i].r==m) jojo++;
	}
	if(jojo==n){
		Max=n;
		ans=fun[1]*Max+fun[2]*Max*Max+fun[3]*Max*Max*Max+fun[4]*Max*Max*Max*Max+fun[5]*Max*Max*Max*Max*Max;
	}
	else while(cnt<n){
		memset(info,0,sizeof(info));
		memset(st,0,sizeof(st));
		Max=0;
		for(i=1;i<=n;i++){
			if(vis[i]) continue;
			for(j=jo[i].l;j<=jo[i].r;j++) st[j]++,info[j][++info[j][0]]=i;
		}
		f=0;
		for(i=1;i<=m;i++){
			if(st[i]>Max) f=0,maxq[++f]=i,Max=st[i];
			if(st[i]==Max) maxq[++f]=i;
		}
		ans+=fun[1]*Max+fun[2]*Max*Max+fun[3]*Max*Max*Max+fun[4]*Max*Max*Max*Max+fun[5]*Max*Max*Max*Max*Max;
		cnm=0;
		for(i=1;i<=f;i++){
			tcnm=0;
			for(j=1;j<=m;j++) tmp[j]=st[j];
			for(j=1;info[maxq[i]][j];j++){
				for(k=jo[info[maxq[i]][j]].l;k<=jo[info[maxq[i]][j]].r;k++) tmp[k]--;
			}
			for(j=1;j<=m;j++) tcnm=max(tcnm,tmp[j]);
			if(tcnm>=cnm){
				cnm=tcnm;
				det=i;
			}
		}
		for(i=1;info[maxq[det]][i];i++){
			vis[info[maxq[det]][i]]=1;
			cnt++;
		}
	}
	printf("%lld",ans);
	return 0;
}

