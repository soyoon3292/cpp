#include <iostream>
using namespace std;

// 초기 제작자
class CMyData {
    public:
        int getData() { return m_nData; }

        void setData(int nParam) { m_nData = nParam; }

    private:
        int m_nData = 0;
};

// 후기 제작자
class CMyDataEx : public CMyData {
    public:
        // 파생 클래스에서 기본 클래스의 메서드를 재정의했다.
        void setData(int nParam) {
            // 입력 데이터의 값을 보정하는 새로운 기능을 추가한다.
            if(nParam < 0)
                CMyData::setData(0);

            if(nParam > 10)
                CMyData::setData(10);
        }
};

// 사용자 코드
int main(int argc, char* argv[]) {
    // 구형에는 값을 보정하는 기능이 없다.
    CMyData a;
    a.setData(-10);
    cout << a.getData() << endl;

    // 신형에는 값을 보정하는 기능이 있다.
    CMyDataEx b;
    b.setData(15);
    cout << b.getData() << endl;

    return 0;
}