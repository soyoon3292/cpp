// string 클래스를 사용하기 위한 헤더
#include <string>

#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    string strName;
    cout << "이름: ";
    cin >> strName;
    cout << "당신의 이름은 " + strName + "입니다." << endl;

    return 0;
}