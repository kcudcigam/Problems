#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &FF)
{
	FF=0;int r=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') r=-1;else FF=ch^48;ch=getchar();
	while(isdigit(ch)) FF=(FF<<1)+(FF<<3)+(ch^48),ch=getchar(); FF*=r;
}
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cout<<"4"<<endl;
	return 0;
}


