// did not reset top

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

void push_back(int idx, int atk, int val) {
    deque[rear].idx = idx ;
    deque[rear].atk = atk ;
    deque[rear].val = val ;
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

void modify_back(int val) {
    deque[SUB(rear)].val += val ;
}

void modify_front(int val) {
    deque[front].val += val ;
}


int main() {
    int n, m ;

    scanf("%d%d", &n, &m) ;

    int top = 0 ;
    for (int idx=1; idx<=n; ++idx) {
        printf("Round %d:", idx) ;

        int atk ;
        scanf("%d", &atk) ;

        while(get_size() && get_back().atk < atk) {
            info tmp = pop_back() ;
            int pts = tmp.val + (idx - tmp.idx) ;
            printf(" %d,%d", tmp.idx, pts) ;
            modify_back(pts) ;
        }
        if (get_size() == m) {
            info tmp = pop_front() ;
            printf(" %d,%d", tmp.idx, top) ;
            top = top - (idx - tmp.idx) - tmp.val ;
        }
        top += m ;

        int val = m - get_size() - 1 ;
        push_back(idx, atk, val) ;

        printf("\n") ;
    }

    printf("Final:") ;
    while(get_size()) {
        info tmp = pop_back() ;
        int pts = tmp.val + (n+1 - tmp.idx) ;
        printf(" %d,%d", tmp.idx, pts) ;
        modify_back(pts) ;
    }
    printf("\n") ;
}