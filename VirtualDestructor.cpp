#include <iostream>
using namespace std;

// 제작자 코드
class CMyData {
    public:
        CMyData() { m_pszData = new char[32]; }
        virtual ~CMyData() {
            cout << "~CMyData()" << endl;
            delete m_pszData;
        }

    private:
        char *m_pszData = nullptr;
};

class CMyDataEx : public CMyData {
    public:
        CMyDataEx() { m_pnData = new int; }
        ~CMyDataEx() {
            cout << "~CMyDataEx()" << endl;
            delete m_pnData;
        }
    
    private:
        int *m_pnData;
};

// 사용자 코드
int main(int argc, char* argv[]) {
    CMyData *pData = new CMyDataEx;

    // 참조 형식에 맞는 소멸자가 호출된다.
    delete pData;

    return 0;
}