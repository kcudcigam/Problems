#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	int f=1,r=0; char ch;
	do ch=getchar(); while(!isdigit(ch)&&ch!='-');
	if(ch=='-'){f=-1;ch=getchar();}
	do r=r*10+ch-48,ch=getchar(); while(isdigit(ch));
	x=f*r;
}
struct info{int num,val;}s[1000010];
int n,alen=0,blen=0,t=0,sum1=0,sum2=0;
int p[1000010][3],used[1000010];
vector<info> a,b;
bool cmp(info a,info b){
	return a.val>b.val;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string str;cin>>str;
		int val;read(val);
		s[++t]=(info){i,val};
		if(str[0]=='1'){
			a.push_back((info){i,val});
			sum1+=val;alen++;
			p[i][1]=1;
		}
		if(str[1]=='1'){
			b.push_back((info){i,val});
			sum2+=val;blen++;
			p[i][2]=1;
		}
	}
	if(alen<=blen){
		sort(b.begin(),b.end(),cmp);
		int tot=alen,ans=sum1,cnt=0,totp=alen;
		for(int i=0;i<blen;i++){
			int x=b[i].num;
			if(p[x][1]==1){
				cnt++;
				used[x]=1;
			}
		}//支持b的且支持a的
		if(cnt!=tot){ //支持b的不够 
			for(int i=0;i<blen;i++){
				if(cnt==tot)break;
				int x=b[i].num;
				if(p[x][1]==0&&!used[x]){
					ans+=b[i].val;
					cnt++;totp++;
					used[x]=1;
				}
			}
		} 
		if(totp<tot*2){//总人数不够 
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(totp==tot*2)break;
				int x=s[i].num;
				if(p[x][1]==0&&!used[x]){
					ans+=s[i].val;
					totp++;
				}
			}
		}
		cout<<ans<<endl;
	}
	if(alen>blen){
		sort(a.begin(),a.end(),cmp);
		int tot=blen,ans=sum2,cnt=0,totp=blen;
		for(int i=0;i<alen;i++){
			int x=a[i].num;
			if(p[x][2]==1){
				cnt++;
				used[x]=1;
			}
		}//支持b的且支持a的
		if(cnt!=tot){ //支持a的不够 
			for(int i=0;i<alen;i++){
				if(cnt==tot)break;
				int x=a[i].num;
				if(p[x][2]==0&&!used[x]){
					ans+=a[i].val;
					cnt++;totp++;
					used[x]=1;
				}
			}
		} 
		if(totp<tot*2){//总人数不够 
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(totp==tot*2)break;
				int x=s[i].num;
				if(p[x][2]==0&&!used[x]){
					ans+=s[i].val;
					totp++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
6
11 6
10 4
01 3
00 3
00 7
00 9
6
11 19
10 22
00 18
00 29
11 29
10 28
*/ 


