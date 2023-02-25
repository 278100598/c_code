#include<iostream>
#include<vector>
using namespace std;
int N=10,K=5,T;
bool out=false;
vector<int> vec;

vector<vector<int>> go(int now,int remain) {
	if(remain==0) {
		return {vec};
	}
	if(now-1 == N) return{};
	if(N-now+1 < remain) return{};
	
	vec.push_back(now);
	vector<vector<int>> v1=go(now+1,remain-1);
	vec.pop_back();
	vector<vector<int>> v2=go(now+1,remain);
	
	v1.insert(v1.end(),v2.rbegin(),v2.rend());
	
	if(v1.size() >= T) {
		cout<<T<<'\n';
		for(int i=0;i<T;i++) {
			for(int j:v1[i]) cout<<j<<" ";
			cout<<'\n';
		}
		out=true;
		exit(0);
	}
	
	return v1;
}

int main() {
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>N>>K>>T;
	long long int v = 1;
    for (int i = K + 1; i <= N; i++) {
        v *= i;
        v /= (i - K);
        if (v >= T) {
            N = i;
            break;
        }
    }
	
	auto ans=go(1,K);
	if(!out) cout<<0;
	
	return 0;
}
/*
12345

12356

12456

*/
