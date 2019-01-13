#include "MyString.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    CMyString strData;
    strData.setString("Hello");
    cout << strData.getString() << endl;

    return 0;
}