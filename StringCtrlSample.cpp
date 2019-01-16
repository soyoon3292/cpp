#include "MyString.h"
#include <iostream>
using namespace std;

void testFunc(const CMyString &param) {
    cout << param.getString() << endl;
}

int main(int argc, char *argv[]) {
    CMyString strData;
    strData.setString("Hello");
    cout << strData.getString() << endl;
    testFunc(strData);
    strData.setString("World!");
    cout << strData.getString() << endl;

    return 0;
}