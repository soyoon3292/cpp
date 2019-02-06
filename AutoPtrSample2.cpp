#include <iostream>
#include <memory>
using namespace std;

class CMyData {
    public:
        CMyData() { cout << "CMyData()" << endl; }
        ~CMyData() { cout << "~CMyData()" << endl; }
        void testFunc() { cout << "CMyData::testFunc()" << endl; }
};

int main(int argc, char* argv[]) {
    auto_ptr<CMyData> ptrTest(new CMyData);
    auto_ptr<CMyData> ptrNew;

    cout << ptrTest.get() << endl;

    // 포인터를 대입하면 원본 포인터는 NULL이 된다.
    ptrNew = ptrTest;
    cout << ptrTest.get() << endl;

    // 따라서 이 코드를 실행할 수 없다.
    ptrTest->testFunc();

    return 0;
}