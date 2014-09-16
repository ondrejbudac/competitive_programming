#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n,h;
    cin >> n >> h;
    vector<int> a(n);
    for (int i=0; i<n; ++i)
        cin >> a[i];


    if (a[0] < h-1 || a[n-1] < h-1) {
        cout << "0\n";
        return 0;
    }
    for (int i=0; i<n-1; ++i)
        if (a[i] > a[i+1]+1 || a[i] < a[i+1]-1 || a[i] > h) {
            cout << "0\n";
            return 0;
        }
    long long res = 1;
    const long long MOD = 1000000007;
    long long th = h-a[0];
    for (int i=1; i<n; ++i) {
        if (a[i]==a[i-1]-1) {
            th++;
        }
        if (a[i]==a[i-1]) {
            res = (res*(th+1)) % MOD;
        }
        if (a[i] == a[i-1]+1) {
            res = (res*th) % MOD;
            th--;
        }
    }
    cout << res << "\n";

    return 0;
}