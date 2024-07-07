#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <iostream>
#include <string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include <iomanip>
#include <fstream>
#define endl '\n'    // endl 대신 '\n'을 사용
using namespace std;
int curCnt = 0;

void check(int s) {
    if (s == 1) return;
    else if (s % 2 == 0) {
        s /= 2;
        curCnt++;
        check(s);

    }
    else {
        s = (s * 3) + 1;
        curCnt++;
        check(s);
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int s = 2;
    int n, m;
    ifstream fin;
    fin.open("3nplus1.inp");
    ofstream fout;
    fout.open("3nplus1.out");
    while (fin >> n >> m) {
        int cur;
        int end;
        int maxCnt = 0;
        if (n > m) {
            cur = m;
            end = n;
        }
        else {
            cur = n;
            end = m;
        }
        while (cur <= end) {
            check(cur);
            maxCnt = max(curCnt, maxCnt);
            cur++;
            curCnt = 0;
        }
        fout << n << " " << m << " " << maxCnt + 1 << endl;

    }

}
