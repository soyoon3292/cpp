#include <iostream>
using namespace std;

// r-value 참조 형식
void testFunc(int &&rParam) {
    cout << "testFunc(int &&)" << endl;
}

// r-value 참조 형식과 호출자 코드가 같다.
void testFunc(int nParam) {
    cout << "testFunc(int)" << endl;
}

int main(int argc, char* argv[]) {
    // 모호한 호출이다. int형과 int&&형 모두 가능하다!
    testFunc(3 + 4);

    return 0;
}