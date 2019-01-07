#include <iostream>
using namespace std;

// 전역(개념상 무소속)
void testFunc(void) { cout << "::testFunc()" << endl; }

// using namespace TEST; // error
namespace TEST {
    // TEST 네임스페이스 소속
    void testFunc(void) {
        cout << "TEST::testFunc()" << endl;
    }
}

// using namespace MYDATA; // error
namespace MYDATA {
    // MYDATA 네임스페이스 소속
    void testFunc(void) {
        cout << "MYDATA::testFunc()" << endl;
    }
}

int main(int argc, char *argv[]) {
    testFunc();
    ::testFunc();
    TEST::testFunc();
    MYDATA::testFunc();

    return 0;
}