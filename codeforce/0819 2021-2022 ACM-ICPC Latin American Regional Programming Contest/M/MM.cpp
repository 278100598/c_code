#include<iostream>
#include<vector>
#define mp make_pair
using namespace std;

struct ASMT {
	int t,d,index;
	bool used=false;
	ASMT(int t,int d,int i) {
		this->t = t;
		this->d = d;
		this->index = i;
	}
};

int N;
vector<ASMT> vec;
bool back=false;

void dfs(vector<int> ans) {
	if(back) return;
	if(ans.size() == N) {
		long long int sum=0;
		for(int i:ans) {
			sum+=vec[i-1].t;
			if(sum > vec[i-1].d) {
				return;
			}
		}
		
		for(int i:ans) cout<<i<<" ";
		back=true;
		return;
	}
	
	for(int i=0;i<N;i++) {
		if(vec[i].used) continue;
		
		ans.push_back(vec[i].index);
		vec[i].used=true;
		dfs(ans);
		ans.pop_back();
		vec[i].used=false;
	}
}

int main()
{
    cin>>N;
    long long int sum=0;
    for(int i=0;i<N;i++) {
    	int t,d;
    	cin>>t>>d;
    	sum+=t;
    	vec.push_back(ASMT(t,d,i+1));
	}
	
	vector<int>v;
	dfs(v);
	
	if(!back)cout<<"*";
    
    return 0;
}
