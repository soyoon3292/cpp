#include <iostream>
#include <cstring>
using namespace std;

class CMyException {
    public:
        // 예외 코드와 메시지를 입력받는다.
        CMyException(int nCode, const char *pszMsg) {
            m_nErrorCode = nCode;
            strncpy(m_szMsg, pszMsg, sizeof(m_szMsg));
        }

        int getErrorCode() const { return m_nErrorCode; }
        const char* getMessage() const { return m_szMsg; }
    
    private:
        int m_nErrorCode;
        char m_szMsg[128];
};

int main(int argc, char* argvp[]) {
    try {
        int nInput = 0;
        cout << "양의 정수를 입력하세요.: ";
        cin >> nInput;

        if(nInput < 0) {
            CMyException exp(10, "양의 정수를 입력해야 합니다.");
            throw exp;
        }
    }

    catch(CMyException &exp) {
        cout << "ERROR CODE [" << exp.getErrorCode() << "] " << exp.getMessage() << endl;
    }

    return 0;
}