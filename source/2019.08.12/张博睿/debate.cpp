#include<bits/stdc++.h>
using namespace std;
int n,a[400002],ans,zyx[400002],hyy[400002],zcy[400002],byf[400002],ty,fd,ac,wa,tle,re,mle,uke;
char s[400002],ss[400002];
bool duckmp(const int &duck,const int &boom0)
{
	return duck>boom0;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i]>>ss[i];scanf("%d",&a[i]);
		if(ss[i]=='1'&&s[i]=='1'){ac++;zyx[ac]=a[i];} 
		else
		{
			if(s[i]=='1'){wa++;hyy[wa]=a[i];}
			else
			{
				if(ss[i]=='1'){tle++;zcy[tle]=a[i];}
				else{re++;byf[re]=a[i];}
			}
		}
	}
	for(int i=1;i<=ac;i++) ans+=zyx[i];ty=ac;
	sort(hyy+1,hyy+wa+1,duckmp);sort(zcy+1,zcy+tle+1,duckmp);mle=min(wa,tle);uke=max(wa,tle);
	for(int i=1;i<=mle;i++) ans=ans+hyy[i]+zcy[i];ty+=mle;fd+=mle;
	if(wa>mle) for(int i=mle+1;i<=wa;i++) byf[re+i-mle]=hyy[i];
	else for(int i=mle+1;i<=tle;i++) byf[re+i-mle]=zcy[i];
	sort(byf+1,byf+re+1+uke-mle,duckmp);
	for(int i=1;i<=uke;i++) {fd++;if((ty+fd+1)/2>ty) break;ans=ans+byf[i];}
	cout<<ans<<endl;
	return 0;
}


