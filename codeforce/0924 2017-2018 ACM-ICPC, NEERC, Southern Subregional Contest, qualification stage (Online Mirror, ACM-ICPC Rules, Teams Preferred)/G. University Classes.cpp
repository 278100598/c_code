#include<iostream>
using namespace std;
int N,keep[7];
int main() {
	cin>>N;
	for(int i=0;i<N;i++) {
		for(int j=0;j<7;j++) {
			char c;
			cin>>c;
			if(c == '1') keep[j]++;
		}
	}
	int mx=-1;
	for(int i=0;i<7;i++) mx = max(mx,keep[i]);
	
	cout<<mx;
	return 0;
}
