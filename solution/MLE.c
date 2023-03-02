#include <stdio.h>

#define D_SIZE 1000001
typedef struct T_info {
    int idx ;
    int atk ;
    int val ;
} info ;

info deque[D_SIZE] ;
int front, rear, ret ;

int get_size() {
    return rear - front ;
}

info get_back() {
    return deque[rear - 1] ;
}

void push_back(int idx, int atk, int val) {
    deque[rear].idx = idx ;
    deque[rear].atk = atk ;
    deque[rear].val = val ;
    ++rear ;
}

info pop_back() {
    return deque[--rear] ;
}

info pop_front() {
    return deque[front++] ;
}

void modify_back(int val) {
    deque[rear - 1].val += val ;
}

void modify_front(int val) {
    deque[front].val += val ;
}


int main() {
    int n, m ;

    scanf("%d%d", &n, &m) ;

    int top = 0 ;
    int atk, pts, val ;
    info tmp ;
    for (int idx=1; idx<=n; ++idx) {
        printf("Round %d:", idx) ;
        scanf("%d", &atk) ;

        while(get_size() && get_back().atk < atk) {
            tmp = pop_back() ;
            pts = tmp.val + (idx - tmp.idx) ;
            printf(" %d,%d", tmp.idx, pts) ;
            modify_back(pts) ;
        }
        if (get_size() == m) {
            tmp = pop_front() ;
            printf(" %d,%d", tmp.idx, top) ;
            top = top - (idx - tmp.idx) - tmp.val ;
        }
        if (get_size()) 
            top += m ;
        else 
            top = m ;

        val = m - get_size() - 1 ;
        push_back(idx, atk, val) ;

        printf("\n") ;
    }

    printf("Final:") ;
    while(get_size()) {
        tmp = pop_back() ;
        pts = tmp.val + (n+1 - tmp.idx) ;
        printf(" %d,%d", tmp.idx, pts) ;
        modify_back(pts) ;
    }
    printf("\n") ;
}