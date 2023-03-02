#include "testlib.h"
#include <bits/stdc++.h>
using namespace std ;

// a[i+1] \in [a[i]-bot, a[i]+top] 

const int R = 1000000000 ;
deque<int> dq ;

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1) ;
	int n = atoi(argv[1]) ; // number of players
	int m = atoi(argv[2]) ; // capacity
	int p = atoi(argv[3]) ; // a1
	int bot = atoi(argv[4]) ;  
	int top = atoi(argv[5]) ;
	int spike = atoi(argv[6]) ; // spike chance 

	int flag = 0 ;
	if (argc > 7)
		flag = 1 ;

	int ori = p ;
	printf("%d %d\n", n, m) ;
	printf("%d", p) ;
	dq.push_back(p) ;
	for (int i=1; i<n; ++i) {
		p = rnd.next(max(1, p-bot), min(R, p+top)) ;
		if (rnd.next(spike) == 0) 
			p = min(R, ori + rnd.next(777777)) ;

		if (flag) {
			while(dq.size() && dq.back() < p) 
				dq.pop_back() ;
			if (dq.size() == m) {
				p = dq.front() + rnd.next(1, 7777) ;
				assert(p <= R) ;
				dq.clear() ;
			}
			dq.push_back(p) ;
		}

		printf(" %d", p) ;
	}
	printf("\n") ;
}