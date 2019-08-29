#include<bits/stdc++.h>
#define N 10000001
using namespace std;
int  n,m,ans,t;
int A,B,C,D,E;
int r[N],l[N],cha[N];
int maxa[N];
int a[N];
struct S {
	int b,w;
	S(int B,int W){
		b=B;w=W;
	}
};
bool operator <(S x,S y){
	if(x.b!=y.b)return x.w<y.w;
	else return x.w>y.w;
}
vector<int> son[N];
priority_queue<S> q;

bool s1=1;
int f(int x){
	return A*x*x*x*x*x+B*x*x*x*x+C*x*x*x+D*x*x+E*x;
}       

void sub1(int n){
   for(int i=1;i<=n;i++) ans=max(ans,f(i));

	}
int main(){
	freopen("stand.in","r",stdin);
freopen("stand.out","w",stdout);
cin>>n>>m;
cin>>E>>D>>C>>B>>A;
for(int i=1;i<=n;i++){
	cin>>l[i]>>r[i];
	if(l[i]!=1||r[i]!=m) s1=0;
	for(int j=l[i];j<=r[i];j++)
	for(int k=l[i];k<=r[i];k++){
		if(j!=k){
			son[j].push_back(k);
			son[k].push_back(j);
		}
	}
	cha[l[i]]++;
	cha[r[i]+1]--;
	
}
a[1]=cha[1];
for(int j=2;j<=m;j++){
a[j]=a[j-1]+cha[j];q.push(S(j,a[j]));
}
int cnt=n;
while(cnt>0){
	t++;
	maxa[t]=q.top().w;
	int ax=q.top().b;
	q.pop();
	for(int i=0;i<son[ax].size();i++){
		int b=son[ax][i];
		a[b]--;
		q.push(S(b,a[b]));
			}
	if(cnt>maxa[t])		
	cnt-=maxa[t];
	else maxa[t]=cnt,cnt=0;
	}

if(s1) { sub1(n);cout<<ans<<endl;}
for(int i=1;i<=m;i++){
	ans+=f(maxa[i]);
}
 cout<<ans<<endl;
	return 0;
}


