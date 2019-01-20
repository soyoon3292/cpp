#include <iostream>
using namespace std;

// 제작자 코드
class CTestData {
    public:
        CTestData() { cout << "CTestData()" << endl; }
        ~CTestData() { cout << "~CTestData()" << endl; }

        CTestData(const CTestData &rhs) : m_nData(rhs.m_nData) {
            cout << "CTestData(const CTestData &)" << endl;
        }

        // 이동 생성자
        CTestData(CTestData &&rhs) : m_nData(rhs.m_nData) {
            cout << "CTestData(const CTestData &&)" << endl;
        }
        CTestData& operator=(const CTestData &) = default;

        int getData() const { return m_nData; }
        void setData(int nParam) { m_nData = nParam; }

    private:
        int m_nData = 0;
};

CTestData testFunc(int nParam) {
    cout << "**testFunc(): Begin***" << endl;
    CTestData a;
    a.setData(nParam);
    cout << "**testFunc(): End*****" << endl;

    return a;
}

int main(int argc, char* argv[]) {
    CTestData b;
    cout << "*Before***************" << endl;
    b = testFunc(20);
    cout << "*After****************" << endl;
    CTestData c(b);

    return 0;
}