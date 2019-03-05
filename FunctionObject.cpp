#include <iostream>
using namespace std;

// 함수 객체 클래스의 선언 및 정의
class Add {
    public:
        // 함수 호출 연산자를 다중 정의한다.
        int operator()(int a, int b) {
            cout << "()(int, int)" << endl;

            return a + b;
        }

        // 다양한 매개변수 구성으로 다중 정의할 수 있다.
        double operator()(double a, double b) {
            cout << "()(double, double)" << endl;

            return a + b;
        }
};

// 제작자 철수의 코드
void testFunc(Add &add) {
    // 사용자가 만든 함수를 제작자가 호출한다.
    cout << add(3, 4) << endl;
}

int main(int argc, char* argv[]) {
    Add adder;

    // 함수 객체로 호출한다.
    cout << adder(3, 4) << endl;
    cout << adder(3.3, 4.4) << endl;

    testFunc(adder);
    
    return 0;
}