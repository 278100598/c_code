#include<iostream>
using namespace std;
int N,M,lv[1000][1000];
string m[1000];

int main() {
	cin>>N>>M;
	for(int i=0;i<N;i++) cin>>m[i];
	
	for(int i=0;i<N;i++) {
		lv[i][M-1]=1;
		for(int j=M-2;j>=0;j--) {
			if(m[i][j]==m[i][j+1]) lv[i][j]=lv[i][j+1]+1;
			else lv[i][j]=1;
		}
	} 
	
	
	int ans=1;
	for(int j=0;j<M;j++) {
		
		int cnt=0;
		bool flag=false;
		for(int i=0;i<N;i++) {
			if(lv[i][j]>ans) cnt++;
			else cnt=0;
			
			if(cnt>ans) {
				flag=true;
				break;
			}
		}
		
		if(flag) {
			ans++;
			j--;
		}
	}
	
	cout<<ans*ans;
	return 0;
}
