#include <iostream>
#include <cstring>
using namespace std;

// 제작자 코드
class CIntArray {
    public:
        CIntArray(int nSize) {
            // 전달된 개수만큼 int 자료를 담을 수 있는 메모리를 확보한다.
            m_pnData = new int[nSize];
            memset(m_pnData, 0, sizeof(int) * nSize);
        }

        ~CIntArray() { delete m_pnData; }

        // 상수형 참조인 경우의 배열 연산자
        int operator[](int nIndex) const {
            cout << "operator[] const" << endl;
            return m_pnData[nIndex];
        }

        // 일반적인 배열 연산자
        int& operator[](int nIndex) {
            cout << "operator[]" << endl;
            return m_pnData[nIndex];
        }

    private:
        // 배열 메모리
        int *m_pnData;

        // 배열 요소의 개수
        int m_nSize;
};

// 사용자 코드
void testFunc(const CIntArray &arParam) {
    cout << "testFunc()" << endl;

    // 상수형 참조이므로 'operator[](int nIndex) const' 를 호출한다.
    // cout << arParam.operator[](3) << endl;
    cout << arParam[3] << endl;
}

int main(int argc, char* argv[]) {
    CIntArray arr(5);
    for(int i = 0; i < 5; ++i)
        arr[i] = i * 10;
    
    testFunc(arr);

    return 0;
}