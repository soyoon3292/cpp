#include <iostream>
using namespace std;

class CTest {
    int m_nData;

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

    // new 연산자를 이용해 동적으로 객체를 생성한다.
    CTest *pData1 = new CTest;
    CTest *pData2 = new CTest[3];
    cout << "Test" << endl;

    // delete 연산자를 이용해 객체를 삭제한다.
    delete pData1;
    delete[] pData2; // 반드시 배열형태로 delete 해주어야 한다.
    cout << "End" << endl;

    return 0;
}