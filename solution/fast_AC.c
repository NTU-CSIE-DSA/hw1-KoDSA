#include <stdio.h>
#include <stdlib.h>

#define D_SIZE 1001
typedef struct T_info {
    int idx ;
    int atk ;
    int val ;
} info ;

info deque[D_SIZE] ;
int front, rear, ret ;

#define ADD(x) ((x)+1 == D_SIZE ? 0 : (x)+1)
#define SUB(x) ((x) == 0 ? D_SIZE-1 : (x)-1)

static inline int get_size() {
    return (rear >= front ? rear - front : D_SIZE - front + rear) ;
}

static inline info get_back() {
    return deque[SUB(rear)] ;
}

static inline void push_back(int idx, int atk, int val) {
    deque[rear].idx = idx ;
    deque[rear].atk = atk ;
    deque[rear].val = val ;
    rear = ADD(rear) ;
}

static inline info pop_back() {
    rear = SUB(rear) ;
    return deque[rear] ;
}

static inline info pop_front() {
    ret = front ;
    front = ADD(front) ;
    return deque[ret] ;
}

static inline void modify_back(int val) {
    deque[SUB(rear)].val += val ;
}

static inline void modify_front(int val) {
    deque[front].val += val ;
}

#define BUF_SZ 262144
char i_buf[BUF_SZ], *p1=i_buf, *p2=i_buf ;
#define getchar() (p1==p2&&(p2=(p1=i_buf)+fread(i_buf,1,BUF_SZ,stdin),p1==p2)?EOF:*p1++)
static inline int read() {
    int s=0;
    char ch=getchar(), last ;
    while(ch<'0'||ch>'9') last=ch,ch=getchar() ;
    while(ch>='0'&&ch<='9') s=(s<<1)+(s<<3)+(ch^48),ch=getchar() ;
    return last=='-'?-s:s;
}

char o_buf[BUF_SZ] ;
int pos ;
static inline void flush_out() {
    fwrite(o_buf, 1, pos, stdout) ;
    pos = 0 ;
}
static inline void write_char(char c) {
    if (pos == BUF_SZ) 
        flush_out() ;
    o_buf[pos++] = c ;
}
static inline void write_int(int x) {
    static char num_buf[100] ;
    int len = 0 ;
    for (; x>=10; x/=10) 
        num_buf[len++] = (char)('0' + (x%10)) ;
    write_char((char)('0'+x)) ;
    while(len)
        write_char(num_buf[--len]) ;
}
static inline void write_two_int(int x, int y) {
    write_char(' ') ;
    write_int(x) ;
    write_char(',') ;
    write_int(y) ;
}
static char round[] = "Round " ;
static char final[] = "Final:" ;
static inline void write_round(int x) {
    for (int i=0; i<6; ++i)
        write_char(round[i]) ;
    write_int(x) ;
    write_char(':') ;
}
static inline void write_final() {
    for (int i=0; i<6; ++i)
        write_char(final[i]) ;
}


int main() {
    atexit(flush_out) ;
    int n, m ;

    n = read() ;
    m = read() ;

    int atk, pts, val, top = 0 ;
    info tmp ;
    for (int idx=1; idx<=n; ++idx) {
        write_round(idx) ;
        atk = read() ;

        while(get_size() && get_back().atk < atk) {
            tmp = pop_back() ;
            pts = tmp.val + (idx - tmp.idx) ;
            write_two_int(tmp.idx, pts) ;
            modify_back(pts) ;
        }
        if (get_size() == m) {
            tmp = pop_front() ;
            write_two_int(tmp.idx, top) ;
            top = top - (idx - tmp.idx) - tmp.val ;
        }
        if (get_size()) 
            top += m ;
        else 
            top = m ;

        val = m - get_size() - 1 ;
        push_back(idx, atk, val) ;

        write_char('\n') ;
    }

    write_final() ;
    while(get_size()) {
        tmp = pop_back() ;
        pts = tmp.val + (n+1 - tmp.idx) ;
        write_two_int(tmp.idx, pts) ;
        modify_back(pts) ;
    }
    write_char('\n') ;
}