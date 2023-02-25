#include<iostream>
#include<vector>
using namespace std;
int N,K,S[100000];
vector<int> ans;
int main() {
	cin>>N>>K;
	int sum=0;
	for(int i=0;i<N;i++) {
		cin>>S[i];
		sum+=S[i];
	}
	if(sum % K != 0) {
		cout<<"No";
		return 0;
	}
	
	int cnt=sum/K,num=0;
	sum=0;
	for(int i=0;i<N;i++) {
		sum+=S[i];
		num++;
		if(sum > cnt) {
			cout<<"No";
			return 0;
		} else if(sum == cnt) {
			ans.push_back(num);
			sum=0;
			num=0;
		}
	}
	cout<<"Yes"<<endl;
	for(int i:ans) cout<<i<<" ";
	
	return 0;
}
