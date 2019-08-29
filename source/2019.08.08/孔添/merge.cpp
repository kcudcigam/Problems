#include<bits/stdc++.h>
using namespace std;
int n,q,p,a,b;
int ans[500010];
int juice[500010];
vector< vector<int> > zu;
void merge(int w1,int w2){
	vector<int> x=zu[w2];
	while((!x.empty())){
		ans[x.back()]=w1;
		zu[w1].push_back(x.back()) ;
		x.pop_back();
	}
	zu[w2].clear();
}
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	cin>>n>>q; 
	for(int i=0;i<=n;++i){
		ans[i]=i;
		vector<int> x;
		x.push_back(i); 
		zu.push_back(x);  
	}
		
	for(int i=1;i<=q;++i){
		read(p),read(a),read(b);
		if(p==1){
			merge(ans[a],ans[b]);
		}else{
			int w1=ans[a];
			vector<int> x=zu[w1];
			while((!x.empty())){
				juice[x.back()]+=b;
				x.pop_back();
			}
		}
		
		
	}
	for(int i=1;i<=n;++i)
		cout<<juice[i]<<endl;
	return 0;
}

