#include <bits/stdc++.h>
using namespace std;
string s[10005];
int x[10005];
int n,i,b=1,Max,Min,sum=0,big,small,Mn,Mx;

string gg(int x) {
	string a=to_string(x/100),b=to_string(x%100);
	if(b.size() < 2) b = "0"+b;
	return a+"."+b;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>s[i]>>x[i];
		sum+=x[i];
		if(x[i]==100)big+=1;
		else if(x[i]==0)small+=1;
	}
	
	int mx = sum*100+(n-big)*49,mn=sum*100-(n-small)*50;
	
	if(mx>=10000) {
		Mn =max((mx-10000)*-1,-50);
		Min=max(((mx-49)-10000)*-1,-50);
	} else {
		cout<<"IMPOSSIBLE";
		return 0;
	}
	
	if(mn<=10000) {
		Mx =min((10000-mn),49);
		Max=min((10000-(mn+50)),49);
	} else {
		cout<<"IMPOSSIBLE";
		return 0;
	}
	
	//cout<<Min<<' '<<Max<<'\n';
	
	for(int i=0;i<n;i++) {
		cout<<s[i]<<' ';
		
		if(x[i]==100) {
			if(Mn>0) cout<<gg(10000)<<' ';
			else cout<<gg(10000+Mn)<<' ';
			
			if(Max>0) cout<<gg(10000)<<'\n';
			else cout<<gg(10000+Max)<<'\n';
		} else if(x[i]==0) {
			if(Min<0) cout<<gg(0)<<' ';
			else cout<<gg(Min)<<' ';
			
			if(Mx<0) cout<<gg(0)<<'\n';
			else cout<<gg(Mx)<<'\n';
		} else {
			cout<<gg(x[i]*100+Min)<<' '<<gg(x[i]*100+Max)<<'\n';
		}
	}
	return 0;
}
/*
3
a 99
b 1
c 0
*/
