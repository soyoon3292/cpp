#include <iostream>
using namespace std;

void testFunc(int &rParam) {
    cout << "testFunc(int &)" << endl;
}

void testFunc(int &&rParam) {
    cout << "testFunc(int &&)" << endl;
}

int main(int argc, char *argv[]) {
    // 3 + 4 연산 결과는 r-value이다. 절대로 l-value가 될 수 없다.
    testFunc(3 + 4);

    return 0;
}