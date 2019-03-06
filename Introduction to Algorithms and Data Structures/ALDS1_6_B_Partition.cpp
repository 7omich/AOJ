#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) REPN(i,0,n)
#define REPN(i,m,n) for(int i=m; i<(n); i++)

#define MAX 100000

int A[MAX], n;

int partition(int p, int r) {
    int x, i;
    x = A[r];
    i = p - 1;
    REPN(j, p, r) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i + 1;
}

int main() {
    int i, q;

    cin >> n;
    REP(i, n) {
        cin >> A[i];
    }

    q = partition(0, n-1);

    REP(i, n) {
        if (i) {
            cout << " ";
        }
        if (i == q) {
            cout << "[";
        }
        cout << A[i];
        if (i == q) {
            cout << "]";
        }
    }
    cout << "\n";
}