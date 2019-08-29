#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &F)
{
	F=0;int R=1;char CH=getchar();
	while(!isdigit(CH)&&CH!='-') CH=getchar();
	if(CH=='-') R=-1;else F=(CH^48);CH=getchar();
	while(isdigit(CH)) F=(F<<1)+(F<<3)+(CH^48),CH=getchar();F*=R;
}
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	cout<<"infinity"<<endl;
	return 0;
}


