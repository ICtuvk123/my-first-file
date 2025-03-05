#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
    long long n;
    scanf("%lld",&n);
    vector<long long> arr(n + 2),l(n + 2),r(n + 2);
    stack<long long> s;
    arr[0] = arr[n + 1] = -1;
    for (long long i = 1; i <= n ; i++) {
        scanf("%lld",&arr[i]);
    }
    for (long long i = 1 ; i <= n + 1; i++) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            r[s.top()] = i ;
            s.pop(); 
        }
        s.push(i);        
    }
    while (!s.empty()) s.pop();
    for (long long i = n ; i >= 0 ; i--) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            l[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    long long ans = 0 ;
    for (long long i = 1 ; i <= n ; i++) {
        ans = max(ans,arr[i] * (r[i] - l[i] - 1));
    }
    cout << ans ;
    return 0;
}
