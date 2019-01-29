#include <iostream>
using namespace std;

class CMyData {
    public:
        CMyData() {
            cout << "CMyData()" << endl;
        }

        virtual ~CMyData() { }
        virtual void testFunc1() { }
        virtual void testFunc2() { }
};

class CMyDataEx : public CMyData {
    public:
        CMyDataEx() {
            cout << "CMyDataEx()" << endl;
        }

        virtual ~CMyDataEx() { }
        virtual void testFunc1() { }
        virtual void testFunc2() {
            cout << "testFunc2()" << endl;
        }
};

int main(int argc, char* argv[]) {
    CMyData *pData = new CMyDataEx;
    pData->testFunc2();
    delete pData;

    return 0;
}