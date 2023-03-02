#include <stdio.h>

typedef struct T_info {
    int idx ;
    int atk ;
    int val ;
} info ;

#define D_SIZE 1010 

info deque[D_SIZE] ;
int front, rear ;

int get_size() {
    return (rear - front) ;
}

info get_back() {
    return deque[rear-1] ;
}

void push_back(int idx, int atk) {
    deque[rear].idx = idx ;
    deque[rear].atk = atk ;
    deque[rear].val = 0 ;
    ++rear ;
}

info pop_back() {
    return deque[--rear] ;
}

info pop_front() {
    return deque[front++] ;
}

void update_score(int m) {
    int score = m ;
    for (int i=front; i<rear; ++i) {
        deque[i].val += score ;
        --score ;
    }
}

int main() {
    int n, m ;
    scanf("%d%d", &n, &m) ;

    for(int idx=1; idx<=n; ++idx) {
        printf("Round %d:", idx) ;
        int atk ;
        scanf("%d", &atk) ;

        while(get_size() && get_back().atk < atk) {
            info tmp = pop_back() ;
            printf(" %d,%d", tmp.idx, tmp.val) ;
        }
        if (get_size() == m) {
            info tmp = pop_front() ;
            printf(" %d,%d", tmp.idx, tmp.val) ;
        }
        push_back(idx, atk) ;
        update_score(m) ;

        printf("\n") ;
    }

    printf("Final:") ;
    while(get_size()) {
        info tmp = pop_back() ;
        printf(" %d,%d", tmp.idx, tmp.val) ;
    }
    printf("\n") ;
}