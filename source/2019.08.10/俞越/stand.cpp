#include<bits/stdc++.h>
#define LL long long
#define ms(a,b) memset(a,b,sizeof a)
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=505;
LL f[M],w[10],n,m;
int t[M<<1],tt,N;
struct node{
	int x,y;
}a[M];
namespace DD{
	int d[M];
	int ans=0;
	void dfs(int x){
		if (x==n+1){
			int tmp=0;
			F(i,1,N) tmp+=f[d[i]]; 
			ans=max(ans,tmp);
			return ;
		}
		for (int i=a[x].x;i<=a[x].y;i++){
			d[i]++;
			dfs(x+1);
			d[i]--;
		}
	}
	void solve(){
		dfs(1);
		cout<<ans<<"\n";
	}
}
namespace fuck{
	bool h[M];
	int s[M];
	void solve(){
		LL ans=0;
		int o=n;
		while (o){
			ms(s,0);
			F(i,1,n){
				if (h[i]) continue;
				s[a[i].x]++; s[a[i].y+1]--;
			}
			F(i,1,N) s[i]+=s[i-1];
			int tmp=0,mx=0;
			for (int i=1;i<=N;i++){
//				cout<<s[i]<<" ";
				if (s[i]>mx) mx=s[i],tmp=i;
			}
//			cout<<mx<<" "<<tmp<<"\n";
			ans+=f[mx]; o-=mx;
			F(i,1,n){
				if (h[i]) continue;
//				cout<<a[i].x<<" "<<a[i].y<<" "<<tmp<<" GGG\n";
				if (a[i].x<=tmp && a[i].y>=tmp) h[i]=1;
			}
//			cout<<o<<"\n";
//			system("pause");
		}
		cout<<ans<<"\n";
	}
}
namespace dddd{
	LL dp[M][M];
	pair<int,int> ll[M][M],rr[M][M];
	int cc;
	LL dfs(int l,int r){
		if (l>r) return 0;
		if (dp[l][r]) return dp[l][r];
		cc=0;
//		cout<<l<<" "<<r<<"\n";
		vector<node> temp;
		F(i,1,n){
			if (a[i].x>=l && a[i].y<=r) temp.pb(a[i]);
		}
		LL ttt=0;
		F(i,l,r){
			int num=0,nl=N,nr=0,nll=N,nrr=0;
			F(j,0,SZ(temp)){
				if (temp[j].x<=i && temp[j].y>=i) num++;
				else {
					if (temp[j].y<i){
						nl=min(nl,temp[j].x);
						nr=max(nr,temp[j].y);
					}
					else {
						nll=min(nll,temp[j].x);
						nrr=max(nrr,temp[j].y);
					}
				}
			}
//			cout<<l<<" - "<<r<<" cut: "<<i<<" number: "<<num<<"   ("<<nl<<" "<<nr<<" "<<nll<<" "<<nrr<<")\n";
			ttt=max(ttt,dfs(nl,nr)+f[num]+dfs(nll,nrr));
		}
		return dp[l][r]=ttt;
	}
	LL ddfs(int l,int r){
		if (l>r) return 0;
		if (dp[l][r]) return dp[l][r];
		cc=0;
//		cout<<l<<" "<<r<<"\n";
		int s[M];
		ms(s,0);
		F(i,1,n){
			if (a[i].x>=l && a[i].y<=r)
			s[a[i].x]++,s[a[i].y+1]--;
		}
		F(i,1,N) s[i]+=s[i-1];
//		cout<<"        hh\n";
		LL ttt=0;
		F(i,l,r){
			int nl,nll,nr,nrr;
			nl=ll[i][l].first; nr=ll[i][l].second;
			nll=rr[i][r].first; nrr=rr[i][r].second;
//			cout<<l<<" - "<<r<<" cut: "<<i<<" number: "<<s[i]<<"   ("<<nl<<" "<<nr<<" "<<nll<<" "<<nrr<<")\n";
//			system("pause");
			ttt=max(ttt,ddfs(nl,nr)+f[s[i]]+ddfs(nll,nrr));
		}
		return dp[l][r]=ttt;
	}
	bool cmp(node A,node B){
		return A.x>B.x;
	}
	bool cmpp(node A,node B){
		return A.y<B.y;
	}
	void solve(){
		vector<node> vl,vr;
		F(i,1,N){
			vl.clear(); vr.clear();
//			int mr=0,ml=N;
			F(j,1,n){
				if (a[j].x<=i && a[j].y>=i) continue;
					if (a[j].y<i){
						vl.pb(a[j]);
//						mr=max(mr,a[j].y);
					}
					else {
						vr.pb(a[j]);
//						ml=min(ml,a[j].x);
					}			
			}
			vl.pb((node){-1,-1});
			vr.pb((node){N+1,N+1});
			sort(vl.begin(),vl.end(),cmp);
			sort(vr.begin(),vr.end(),cmpp);
//			cout<<i<<" "<<SZ(vl)+1<<" "<<SZ(vr)+1<<"\n";
			int nowl=N,nowr=0,lst=i;
			
			if (!(SZ(vl)+1)){
				F(j,1,i) ll[i][j]=make_pair(nowl,nowr);
			}
			if (!(SZ(vr)+1)){
				F(j,i,N) rr[i][j]=make_pair(nowl,nowr);
			}
			F(j,0,SZ(vl)){
//				cout<<lst<<" "<<vl[j].x<<"    GGGGGGGGGGGGGG\n";
				DF(kk,lst,vl[j].x+1){ 
					ll[i][kk]=make_pair(nowl,nowr);	
//					cout<<nowl<<" "<<nowr<<" "<<i<<" "<<kk<<"  HHHGFF\n";
				}
				lst=vl[j].x;
				nowl=min(nowl,vl[j].x); nowr=max(nowr,vl[j].y);
			}
			nowl=N,nowr=0,lst=i;
			F(j,0,SZ(vr)){
				F(kk,lst,vr[j].y-1){
					rr[i][kk]=make_pair(nowl,nowr);	
				}
				lst=vr[j].y;
				nowl=min(nowl,vr[j].x); nowr=max(nowr,vr[j].y);
			}
		}
		cout<<ddfs(1,N)<<"\n";
	}
	
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	n=read(); m=read();
	F(i,1,5) w[i]=read();
	F(i,1,n) {
		LL tmp=i;
		F(j,1,5)
		f[i]+=tmp*w[j],tmp*=i;
	}
	F(i,1,n){
		a[i].x=read(); a[i].y=read();
		t[++tt]=a[i].x; t[++tt]=a[i].y;
	}
	sort(t+1,t+tt+1);
	N=unique(t+1,t+tt+1)-t-1;
//	LL ti=0;
	for (int i=1;i<=n;i++) {
		a[i].x=lower_bound(t+1,t+N+1,a[i].x)-t;
		a[i].y=lower_bound(t+1,t+N+1,a[i].y)-t;
//		cout<<a[i].x<<" "<<a[i].y<<"\n";
//		ti*=(a[i].y-a[i].x+1);
	}
	dddd::solve();
	return 0;
}

