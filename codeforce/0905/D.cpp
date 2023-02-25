#include<iostream>
using namespace std;
long long int x[2][2],sum=0,ans=0;
int main() {
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			cin>>x[i][j];
			sum+=x[i][j];
		}
	}
	
	if((sum/4)*4 !=sum) {
		cout<<-1;
		return 0;
	}
	sum /= 4;
	
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			if(x[i][j] < sum && x[(i+1)%2][j] > sum) {
				long long int give = min(sum - x[i][j], x[(i+1)%2][j]-sum);
				x[i][j]+=give;
				x[(i+1)%2][j]-=give;
				ans += give;
			}
			if(x[i][j] < sum && x[i][(j+1)%2] > sum) {
				long long int give = min(sum - x[i][j], x[i][(j+1)%2]-sum);
				x[i][j]+=give;
				x[i][(j+1)%2]-=give;
				ans += give;
			}
			if(x[i][j] < sum && x[(i+1)%2][(j+1)%2] > sum) {
				long long int give = min(sum - x[i][j], x[(i+1)%2][(j+1)%2]-sum);
				x[i][j]+=give;
				x[(i+1)%2][(j+1)%2]-=give;
				ans += give*2;
			}
		}
	}
	
	cout<<ans;
	return 0;
}
/*
0 2
0 10
*/
