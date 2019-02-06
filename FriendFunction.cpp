#include <iostream>
using namespace std;

class CMyData {
    public:
        CMyData(int nParam) : m_nData(nParam) { }
        int getData() const { return m_nData; }
        void setData(int nParam) { m_nData = nParam; }

        // friend 함수로 선언한다.
        friend void printData(const CMyData &);

    private:
        int m_nData = 0;
};

void printData(const CMyData &rData) {
    // 프렌드 함수이므로 접근 제어 지시자의 영향을 받지 않고
    // private 멤버에 직접 접근한다.
    cout << "printData(): " << rData.m_nData << endl;
}

int main(int argc, char* argv[]) {
    CMyData a(5);
    printData(a);

    return 0;
}