#include <iostream>
using namespace std;

class CTest {
    public:
        // 디폴트 생성자 선언
        CTest(void) = default;
        // CTest(void) = delete; // error: use of deleted function 'CTest::CTest()'
        int m_nData = 5;
};

// 클래스 외부에서 디폴트 생성자 정의
CTest::CTest(void) { }

int main(int argc, char *argv[]) {
    CTest a;
    cout << a.m_nData << endl;

    return 0;
}