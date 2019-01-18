#include <iostream>
using namespace std;

// 제작자 코드
class CTestData {
    public:
        // 매개변수가 하나뿐인 생성자는 형변환이 가능하다.
        // 하지만 묵시적으로는 불가능하도록 차단한다.
        explicit CTestData(int nParam) : m_nData(nParam) {
            cout << "CTestData(int)" << endl;
        }

        CTestData(const CTestData &rhs) : m_nData(rhs.m_nData) {
            cout << "CTestData(const CTestData &)" << endl;
        }

        ~CTestData() {
            cout << "~CTestData()" << endl;
        }

        int getData() const { return m_nData; }
        void setData(int nParam) { m_nData = nParam; }

    private:
        int m_nData = 0;
};

// 사용자 코드
// 매개변수가 클래스 형식이며 변환 생성이 가능하다.
void testFunc(const CTestData &param) {
    cout << "testFunc(): " << param.getData() << endl;
}

int main(int argc, char *argv[]) {
    cout << "*****Begin*****" << endl;

    // 새로운 CTestData 객체를 생성하고 참조로 전달한다.
    // testFunc(5); // error: invalid initializationof reference of type 'const CTestData&' from expression of type 'int'
    testFunc(CTestData(5));

    // 함수가 반환되면서 임시 객체는 소멸한다.
    cout << "******End******" << endl;

    return 0;
}