#include <iostream>

// std 네임스페이스를 using 예약어로 선언한다.
using namespace std;

namespace TEST {
    int g_nData = 100;

    void testFunc(void) {
        // cout에 대해서 범위를 지정하지 않아도 상관없다.
        cout << "TEST::testFunc()" << endl;
    }
}

// TEST 네임스페이스에 using 선언을 한다.
using namespace TEST;

int main(int argc, char *argv[]) {
    // testFunc()나 g_nData에도 범위 지정을 할 필요가 없다.
    testFunc();
    cout << g_nData << endl;

    return 0;
}