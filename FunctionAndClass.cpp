#include <iostream>
using namespace std;

class CTestData {
    public:
        CTestData(int nParam) : m_nData(nParam) {
            cout << "CTestData(int)" << endl;
        }

        CTestData(const CTestData &rhs) : m_nData(rhs.m_nData) {
            cout << "CTestData(const CTestData &)" << endl;
        }

        // 읽기 전용인 상수형 매서드
        int getData() const { return m_nData; }

        // 멤버 변수에 쓰기를 시도하는 매서드
        void setData(int nParam) { m_nData = nParam; }

    private:
        int m_nData = 0;
};

// 매개변수가 CTestData 클래스 형식이므로 복사 생성자가 호출된다.
void testFunc(const CTestData &param) {
    cout << "testFunc()" << endl;

    // 피호출자 함수에서 매개변수 인스턴스의 값을 변경한다.
    param.setData(20);
}

int main(int argc, char *argv[]) {
    cout << "*****Begin*****" << endl;
    CTestData a(10);
    testFunc(a);

    // 함수 호출 후 a의 값을 출력한다.
    cout << "a: " << a.getData() << endl;

    cout << "******End******" << endl;

    return 0;
}