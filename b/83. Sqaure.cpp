#include<iostream>
#include<deque>
using namespace std;
int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	int **x = new int*[n];
	int *len = new int[m];
	for(int i=0;i<n;i++) {
		x[i] = new int[m];
	}
	for(int j=0;j<m;j++) {
		len[j]=0;
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin>>x[i][j];
		} 
	}
	int mx=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(x[i][j]==7) {
				len[j]++;
			} else {
				len[j]=0;
			}
			//cout<<len[j]<<" ";
		}
		//cout<<endl;
		for(int j=0;j<m;j++) {
			if(len[j]>mx) {
				int ma = len[j];
				for(int k=1;k<m-j;k++) {
					ma = min(ma,len[j+k]);
					mx = max(min(ma,k+1),mx);
					if(ma<=mx) {
						break;
					}
				}
			}
		}
	}
	cout<<mx;
	return 0;
}

