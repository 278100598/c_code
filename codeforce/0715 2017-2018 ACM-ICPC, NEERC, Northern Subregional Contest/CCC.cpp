#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
#define maxn 1000050
#define INF 0x3f3f3f3f
#define eps 1e-8
using namespace std;
typedef long long ll;

char s[maxn];
int n;
int flag[25];
int num[25][25];
map<char,int>m;

int main()
{
    freopen("consonant.in","r",stdin);
    freopen("consonant.out","w",stdout);
    scanf("%s",s);
    int n=strlen(s);
    int no=1;
    for(int i=0;i<26;i++)
    {
        if(i==0||i==4||i==8||i==14||i==20||i==22||i==24)
            continue;
        char c='a'+i;
        m[c]=no++;
    }
    memset(num,0,sizeof(num));
    for(int i=1;i<n;i++)
    {
        if(m[s[i-1]]&&m[s[i]])
            num[m[s[i-1]]][m[s[i]]]++;
    }
    int maxx=0,k=-1;
    for(int i=0;i<(1<<19);i++)
    {
        int tmp=i;
        for(int j=0;j<19;j++)
        {
            flag[j]=tmp%2;
            tmp/=2;
        }
        int cnt=0;
        for(int j=1;j<=19;j++)
        {
            for(int k=1;k<=19;k++)
            {
                if(k==j)continue;
                if(flag[k]+flag[j]==1)
                    cnt+=num[j][k];
            }
        }
        if(maxx<cnt)
        {
            maxx=cnt;
            k=i;
        }
    }
    for(int i=0;i<19;i++)
    {
        flag[i]=k%2;
        k/=2;
    }
    for(int i=0;i<n;i++)
    {
        if(flag[m[s[i]]])
            s[i]-=32;
    }
    printf("%s\n",s);
    return 0;
}

