#include <iostream>
using namespace std;

class CTest {
    public:
        CTest() {
            cout << "CTest::CTest()" << endl;
        }

        ~CTest() {
            cout << "CTest::~CTest()" << endl;
        }
};

int main(int argc, char *argv[]) {
    cout << "Begin" << endl;
    CTest t;
    cout << "End" << endl;

    return 0;
}