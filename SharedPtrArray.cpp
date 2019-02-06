#include <iostream>
#include <memory>
using namespace std;

class CTest {
    public:
        CTest() { cout << "CTest()" << endl; }
        ~CTest() { cout << "~CTest()" << endl; }
        void testFunc() { cout << "testFunc()" << endl; }
};

void removeTest(CTest *pTest) {
    cout << "removeTest()" << endl;

    // 대상을 배열로 삭제한다.
    delete[] pTest;
}

int main(int argc, char* argv[]) {
    cout << "*****Begin*****" << endl;

    // 대상 객체를 소멸할 함수를 별도로 등록한다.
    shared_ptr<CTest> ptr(new CTest[3], removeTest);
    cout << "******End******" << endl;
    ptr.reset();

    return 0;
}