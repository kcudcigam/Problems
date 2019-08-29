#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
template<typename T> void chkmax(T &x,T y){x=x>y?x:y;}
vector<int>v[4];int w[4][5010];
inline int t(string c){
	if(c=="00")return 0;
	if(c=="01")return 1;
	if(c=="10")return 2;
	if(c=="11")return 3;
}

int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);

	int n;read(n);
	int su1=1;int su2=0;
	rep(i,1,n){
		string ch;cin>>ch;int x;read(x);int temp=t(ch);
		v[temp].push_back(-x);
		su1&=(temp==0||temp==3);
		if(!su2){su2=x;}
		else{su2=((su2==x)?x:-1);}
	}
	rep(i,0,3)sort(v[i].begin(),v[i].end());
	rep(i,0,2){
		rep(j,0,(int)(v[i].size()-1))w[i][j+1]=w[i][j]-v[i][j];
	}
	
	int ans=0;
	rep(i,0,(int)(v[3].size()-1))ans-=v[3][i];
	if(su1){
		write(ans+w[0][min((int)v[0].size(),(int)v[3].size())]);
	}else if(su2!=-1){
		int n1=(int)v[1].size();int n2=(int)v[2].size();
		int n3=(int)v[3].size();int nop=n3;
		if(n1>n2)swap(n1,n2);
		if(2*(n1+n3)>=n1+n2+n3){
			nop+=n1+n2+min(n1+n3-n2,(int)v[0].size());
		}else{nop+=n1+n1+n3;}
		write(nop*su2);
	}else{
		int mx=0;
		rep(j,0,(int)v[1].size()){
			rep(k,0,(int)v[2].size()){
				int tmp=(int)v[3].size();int sum=j+k+tmp;
				if(2*(j+tmp)<sum||2*(k+tmp)<sum)continue;
				int nop=w[1][j]+w[2][k];
				int pos=min((min(j,k)+tmp)*2-sum,(int)v[0].size());
				nop+=w[0][pos];
				chkmax(mx,nop);
			}
		}
		write(ans+mx);
	}
	return 0;
}
