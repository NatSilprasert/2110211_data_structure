#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {    
    int n;
    cin >> n;
    while (n--) {
        int mFront, mSize, mCap, last, correction;
        cin >> mFront >> mSize >> mCap >> last >> correction;
        if (mFront < mCap &&
            mCap >= mSize &&
            last < mCap &&
            (mFront + mSize) % mCap == last)
        {
            cout << "OK\n";
            continue;
        }
           
        cout << "WRONG" << " ";
        if (correction == 0) cout << "\n";

        if (correction == 1) {
            cout << (last + mCap - mSize) % mCap << "\n";
        }
        if (correction == 2) {
            cout << (mCap + last - mFront) % mCap << "\n";
        }
        if (correction == 3) {
            if (mFront < last) cout << mSize + mFront + 1 << "\n";
            else cout << mFront - last + mSize << "\n";
        }
        if (correction == 4) {
            cout << (mFront + mSize) % mCap << "\n";
        }
    } 

    return 0;
}