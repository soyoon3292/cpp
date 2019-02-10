#include <new>
#include <iostream>
using namespace std;

class CTest {
    public:
        CTest(int nSize) {
            // 메모리 할당에 실패하면 예외를 던진다!
            m_pszData = new char[nSize];
        }

        ~CTest() {
            delete[] m_pszData;
            cout << "정상적으로 객체가 소멸함" << endl;
        }

    private:
        char *m_pszData;
};

int main(int argc, char* argv[]) {
    try {
        int nSize;
        cout << "Input size: ";

        // 사용자가 입력한 값을 검증 없이 그대로 사용해 객체를 생성
        cin >> nSize;
        CTest a(nSize);
    }
    
    catch(bad_alloc &exp) {
        // 시스템이 밝힌 원인을 출력한다.
        cout << exp.what() << endl;
        cout << "ERROR: CTest()" << endl;
    }

    return 0;
}