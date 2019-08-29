#include<iostream>
#include<cstdio>
using namespace std;
long long Treetj[3200005],Treewj[3200005],Tree[3200005];
bool flag;
long long Ans;
int n,m;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
void doit(int id,int l,int r){
	long  Mid,h;
	long long mid = (l+r)/2;
	if (Treewj[id] == Treetj[id]){
		Mid = Treewj[id];
		h = 0;
	}
	else{
		h = (Treewj[id]-Treetj[id])/(r-l);
		Mid = h*(mid-l)+Treetj[id];
	}
	Treetj[id*2] += Treetj[id];
	Treewj[id*2+1] += Treewj[id];
	Treewj[id*2] += Mid;
	Treetj[id*2+1] += Mid + h;
	Treetj[id] = 0;
	Treewj[id] = 0;
	return;
}
void Revise(int id,int Nl,int Nr,int l,int r,int t,int w){ //Nl,Nr dangqian
	if (Nl>=l && Nr<=r){
		Treetj[id]+=t;
		Treewj[id]+=w;
		return;
	}
	if (Treetj[id]&&Treewj[id]){
		doit(id,Nl,Nr);
	}
	int Mid,h;
	int mid = (Nl+Nr)/2;
	if (t == w){
		Mid = w;
		h = 0;
	}
	else{
		h = (w - t)/(Nr-Nl);
		Mid = h*(mid-Nl)+t;
	}
	if (l <= mid)
		Revise(id*2,Nl,mid,l,mid,t,Mid);
	if (r > mid)
		Revise(id*2+1,mid+1,Nr,mid+1,r,Mid+h,w);
}
void Build(int id,int l,int r){
	if (l == r){
		Tree[id] = Treetj[id];
		if (!flag){
			flag = 1;
			Ans = Tree[id];
		}
		else
			Ans = Ans^Tree[id];
		return;
	}
	if (Treetj[id]&&Treewj[id]){
		doit(id,l,r);
	}
	int mid = (l+r)/2;
	Build(id*2,l,mid);
	Build(id*2+1,mid+1,r);
	return;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	for (int i = 1; i <= m; ++ i){
		int l,r,s,e;
		scanf("%d%d%d%d",&l,&r,&s,&e);
		Revise(1,1,n,l,r,s,e);
	}
	Build(1,1,n);
	printf("%lld",Ans);
}
