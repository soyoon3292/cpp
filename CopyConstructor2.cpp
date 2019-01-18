#include <iostream>
using namespace std;

class CMyData {
    public:
        CMyData() { cout << "CMyData()" << endl; }

        int getData(void) const { return m_nData; }
        void setData(int nParam) { m_nData = nParam; }

    private:
        int m_nData = 0;
};

int main(int argc, char *argv[]) {
    // 디폴트 생성자가 호출되는 경우
    CMyData a;
    a.setData(10);

    // 복사 생성자가 호출되는 경우
    CMyData b(a);
    cout << b.getData() << endl;

    return 0;
}