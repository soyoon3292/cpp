#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int nData = 10;
    cout << nData << endl;
    auto testFunc = [nData](void)->void {
        cout << nData << endl;
    };
    // auto testFunc = [nData](void)
    // auto testFunc = [nData]()
    // auto testFunc = [nData];;
    testFunc();

    return 0;
}