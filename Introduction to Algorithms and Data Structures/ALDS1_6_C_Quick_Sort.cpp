#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) REPN(i,0,n)
#define REPN(i,m,n) for(int i=m; i<(n); i++)

#define MAX 100000
#define SENTINEL 2000000000

struct Card {
    char suit;
    int value;
};

Card L[MAX/2 + 2], R[MAX/2 + 2];

// Merge Sort
void merge(Card A[], int n, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;
    REP(i, n1) {
        L[i] = A[left + i];
    }
    REP(i, n2) {
        R[i] = A[mid + i];
    }
    L[n1].value = R[n2].value = SENTINEL;

    i = j = 0;
    REPN(k, left, right) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(Card A[], int n, int left, int right) {
    int mid;
    if (left + 1 < right) {
        mid = (left + right) / 2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }
}

// Quick Sort
int partition(Card A[], int n, int p, int r) {
    int i, j;
    Card t, x;
    x = A[r];
    i = p - 1;
    
    REPN(j, p, r) {
        if (A[j].value <= x.value) {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }

    t = A[i + 1];
    A[i + 1] = A[r];
    A[r] = t;
    return i + 1;
}

void quickSort(Card A[], int n, int p, int r) {
    int q;
    if (p < r) {
        q = partition(A, n, p, r);
        quickSort(A, n, p, q - 1);
        quickSort(A, n, q + 1, r);
    }
}

int main() {
    int n, i, v;
    Card A[MAX], B[MAX];
    char S[10];
    int stable = 1;

    cin >> n;

    REP(i, n) {
        cin >> S;
        cin >> v;
        A[i].suit = B[i].suit = S[0];
        A[i].value = B[i].value = v;
    }

    mergeSort(A, n, 0, n);
    quickSort(B, n, 0, n - 1);

    REP(i, n) {
        if (A[i].suit != B[i].suit) {
            stable = 0;
        }
    }

    if (stable == 1) {
        cout << "Stable" << '\n';
    } else {
        cout << "Not stable" << '\n';
    }
    REP(i, n) {
        cout << B[i].suit << " " << B[i].value << '\n';
    }
}