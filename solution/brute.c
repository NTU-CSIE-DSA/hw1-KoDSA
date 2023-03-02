#include <stdio.h>

#define D_SIZE 1001
typedef struct T_info {
    int idx ;
    int atk ;
    int val ;
} info ;

info deque[D_SIZE] ;
int front, rear ;

#define ADD(x) (((x) + 1) % D_SIZE)
#define SUB(x) (((x) - 1 + D_SIZE) % D_SIZE)

int get_size() {
    return (rear - front + D_SIZE) % D_SIZE ;
}

info get_back() {
    return deque[SUB(rear)] ;
}

void push_back(int idx, int atk) {
    deque[rear].idx = idx ;
    deque[rear].atk = atk ;
    deque[rear].val = 0 ;
    rear = ADD(rear) ;
}

info pop_back() {
    rear = SUB(rear) ;
    return deque[rear] ;
}

info pop_front() {
    int ret = front ;
    front = ADD(front) ;
    return deque[ret] ;
}

void update_score(int m) {
    int len = get_size() ;
    int p = front ;
    while(len--) {
        deque[p].val += m-- ;
        p = ADD(p) ;
    }
}


int main() {
    int n, m ;

    scanf("%d%d", &n, &m) ;

    for (int idx=1; idx<=n; ++idx) {
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