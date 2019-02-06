#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
class CMyData {
    public:
        CMyData(T param) : m_Data(param) { }

        T getData() const { return m_Data; }
        void setData(T param) { m_Data = param; }

    private:
        T m_Data;
};

template< >
class CMyData<char *> {
    public:
        CMyData(char *pszParam) {
            int nLen = strlen(pszParam);
            m_Data = new char[nLen + 1];
            strncpy(m_Data, pszParam, nLen + 1);
        }

        ~CMyData() { delete[] m_Data; }
        char* getData() const { return m_Data; }

    private:
        char *m_Data;
};

int main(int argc, char* argv[]) {
    CMyData<char*> a("Hello");
    cout << a.getData() << endl;

    return 0;
}