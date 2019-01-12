#include <iostream>
using namespace std;

// 제작자 코드
class CMyData {
    // 기본 접근 제어 지시자는 'private'이다.
    int m_nData;

    public:
        int getData(void) { return m_nData; }
        void setData(int nParam) { m_nData = nParam; }
};

// 사용자 코드
int main(int argc, char *argv[]) {
    CMyData data;
    // data.m_nData = 10; // error: 'int CMyData::m_nData'is private within this context
    data.setData(10);
    cout << data.getData() << endl;

    return 0;
}