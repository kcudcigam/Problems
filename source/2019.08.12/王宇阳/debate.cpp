#include<bits/stdc++.h>
using namespace std;
inline int read(){
	   int x=0,f=1;
	   char c=getchar();
	   while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	   while(c>='0' && c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	   return x*f;
}
struct node{
	bool fir,sec;
	int dat;
}a[400005];
vector<int> v1,v2,v3;
bool cmp(node x,node y){
	return x.dat>y.dat;
}
int  n,t,pro1,pro2,ans;
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		char c1,c2;
		cin>>c1>>c2;
		int a,b;
		a=c1-'0';
		b=c2-'0';
		int val=read();
		if(a+b==2){
			ans+=val;
			t++;
		}else{
			if(a==1){
				v1.push_back(val);
			}else{
				if(b==1){
					v2.push_back(val);
				}else{
					v3.push_back(val);
				}
			}
		}
	}
	sort(v1.begin(),v1.end());
	reverse(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	reverse(v2.begin(),v2.end());
	for(int i=0;i<v1.size();i++){
		if(i<min(v1.size(),v2.size())){
			ans+=v1[i];
		}else{
			v3.push_back(v1[i]);
		}
	}
	for(int i=0;i<v2.size();i++){
		if(i<min(v1.size(),v2.size())){
			ans+=v2[i];
		}else{
			v3.push_back(v2[i]);
		}
	}
	sort(v3.begin(),v3.end());
	reverse(v3.begin(),v3.end());
	for(int i=0;i<min(t,int(v3.size()));i++){
		ans+=v3[i];
	}
	cout<<ans<<endl;
	return 0;
}


