#include <bits/stdc++.h>
using namespace std;
bool valid(vector<int> x,vector<int> y)
{
    bool pos=1;
    for(int i=1;i+1<x.size();i++)
    {
        if(x[i+1]-x[i] != x[i]-x[i-1])
        {
            pos=0;
        }
    }
    swap(x,y);
    for (int i = 1; i + 1 < x.size(); i++)
    {
        if (x[i + 1] - x[i] != x[i] - x[i - 1])
        {
            pos = 0;
        }
    }
    if(pos)
    {
        if(x.size()==0)x.push_back(y.back()),y.pop_back();
        swap(x,y);
        if (x.size() == 0)x.push_back(y.back()),y.pop_back();
        cout<<x.size()<<endl;
        for(auto v:x)
            cout<<v<<' ';
        cout<<endl;
        swap(x,y);
        cout << x.size() << endl;
        for (auto v : x)
            cout << v << ' ';
        cout << endl;
    }
    return pos;
}
multiset<int> dif1;
multiset<int> cur1;
void add1(int x)
{
    auto it = cur1.upper_bound(x);
    int nxt = -1, prv = -1;
    if (it != end(cur1))
    {
        nxt = *it;
    }
    if (it != begin(cur1))
    {
        it--;
        prv = *it;
    }
    if (nxt != -1 and prv != -1)
    {
        dif1.erase(dif1.find(nxt - prv));
    }
    if (nxt != -1)
    {
        dif1.insert(nxt - x);
    }
    if (prv != -1)
    {
        dif1.insert(x - prv);
    }
    cur1.insert(x);
}
void rem1(int x)
{
    auto it = cur1.upper_bound(x);
    int nxt = -1, prv = -1;
    if (it != end(cur1))
    {
        nxt = *it;
    }
    it--; // as x exist so
    if (it != begin(cur1))
    {
        it--;
        prv = *it;
    }
    if (nxt != -1 and prv != -1)
    {
        dif1.insert(nxt - prv);
    }
    if (nxt != -1)
    {
        dif1.erase(dif1.find(nxt - x));
    }
    if (prv != -1)
    {
        dif1.erase(dif1.find(x - prv));
    }
    cur1.erase(cur1.find(x));
}
multiset<int> dif;
multiset<int> cur;
void add(int x)
{
    rem1(x);
    auto it=cur.upper_bound(x);
    int nxt=-1,prv=-1;
    if(it!=end(cur))
    {
        nxt=*it;
    }
    if(it!=begin(cur))
    {
        it--;
        prv=*it;
    }
    if(nxt!=-1 and prv!=-1)
    {
        dif.erase(dif.find(nxt-prv));
    }
    if(nxt!=-1)
    {
        dif.insert(nxt-x);
    }
    if(prv!=-1)
    {
        dif.insert(x-prv);
    }
    cur.insert(x);
}
void rem(int x)
{
    add1(x);
    auto it = cur.upper_bound(x);
    int nxt = -1, prv = -1;
    if (it != end(cur))
    {
        nxt = *it;
    }
    it--;// as x exist so 
    if (it != begin(cur))
    {
        it--;
        prv = *it;
    }
    if (nxt != -1 and prv != -1)
    {
        dif.insert(nxt - prv);
    }
    if (nxt != -1)
    {
        dif.erase(dif.find(nxt - x));
    }
    if (prv != -1)
    {
        dif.erase(dif.find(x - prv));
    }
    cur.erase(cur.find(x));
}
bool valid()
{
    if(dif.size()==0 or *rbegin(dif) == *begin(dif))
        if (dif1.size() == 0 or *rbegin(dif1) == *begin(dif1))
            return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int h[n];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    sort(h, h + n);
    if (n == 2)
    {
        cout << 1 << endl
             << h[0] << endl
             << 1 << endl
             << h[1] << endl;
        return 0;
    }
    if (n == 3)
    {
        cout << 2 << endl
             << h[0] << ' '
             << h[1] << endl
             << 1 << endl
             << h[2] << endl;
        return 0;
    }
    if (n == 4)
    {
        cout << 2 << endl
             << h[0] << ' '
             << h[1] << endl
             << 2 << endl
             << h[2] << ' '
             << h[3] << endl;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        cur1.insert(h[i]);
        add(h[i]);
    }
    for(auto d:{h[1]-h[0],h[2]-h[0]})
    {
        int lst=h[0];
        vector<int> tp;
        for(int l=1;l<=n;l++)
        {
            if(cur.find(lst)==cur.end())
            {
                break;
            }
            tp.push_back(lst);
            rem(lst);
            if(valid())
            {
                cout<<cur1.size()<<endl;
                for(auto x:cur1)cout<<x<<' ';
                cout<<endl;
                cout << cur.size() << endl;
                for (auto x : cur)
                    cout << x << ' ';
                cout << endl;
                return 0;
            }
            lst+=d;
        }
        for(auto x:tp)add(x);
    }
    for (auto d : {h[2] - h[1]})
    {
        int lst = h[1];
        vector<int> tp;
        for (int l = 1; l <= n; l++)
        {
            if (cur.find(lst) == cur.end())
            {
                break;
            }
            tp.push_back(lst);
            rem(lst);
            if (valid())
            {
                cout << cur1.size() << endl;
                for (auto x : cur1)
                    cout << x << ' ';
                cout << endl;
                cout << cur.size() << endl;
                for (auto x : cur)
                    cout << x << ' ';
                cout << endl;
                return 0;
            }
            lst += d;
        }
        for (auto x : tp)
            add(x);
    }
    cout<<-1<<endl;
}