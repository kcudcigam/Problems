#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>

#define LL long long
#define fgx cerr<<"-------------"<<endl;
using namespace std;

inline LL read(){
	LL x=0,f=1; char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const LL INF = 1000483600;
const LL MAXN = 200010;
const LL Mod = 1000000007LL;

LL N,M,Q;

#define pii pair<LL,LL>
#define fr first
#define sc second

struct data{
	LL l,r;
}q[MAXN+1]; LL sta[MAXN+1],top;
bool cmp(data a,data b){ return a.l<b.l; }
inline LL Pow(LL a,LL b){ LL ret=1; for(;b;b>>=1,a=a*a%Mod) if(b&1) ret=ret*a%Mod; return ret; }
vector<pii > vec[MAXN+1],ans[MAXN+1];
LL f[MAXN+1],g[MAXN+1],tmp[MAXN+1];
bool cmp2(pii a,pii b){
	return abs(a.fr)<abs(b.fr);
}
vector<pii > tp;

int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	N=read(),M=read(),Q=read();
	for(LL i=1;i<=M;i++){
		LL x=read(),y=read(),p=read();
		sta[++top]=y;
		vec[x].push_back(make_pair(y,p));
	}
	sort(sta+1,sta+top+1);
	top=unique(sta+1,sta+top+1)-sta-1;
	for(LL i=1;i<=N;i++)
		for(LL j=0,l=vec[i].size();j<l;j++)
			vec[i][j].fr=lower_bound(sta+1,sta+top+1,vec[i][j].fr)-sta; 
	for(LL i=1;i<=N;i++){
		LL prodno=1;
		sort(vec[i].begin(),vec[i].end());
		ans[i].push_back(make_pair(0,0));
		for(LL j=0,ed=0,l=vec[i].size();j<l;j=ed){
			LL no=1;
			ed=j; while(ed<l&&vec[i][ed].fr==vec[i][j].fr) 
				no=no*(Mod+1-vec[i][ed].sc)%Mod,++ed;
			ans[i].push_back(make_pair(vec[i][j].fr,(Mod+1-no)*prodno%Mod));
			prodno=prodno*no%Mod;
		}
		ans[i][0].sc=prodno; LL pp=0;
		//fgx;
		//cout<<i<<endl;
		for(int j=0;j<ans[i].size();j++) pp+=ans[i][j].sc;//cout<<ans[i][j].fr<<" "<<ans[i][j].sc<<endl;
	}
	for(LL i=1;i<=Q;i++){
		q[i].l=read(),q[i].r=read();
	} sort(q+1,q+Q+1,cmp);
	for(LL i=0;i<=top;i++) f[i]=1;
	if(N<=1000&&M<=5000){
		LL dw=0,dt=0,l,cnt=0;
		for(LL i=1;i<=N;i++){
			LL ret=0,now=0;
			if(q[dw+1].r==i-1){
				++dw;
				//fgx;
				for(LL j=0;j<=top;j++) (g[j]+=(tmp[j]?0:f[j]))%=Mod;//cout<<(tmp[j]?0:f[j])<<" ";
				//cout<<endl;
				//cout<<"pp:"<<i<<endl;
				for(LL j=q[dw].l;j<min(q[dw+1].l,i);j++){
					now=0,l=ans[j].size(); ret=0;
					for(LL k=0;k<=top;k++){
						while(now<l&&ans[j][now].fr==k) 
							(ret+=ans[j][now].sc)%=Mod,++now;
						if(ret) f[k]=f[k]*Pow(ret,Mod-2)%Mod;
						else tmp[k]--;
					}
				} 
				//for(LL j=0;j<=top;j++)
				//	cout<<f[j]<<" ";
				//	cout<<endl;
				--cnt;
			}
			if(q[dt+1].l==i){ ++dt; ++cnt; }
			if(cnt){
				now=0; l=ans[i].size(); ret=0;
				for(LL j=0;j<=top;j++){
					while(now<l&&ans[i][now].fr==j) (ret+=ans[i][now].sc)%=Mod,++now;
					if(ret) f[j]=f[j]*ret%Mod;
					else tmp[j]++;
				}
			}
		} 
		if(q[dw+1].r==N){
			++dw;
			for(LL j=0;j<=top;j++) (g[j]+=(tmp[j]?0:f[j]))%=Mod;//cout<<f[j]<<" ";
			//cout<<endl;
		}
		LL Ans=0;
		for(LL i=top;i>=1;i--){
			g[i]=(g[i]-g[i-1]+Mod)%Mod;
			Ans=(Ans+g[i]*sta[i]%Mod)%Mod;
		} printf("%lld\n",Ans);
	}
	else{
		if(Q==N){
			for(int i=1;i<=N;i++){
				for(int j=0;j<ans[i].size();j++)
					(g[ans[i][j].fr]+=ans[i][j].sc)%=Mod;
			} LL Ans=0;
			for(int i=1;i<=top;i++){
				Ans=(Ans+g[i]*sta[i]%Mod)%Mod;
			} printf("%lld\n",Ans);
		}
		else{
			LL Ans=0;
			for(int i=1;i<N;i++){
				tp.clear();
				for(int j=1;j<ans[i].size();j++)
					tp.push_back(make_pair(ans[i][j].fr,ans[i][j].sc));
				for(int j=1;j<ans[i+1].size();j++)
					tp.push_back(make_pair(-ans[i+1][j].fr,ans[i+1][j].sc));
				sort(tp.begin(),tp.end(),cmp2);
				LL ret0=0,ret1=0;
				ret0+=ans[i][0].sc;
				ret1+=ans[i+1][0].sc;
				(g[0]+=ret0*ret1%Mod)%=Mod;
				for(int j=0;j<tp.size();j++){
					int x=tp[j].first;
					cout<<x<<" ";
					if(x<0) (ret1+=tp[j].second)%=Mod;
					else (ret0+=tp[j].second)%=Mod;
					if(j==tp.size()-1||(abs(tp[j+1].fr)-abs(tp[j].fr)>0)){
						(f[abs(x)]+=ret0*ret1%Mod)%=Mod;
						if(j!=tp.size()-1) (f[abs(tp[j+1].fr)]+=Mod-ret0*ret1%Mod)%=Mod;
					}
				} cout<<endl;
			}
			for(int i=1;i<=top;i++) f[i]=(f[i]+f[i-1])%Mod;
			for(int i=1;i<=top;i++) g[i]=(g[i]+f[i])%Mod;
			for(int i=top;i>=1;i--){
				g[i]=(g[i]-g[i-1]+Mod)%Mod;
				Ans=(Ans+g[i]*sta[i]%Mod)%Mod;
			}
			printf("%lld\n",Ans);
		}
	}
	return 0;
}

