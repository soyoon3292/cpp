#include <iostream>

int main(int argc, char *argv[]) {
    int *pData = new int;
    int *pNewData = new int(10);

    *pData = 5;

    std::cout << *pData << std::endl;
    std::cout << *pNewData << std::endl;

    delete pData;
    delete pNewData;
}