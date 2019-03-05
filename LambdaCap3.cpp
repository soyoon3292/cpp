#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int x = 10, y = 20;

    auto testFunc = [x, y]() -> int {
        return x + y;
    };

    cout << testFunc() << endl;

    return 0;
}