/************************************************
Problem: UVA 10949 -- Kids in a Grid
Author: Bruce Chen
Language: C++
Time: 1.939 sec
************************************************/
 
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int LCS(string s1, string s2) //Hunt-Szymanski Algorithm, 注意s1比較短, s2比較長
{
    vector<int> p[130];
    for(int i = 0; i < s2.size() ; ++i)
    {
        char index = s2[i];
        p[index].push_back(i);
    }
 
    vector<int> v;
    v.push_back(-1);
 
    for(int i = 0; i < s1.size(); ++i)
    {
        char index = s1[i];
        for(int j = p[index].size() - 1 ; j >= 0 ; --j)
        {
            int n = p[index][j];
 
            if (n > v.back()) v.push_back(n);
            else *lower_bound(v.begin(), v.end(), n) = n;
        }
    }
    return v.size() - 1;
}
 
 
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
    int T, count = 1;
    cin>>T;
    while(T--)
    {
        int row, col;
        scanf("%d %d", &row, &col);
       
        char grid[30][30];
 
        for(int i = 1 ; i <= row ; i++)
        {
            for(int j = 1 ; j <= col ; j++)
            {
                char c;
                scanf(" %c", &c);
                grid[i][j] = c;
            }
        }
 
        string str1, str2;
 
        int step, x0, y0;
        scanf("%d %d %d", &step, &x0, &y0);
        int len1 = step+1;
       
        int curX = x0, curY = y0, count1 = 2;
        char first = grid[x0][y0];
        str1 += first;
 
        for(int i = 0 ; i < step ; i++)
        {
            char c ;
            scanf(" %c", &c);
            if(c == 'N') curX--;
            else if(c == 'E') curY++;
            else if(c == 'S') curX++;
            else if(c == 'W') curY--;
 
            char temp = grid[curX][curY];
            str1 += temp;
        }
 
        scanf("%d%d%d", &step, &x0, &y0);
        int len2 = step+1;
       
        curX = x0, curY = y0;
        first = grid[x0][y0];
       
        str2 += first;
 
        for(int i = 0 ; i < step ; i++)
        {
            char c ;
            scanf(" %c", &c);
            if(c == 'N') curX--;
            else if(c == 'E') curY++;
            else if(c == 'S') curX++;
            else if(c == 'W') curY--;
 
            char temp = grid[curX][curY];
            str2 += temp;
        }
 
        int len;
        if(str1.length() > str2.length()) len = LCS(str2, str1);
        else len = LCS(str1, str2);
 
        printf("Case %d: %d %d\n", count++, len1-len, len2-len);
    }
    return 0;
}
