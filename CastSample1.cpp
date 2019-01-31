#include <iostream>
using namespace std;

class CMyData {
    public:
        CMyData() { }
        virtual ~CMyData() { }
        void setData(int nParam) { m_nData = nParam; }
        int getData() { return m_nData; }

    private:
        int m_nData = 0;
};

class CMyDataEx : public CMyData {
    public:
        void setData(int nParam) {
            if(nParam > 10)
                nParam = 10;

            CMyData::setData(nParam);
        }

        void printData() {
            cout << "printData(): " << getData() << endl;
        }
};

int main(int argc, char* argv[]) {
    // 파생 형식의 객체를 기본 형식으로 포인팅합니다.
    CMyData *pData = new CMyDataEx;
    CMyDataEx *pNewData = NULL;

    // CMyData::setData() 함수를 호출합니다.
    // 따라서 10이 넘는지 검사하지 않습니다.
    pData->setData(15);

    // 기본 형식에 대한 포인터이나 가리키는 대상은 파생 형식입니다.
    // 이 사실이 명확하므로 파생 형식에 대한 포인터로 형변환을 시도합니다.
    pNewData = static_cast<CMyDataEx*>(pData);
    pNewData->printData();
    delete pData;

    return 0;
}