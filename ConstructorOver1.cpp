#include <iostream>
using namespace std;

class CMyData {
    public:
        // 디폴트 생성자는 없다.
        // 매개변수가 int 하나인 생성자 함수 선언 및 정의
        CMyData(int nParam) : m_nData(nParam) { };

        // 매개변수가 int 자료형 두 개인 생성자 함수 다중 정의
        CMyData(int x, int y) : m_nData(x + y) { };
        int getData(void) { return m_nData; }

    private:
        int m_nData;
};

int main(int argc, char *argv[]) {
    CMyData a(10);
    CMyData b(3, 4);

    cout << a.getData() << endl;
    cout << b.getData() << endl;

    return 0;
}