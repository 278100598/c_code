#include<iostream>
#include<vector>
#define P pair<int ,int>
using namespace std;
int main()
{
	int T,N;
	vector<int> *d;
    while(true) {
    	cin>>T;
    	if(T==0)break;
    	cin>>N;
    	
    	d = new vector<int>[T+1];
    	int task[N];
    	for(int i=0;i<N;i++) {
    		int x;
    		cin>>x;
    		task[i]=x;
    		for(int j=T-x;j>=0;j--) {
    			if(!d[j].empty()||j==0) {
    				bool y=false;
    				auto vec = d[j+x];
    				d[j].push_back(i);
    				for(int k=0;k<vec.size()&&k<d[j].size();k++) {
    					if(d[j][k]<vec[k]) {
    						y=true;
    						break;
						} else if(vec[k]<d[j][k]) break;
					}
					if(y||vec.empty()) {
						d[j+x].assign(d[j].begin(),d[j].end());
					}
					d[j].pop_back();
				}
			}
		}
		/*
		for(int i=0;i<=T;i++) {
			cout<<i;
			for(int j=0;j<d[i].size();j++) {
				cout<<" "<<task[d[i][j]];
			}
			cout<<endl;
		}
		cout<<endl;*/
		int x=T;
		while(d[x].empty())x--;
		for(int i=0;i<d[x].size();i++) {
			cout<<task[d[x][i]]<<" ";
		}
		cout<<x<<endl;
	}
    return 0;
}
