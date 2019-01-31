#include <iostream>
using namespace std;

class CMyObject {
    public:
        CMyObject() { cout << "CMyObject()" << endl; }
        virtual ~CMyObject() { }
};

class CMyImage : virtual public CMyObject {
    public:
        CMyImage() { cout << "CMyImage(int, int)" << endl; }
};

class CMyShape : virtual public CMyObject {
    public:
        CMyShape() { cout << "CMyShape(int)" << endl; }
};

class CMyPicture : public CMyImage, public CMyShape {
    public:
        CMyPicture() { cout << "CMyPicture()" << endl; }
};

int main(int argc, char* argv[]) {
    CMyPicture a;
}