#include <bits/stdc++.h>
using namespace std;
string s[10005];
int x[10005];
int n,i,b=1;
double sum,a,Max,Min,big=0,small=0,Maxs,Mins,c,d;
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
	if(sum<100){
		a=0.49*(n-1);
		Max=0.49;
		if(a>=100-sum+0.5)Min=-0.5;
		else if(100-sum-a>0.49)b=0;
		else Min=100-sum-a;
	}else if(sum>100){
		a=0.5*(n-1-small);
		c=0.5*(n-small);
		d=1;
		Min=-0.5;
		if(a-sum+100>=0.49)Max=0.49;
		else if(a-sum+100<-0.5)b=0;
		else Max=a-sum+100;
		if(c-sum+100>=0.49)Maxs=0.49;
		else if(c-sum+100<-0.5)b=0;
		else Maxs=c-sum+100;
	}else{
		if(n>2)Min=-0.5;
		else Min=-0.49;
		Max=0.49;
	}if(b==0)cout<<"IMPOSSIBLE"<<endl;
	else {
		for(i=0;i<n;i++){
			if(x[i]==0 && d==1)cout <<fixed<<setprecision(2)<<s[i]<<' '<<x[i]+Mins<<' '<<x[i]+Maxs<<endl;
			else {cout<<fixed << setprecision(2)<<s[i]<<' ';
			if(x[i]+Min<0)cout<<"0.00"<<' ';
			else if(x[i]+Min>100)cout<<"100.00"<<' ';
			else cout<<x[i]+Min<<' ';
			if(x[i]+Max<0)cout<<"0.00"<<endl;
			else if(x[i]+Max>100)cout<<"100.00"<<endl;
			else cout<<x[i]+Max<<endl;}
		}
	}
}


