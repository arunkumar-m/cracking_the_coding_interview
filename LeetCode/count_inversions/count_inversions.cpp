#include <iostream>
#include <fstream>
using namespace std;

int *mergeAndCountInversions(int *B, int *C, int m, int n, long long &cnt) {
    int *D = new int[m + n];
    int bi = 0, ci = 0;
    cnt = 0;
    for (int i = 0; i < m + n; i++) {
        if (bi < m && ci < n) {
            if (B[bi] < C[ci]) {
                D[i] = B[bi];
                bi++;
            }
            else {
                D[i] = C[ci];
                ci++;
                cnt += m - bi;
            }
        }
        else {
            if (bi < m) {
                D[i] = B[bi];
                bi++;
            }
            else {
                D[i] = C[ci];
                ci++;
                cnt += m - bi;
            }
        }
    }
    return D;
}

int *splitAndCountInversions(int *A, int n, long long &cnt) {
    if (n == 0) {
        cnt = 0;
        return NULL;
    }
    else if (n == 1) {
        cnt = 0;
        int *D = new int[1];
        D[0] = A[0];
        return D;
    }
    long long x = 0, y = 0, z = 0;
    int *B = splitAndCountInversions(A, n / 2, x);
    int *C = splitAndCountInversions(A + n / 2, (n + 1) / 2, y);
    int *D = mergeAndCountInversions(B, C, n / 2, (n + 1) / 2, z);
    delete[] B;
    delete[] C;
    cnt = x + y + z;
    return D;
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {
    ifstream ifile("IntegerArray.txt");
    int arr[100000];
    for (int i = 0; i < 100000; i++) {
        ifile >> arr[i];
    }
    ifile.close();
    long long cnt = 0;
    int *array = splitAndCountInversions(arr, 100000, cnt);
    cout << cnt << endl;
    return 0;
}

