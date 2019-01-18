#include <iostream>
using namespace std;

// 제작자 코드
class CTestData {
    public:
        explicit CTestData(int nParam) : m_nData(nParam) { }

        // CTestData 클래스는 int 자료형으로 변환될 수 있다!
        explicit operator int(void) { return m_nData; }

        int getData() const { return m_nData; }
        void setData(int nParam) { m_nData = nParam; }

    private:
        int m_nData = 0;
};

// 사용자 코드
int main(int argc, char *argv[]) {
    CTestData a(10);
    cout << a.getData() << endl;

    // CTestData 형식에서 int 자료형으로 변환될 수 있다.
    // cout << a << endl; // error: no match for 'operator<<' (operand types are 'std::ostream' {aka 'std::basic_ostream<char>'} and 'CTestData')
    // cout << (int)a << endl;
    cout << static_cast<int>(a) << endl;

    return 0;
}