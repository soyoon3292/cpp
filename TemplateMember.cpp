#include <iostream>
using namespace std;

template<typename T>
class CTest {
    public:
        // 생성자 선언
        CTest();
        T testFunc();

    protected:
        // 정적 멤버 데이터 선언
        static T m_Data;
};

// 생성자 정의
template<typename T>
CTest<T>::CTest() {

}

// 멤버 함수 정의
template<typename T>
T CTest<T>::testFunc() {
    return m_Data;
}

// 정적 멤버 변수 정의
template<typename T>
T CTest<T>::m_Data = 15;

int main(int argc, char* argv[]) {
    CTest<double> a;
    cout << a.testFunc() << endl;

    return 0;
}