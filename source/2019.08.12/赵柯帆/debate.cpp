#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
vector<int>v1,v2,v3;
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n;
	read(n);
	
	unsigned int t=0,ans=0;
	for(int i=1;i<=n;i++){
		char ch1,ch2;
		cin>>ch1>>ch2;
		int a,b,v;
		a=ch1-'0';
		b=ch2-'0';
		read(v);
		if(a+b==2){
			ans+=v;
			t++;
		}else{
			if(a){
				v1.push_back(v);
			}else if(b){
				v2.push_back(v);
			}else{
				v3.push_back(v);
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
	for(int i=0;i<min(t,v3.size());i++){
		ans+=v3[i];
	}
	
	cout<<ans<<endl;
	return 0;
}

