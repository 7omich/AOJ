#include <iostream>
using namespace std;

#define REP(i,n) REPN(i,0,n)
#define REPN(i,m,n) for(int i=m; i<(n); i++)

#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2 + 2], R[MAX/2 + 2];
int cnt;

void merge(int A[], int n, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    REP(i, n1) {
        L[i] = A[left + i];
    }
    REP(i, n2) {
        R[i] = A[mid + i];
    }
    L[n1] = R[n2] = SENTINEL;

    int i = 0, j = 0;
    REPN(k, left, right) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(int A[], int n, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

int main() {
    int A[MAX], n, i;
    cnt = 0;

    cin >> n;
    REP(i, n) {
        cin >> A[i];
    }

    mergeSort(A, n, 0, n);

    REP(i, n) {
        if (i) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << '\n';
    cout << cnt << '\n';
}