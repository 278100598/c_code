#include<iostream>
using namespace std;
int N,d[60*24+1],keep[60*24],ans1=0,ans2;
int main() {
	cin>>N;
	for(int i=0;i<60*24;i++) {
		keep[i] = -1;
		d[i] = 1e9;
	}
	d[60*24]=1e9;
	d[0]=0;
	for(int i=0;i<N;i++) {
		string s;
		cin>>s;
		int h = stoi(s.substr(0,s.find(":"))), m = stoi(s.substr(s.find(":")+1,s.size()));
		//cout<<h<<" "<<m<<endl;
		cin>>s;
		if(s=="S") keep[h*60+m] = 0;
		else if(s=="U") keep[h*60+m] = 1;
	}
	
	int use = -1;
	bool subway = false;
	for(int i=0;i<60*24;i++) {
		if(use != -1 && use < i) {
			use = -1;
			subway = false;
		}
		
		if(keep[i] == 0) {
			if (use == -1) {
				bool y=false;
				for(int j=1;j<=90 && i+j<60*24;j++) {
					if(keep[i+j] != -1) y=true;
				}
				
				if(y) {
					ans1 += 44;
					use = i+90;
				} else ans1 += 26;
			}
		} else if(keep[i] == 1) {
			if (use == -1 || subway) {
				bool y=false;
				for(int j=1;j<=90 && i+j<60*24;j++) {
					if(keep[i+j] == 1) break;
					else if(keep[i+j] == 0) y=true;
				}
				
				if(y) {
					ans1 += 44;
					use = i+90;
					subway = true;
				} else {
					ans1 += 28;
				}
			} else subway = true;
		}
		//cout<<i/60<<" "<<i%60<<" "<<ans1<<endl;
	}
	
	for(int i=0;i<60*24;i++) {
		int k = min(60*24,i+91),count=0,add=0;
		for(int j=0;j<=90 && i+j<=60*24;j++) {
			if(keep[i+j] == 1) count++;
			if(count == 2) {
				k=i+j;
				break;
			}
		}
		
		if(keep[i] == 0) add=26;
		else if(keep[i] == 1) add=28;
		d[i+1] = min(d[i+1],d[i]+add);
		d[k] = min(d[k],d[i]+44);
		//cout<<i/60<<" "<<i%60<<" "<<d[i]<<endl;
	}
	ans2 = d[60*24];
	cout<<ans1<<" "<<ans2;
	return 0;
}
