#include<bits/stdc++.h>
using namespace std;
const int N=400010;
inline int read()
{int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch<='9'&&ch>='0'){x*=10;x+=(ch-'0');ch=getchar();}return x*f;
}
int n;
string td[N];
int le[N],re[N];
int vis[N];
int need_le,need_re;
int sum,num_le,num_re;
struct node{
	int le,re,v;
};node a[N];
inline bool cmp(node x,node y){
	return x.v>y.v;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout); 
	n=read();
	for(int i=1;i<=n;++i){
		cin>>td[i];
		a[i].v=read();
	} 
	for(int i=1;i<=n;++i){
		if(td[i][0]=='1'){
			a[i].le=1;
			num_le++;
		}
		if(td[i][1]=='1'){
			a[i].re=1;
			num_re++;
		}
	}
	sort(a+1,a+1+n,cmp);
/*	if(num_le==num_re||num_le<num_re){
		cut=num_le;
		need_le=cut,need_re=cut;
	}
	if(num_le>num_re){
		cut=num_re;
		need_le=cut+1,need_re=cut;
	}*/
	int cut=min(num_le,num_re);
	need_le=cut,need_re=cut;
	//xuan cut*2 ge ren
	int tot=0;
	for(int i=1;i<=n;++i){
		if(!need_le){
			break;
		}
		if(a[i].le){
			sum+=a[i].v;
		//	cout<<a[i].v<<" ";
			vis[i]=1;need_le--;
			tot++;
		}
	}
	for(int i=1;i<=n;++i){
		if(!need_re){
			break;
		}
		if(a[i].re){
			if(!vis[i]){
				sum+=a[i].v;
			//	cout<<a[i].v<<" ";
				tot++;
				vis[i]=1;
			}
			need_re--;
		}
	}
	for(int i=1;i<=n;++i){
		if(tot==cut*2){
			break;
		}
		if(!vis[i]){
			sum+=a[i].v;
		//	cout<<a[i].v<<" ";
			tot++;
			vis[i]=1;
		}
	} 
	printf("%d",sum);
	return 0;
}


