#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int a = 100, b;
    cout << "Input number: ";
    cin >> b;

    // 사용자가 입력한 수로 100을 나누고 출력한다.
    if(b > 0)
        cout << a / b << endl;
    
    else
        cout << "ERROR: 0으로 나눌 수 없습니다." << endl;

    return 0;
}