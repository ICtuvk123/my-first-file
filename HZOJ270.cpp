#include<iostream>
#include<vector>
#include<deque>
#include<cinttypes>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int ans = INT32_MIN;
    vector<int> s(n + 1);
    s.push_back(0);
    deque<int> q;
    q.push_back(0);
    for (int i = 1 ; i <= n ; i++) {
        cin >> s[i];
        s[i] += s[i - 1];        
    }
    for (int i = 1 ; i <= n ; i++) {
        ans = max(ans,s[i] - s[q.front()]);
        while (!q.empty() && s[q.back()] > s[i]) q.pop_back();
        q.push_back(i);
        if (q.front() == i - m) q.pop_front();
    }
    cout << ans << endl;
    return 0;
}