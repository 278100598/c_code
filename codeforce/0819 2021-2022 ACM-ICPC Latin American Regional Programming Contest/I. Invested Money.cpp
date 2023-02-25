#include<iostream>
using namespace std;
string T;
int N,day;

int get(int x) {
	bool yes=(x>=30);
	int preday=((day-x)%7+7)%7;
	
	if(x > 91) {
		if(preday == 1) x-=0;
		else if(preday == 2) x-=62;
		else if(preday == 3) x-=61;
		else if(preday == 4) x-=32;
		else if(preday == 5) x-=31;
		x %= 91;
		preday = 1;
	}
	
	while(x > 30) {
		x-=30;
		preday+=2;
		preday%=7;
		if(preday==6) {
			x -= 2;
			preday = 1;
		} else if(preday==0) {
			x -= 1;
			preday = 1;
		}
	}
	x = (x+30) % 30;
	//cout<<x<<endl;
	if(x==0 && yes) {
		return 30;
	}
	
	return x;
}

int main() {
	cin>>T>>N;
	if(T=="Mon") day=1;
	else if(T=="Tue") day=2;
	else if(T=="Wed") day=3;
	else if(T=="Thu") day=4;
	else if(T=="Fri") day=5;
	else if(T=="Sat") day=6;
	else if(T=="Sun") day=0;
	
	int mx=-1;
	for(int i=0;i<N;i++) {
		int x;
		cin>>x;
		x = get(x);
		if(x==30 || mx==30) {
			mx=30;
		} else {
			mx = max(mx,x);
		}
	}
	
	mx = 30-mx;
	int preday = (day+mx)%7;
	if(preday == 6) cout<<mx+2;
	else if(preday == 0) cout<<mx+1;
	else cout<<mx;
	
	return 0;
} 

