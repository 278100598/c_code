#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
int N,M;
vector<pair<long long int,int>>ans,city;

int main() {
	cin>>N>>M; 
    for(int i=1;i<=N;i++) {
    	pair<long long int,int> p;
    	cin>>p.first;
    	p.second=i;
    	city.push_back(p);
	}
    sort(city.begin(),city.end());
    
    for(int i=0;i<N;i++) {
    	if(city[i].second == M) {
    		city[i].first=1;
    		continue;
		}
    	long long int sum=city[i].first;
    	for(int j=i-1;j>=0;j--) {
    		//if(city[j].first==0) continue;
    		if(sum >= city[j].first) {
    			sum -= city[j].first;
    			ans.push_back(make_pair(city[j].second,city[i].second));
			}
		}
	}
    
    cout<<ans.size()<<'\n';
    for(auto i:ans) cout<<i.first<<" "<<i.second<<'\n';
	return 0;
}
