#include <iostream>
using namespace std;

// 제작자 코드
class CMyData {
    public:
        CMyData() : m_nData(0) { };

        int getData(void) { return m_nData; }
        void setData(int nParam) { m_nData = nParam; }

        // 실수로 double 자료형 실인수가 넘어오는 경우를 차단한다.
        void setData(double dParam) = delete;

    private:
        int m_nData;
};

// 사용자 코드
int main(int argc, char *argv[]) {
    CMyData a;

    // CMyData::setData(int) 메서드가 호출된다.
    a.setData(10);
    cout << a.getData() << endl;

    // CMyData b;

    // CMyData::setData(double) 메서드가 호출된다.
    // b.setData(5.5); // error: use of deleted function 'void CMyData::setData(double)'
    // cout << b.getData() << endl;

    return 0;
}