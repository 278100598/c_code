#include<iostream>
#include<vector>
#include<algorithm>
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
bool cmp(ASMT a,ASMT b) {return a.d < b.d;}

int N;
vector<ASMT> vec;
vector<int> ans;

int main()
{
    cin>>N;
    for(int i=0;i<N;i++) {
    	int t,d;
    	cin>>t>>d;
    	vec.push_back(ASMT(t,d,i+1));
	}
	sort(vec.begin(),vec.end(),cmp);
	
	int had=0;
	for(int i=0;i<N;i++) {
		int sum=had,gap=1e9+1,target=-1;
		for(int j=0;j<vec.size();j++) {
			if(vec[j].used) continue;
			
			if(vec[j].t <= gap) {
				if(target == -1 || vec[j].index < vec[target].index) {
					target = j;
				}
			}
			sum += vec[j].t;
			gap = min(gap,vec[j].d - sum);
		}
		
		if(vec[target].d < had + vec[target].t) {
			cout<<"*";
			return 0;
		} else {
			ans.push_back(vec[target].index);
			had += vec[target].t;
			vec[target].used = true;
		}
	}
	for(int i:ans) cout<<i<<" ";
    return 0;
}
/*
8
8 59
7 56
7 57
9 60
7 56
8 55
7 50
7 44
*/
