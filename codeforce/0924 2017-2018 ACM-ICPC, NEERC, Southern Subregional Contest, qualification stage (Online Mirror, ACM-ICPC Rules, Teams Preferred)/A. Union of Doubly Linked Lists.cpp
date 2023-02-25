#include<iostream>
#include<vector>
using namespace std;
int N;
bool vis[101];
pair<int,int> arr[101];
int main() {
	cin>>N;
	for(int i=1;i<=N;i++) cin>>arr[i].first>>arr[i].second;
	
	int pre=0;
	for(int i=1;i<=N;i++) {
		if(arr[i].first == 0) {
			arr[pre].second = i;
			arr[i].first = pre;
			int it = i;
			while(arr[it].second != 0) it=arr[it].second;
			pre = it;
		}	
	}
	
	for(int i=1;i<=N;i++) cout<<arr[i].first<<' '<<arr[i].second<<'\n';
	
	return 0;
} 
