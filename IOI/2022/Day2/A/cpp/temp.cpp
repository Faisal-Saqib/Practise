#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    dp[0][0]=0;
    dp[0][1]=12;

    dp[1][0]=0;
    dp[1][1]=34;
    
    vector<int> p1(10),p2(10);
    p1[0]=dp[0][0];
    p1[1]=dp[0][1];
    p1[2]=dp[0][1];

    p2[0] = dp[1][0];
    p2[1] = dp[1][1];
    p2[2]=dp[1][1];
    for (int i = 0; i < 10; i++)
        cout << p1[i] << ' ';
    cout << endl;
    for (int i = 0; i < 10; i++)
        cout << p2[i] << ' ';
    cout << endl;
    vector<int> p3(40);
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                p3[i + j] += (p1[i] * p2[j]);
            }
        }
    int sm=0;
    int sm1=0;
    for (int i = 0; i < 10; i++)
    {
        sm += (p3[i] * i);
        if(i)
            sm1 += (p3[i]);
        cout << p3[i] << ' ';
    }
    cout<<endl;
    cout << "tot = " << sm << endl;
    cout << "tot = " << sm1 << endl;
}
// answer is 816
// as we need 1 408
// 2 408