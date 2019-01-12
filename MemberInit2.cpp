#include <iostream>
using namespace std;

// 제작자 코드
class CTest {
    public:
        // CTest 클래스의 '생성자 함수' 선언 및 정의
        CTest() {
            // 인스턴스가 생성되면 멤버 데이터를 '자동'으로 초기화한다.
            cout << "CTest() : 생성자 함수" << endl;
            m_nData = 10;
        }

        // 멤버 데이터 선언
        int m_nData;

        // 멤버 함수 선언 및 정의
        void printData(void) {
            // 멤버 데이터에 접근하고 값을 출력한다.
            cout << m_nData << endl;
        }

        // ~CTest() {
        //     cout << "CTest() : 소멸자 함수" << endl;
        // }
};

// 사용자의 코드
int main(int argc, char *argv[]) {
    cout << "main() 함수 시작" << endl;

    CTest t;
    t.printData();

    cout << "main() 함수 끝" << endl;

    return 0;
}