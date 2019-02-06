#include <memory>
#include <iostream>
using namespace std;

class CTest {
    public:
        CTest() { cout << "CTest()" << endl; }
        ~CTest() { cout << "~CTest()" << endl; }
        void testFunc() { cout << "testFunc()" << endl; }
};

int main(int argc, char* argv[]) {
    unique_ptr<CTest> ptr1(new CTest);

    // 아래 코드들은 실행하면 모두 컴파일 오류가 발생한다.
    // unique_ptr<CTest> ptr2(ptr1);
    // ptr2 = ptr1;

    return 0;
}