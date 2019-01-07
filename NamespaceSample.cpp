#include <iostream>

namespace TEST {
    int g_nData = 100;
    
    void testFunc(void) {
        std::cout << "TEST::testFunc()" << std::endl;
    }
}

int main(int argc, char *argv[]) {
    TEST::testFunc();
    std::cout << TEST::g_nData << std::endl;

    return 0;
}