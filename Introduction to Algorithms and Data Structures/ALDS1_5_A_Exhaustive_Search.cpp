#include <iostream>
using namespace std;

#define REP(i,n) REPN(i,0,n)
#define REPN(i,m,n) for(int i=m; i<(n); i++)

int n, A[50];

bool solve(int i, int m) {
    if (m == 0) {
        return true;
    }
    if (i >= n) {
        return false;
    }
    bool res = solve(i + 1, m) || solve(i + 1, m - A[i]);
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int q, M, i;
    cin >> n;
    REP(i, n) {
        cin >> A[i];
    }
    cin >> q;
    REP(i, q) {
        cin >> M;
        if (solve(0, M)) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }
}
