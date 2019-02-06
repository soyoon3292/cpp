#include <iostream>
using namespace std;

template<typename T>
class CMyData {
    public:

    protected:
        T m_Data;
};

template<typename T>
class CMyDataEx : public CMyData<T> {
    public:
        T getData() const { return CMyData<T>::m_Data; }
        void setData(T param) { this->m_Data = param; }
};

int main(int argc, char* argv[]) {
    CMyDataEx<int> a;
    a.setData(5);
    cout << a.getData() << endl;

    return 0;
}