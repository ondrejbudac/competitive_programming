#include <iostream>
using namespace std;

int main()
{
    int n, p;
    char s[2000];
    scanf("%d %d", &n, &p);
    scanf("%s", s);

    for (int i=0; i<n; ++i)
        cin >> s[i];
    int i=n-1;
    bool done = false;
    for (; i>=0; --i) {
        for (char c = s[i]+1; c < 'a'+p; ++c) {
            if (((i<1) || (s[i-1] != c)) && ((i < 2) || (s[i-2] != c))) {
                s[i]=c;
                i++;
                done = true;
                break;
            }
        }
        if (done)
            break;
    }

    if (!done) {
        cout << "NO\n";
        return 0;
    }

    for (; i<n; ++i) {
        for (char c='a'; c<'a'+p; ++c) {
            if ((s[i-1] != c) && ((i < 2) || (s[i-2] != c))) {
                s[i]=c;
                break;
            }
        }
    }
    for (int k=0; k<n; ++k)
        cout << s[k];
    cout << "\n";
    return 0;
}
