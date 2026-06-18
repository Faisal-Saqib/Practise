#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
pair<int, int> p[1009];
int orient(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    return 1ll*(b.first - a.first) * (c.second - a.second) > 1ll*(c.first - a.first) * (b.second - a.second);
}
int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            bool pos = 0;
            for (int k = 0; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    // m1 = (p[j].y-p[i].y) / (p[j].x-p[i].x)
                    // m2 = (p[k].y-p[l].y) / (p[k].x-p[l].x)
                    // c1 = p[i].y - m1*p[i].x
                    // c2 = p[k].y - m2*p[k].x
                    // x*m1 + c1  = x*m2 + c2
                    // x = (c2-c1)/(m1-m2)

                    // p[i].x,p[j].x
                    // p[k].x,p[l].x
                    // intersect

                    // p[i].y,p[j].y
                    // p[k].y,p[l].y
                    // intersect
                    if (k != j and l != j and k != i and l != i)
                    {
                        if (orient(p[i], p[j], p[k]) != orient(p[i], p[j], p[l]) and orient(p[k], p[l], p[i]) != orient(p[k], p[l], p[j]))
                        {
                            pos = 1;
                            break;
                        }
                    }
                }
            }
            ans += !pos;
        }
    }
    cout << ans << endl;
}
// 50 pts