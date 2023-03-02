#include "testlib.h"
#include <bits/stdc++.h>
using namespace std ;

const int MXR = 1000000000 ;
deque<int> dq ;

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1) ;
	int n = atoi(argv[1]) ; // number of players
	int m = atoi(argv[2]) ; // capacity
	int R = atoi(argv[3]) ; // atk range [1, R]
	int flag = 0 ;
	if (argc > 4)
		flag = 1 ;

	printf("%d %d\n", n, m) ;
	for (int i=0; i<n; ++i) {
		int atk = rnd.next(1, R) ;

		if (flag) {
			while(dq.size() && dq.back() < atk) 
				dq.pop_back() ;
			if (dq.size() == m) {
				atk = dq.front() + rnd.next(1, 7777) ;
				assert(atk <= MXR) ;
				dq.clear() ;
			}
			dq.push_back(atk) ;
		}

		printf("%d%c", atk, " \n"[i == n-1]) ;
	}
}