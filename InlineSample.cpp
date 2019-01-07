#include <cstdio>

#define ADD(a, b)((a) + (b))

int add(int a, int b) {
    return a + b;
}

inline int addNew(int a, int b) {
    return a + b;
}

int main(int argc, char *argv[]) {
    int a, b;
    scanf("%d%d", &a, &b);

    printf("ADD(): %d \n", ADD(a, b));
    printf("add(): %d \n", add(a, b));
    printf("addNew(): %d \n", addNew(a, b));

    return 0;
}