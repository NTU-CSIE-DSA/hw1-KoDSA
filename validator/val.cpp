#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int N = 1000000 ;
int M = 1000 ;
int R = 1000000000 ;

int main() {
	registerValidation();
	int n = inf.readInt(1, N) ; inf.readSpace() ;
	int m = inf.readInt(1, M) ; inf.readEoln() ;

	for (int i=0; i<n; ++i) {
		int atk = inf.readInt(1, R) ; 
		if (i == n-1)
			inf.readEoln() ;
		else 
			inf.readSpace() ;
	}
	inf.readEof() ;
}
