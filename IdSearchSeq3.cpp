#include <iostream>
using namespace std;

int nData = 200;

namespace TEST {
    int nData = 100;
    void testFunc(void) {
        cout << nData << endl;
    }
}

int main(int argc, char *argv[]) {
    TEST::testFunc();

    return 0;
}