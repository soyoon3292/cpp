#include <iostream>
using namespace std;

// 제작자 - 초기 개발자
class CMyData {
    public:     // 누구나 접근 가능
        CMyData() { cout << "CMyData()" << endl; }
        int getData() { return m_nData; }
        void setData(int nParam) { m_nData = nParam; }
    
    protected:  // 파생 클래스만 접근 가능
        void printData() { cout << "CMyData::printData()" << endl; }

    private:
        int m_nData = 0;
};

// 제작자 - 후기 개발자
class CMyDataEx : public CMyData {
    public:
        CMyDataEx() { cout << "CMyDataEx()" << endl; }
        void testFunc() {
            // 기본 형식 멤버에 접근
            printData();
            setData(5);
            cout << CMyData::getData() << endl;
        }
};

// 사용자
int main(int argc, char* argv[]) {
    CMyDataEx data;

    // 기본 클래스(CMyData) 멤버에 접근
    data.setData(10);
    cout << data.getData() << endl;

    // 파생 클래스(CMyDataEx) 멤버에 접근
    data.testFunc();

    return 0;
}