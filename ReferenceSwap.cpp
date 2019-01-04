#include <iostream>
using namespace std;

// 참조 전달이므로 호출자 변수의 값을 변경할 수 있다.
void swap(int &a, int &b) {
    int nTemp = a;
    a = b;
    b = nTemp;
}

int main(int argc, char *argv[]) {
    int x = 10, y = 20;

    // 참조 전달이며 두 변수의 값이 교환된다.
    swap(x, y);

    // 교환된 결과를 출력한다.
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    return 0;
}