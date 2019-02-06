#include <cstring>
#include <iostream>
using namespace std;

class CNode {
    // friend 클래스 선언
    friend class CMyList;

    public:
        explicit CNode(const char *pszName) {
            strncpy(m_szName, pszName, sizeof(m_szName));
        }

    private:
        // 단일 연결 리스트로 관리할 데이터
        char m_szName[32];
        CNode *pNext = nullptr;
};

class CMyList {
    public:
        CMyList() : m_HeadNode("Dummy Head") { }
        ~CMyList() {
            // 리스트에 담긴 데이터들을 모두 출력하고 삭제
            CNode *pNode = m_HeadNode.pNext;
            CNode *pDelete = nullptr;

            while(pNode) {
                pDelete = pNode;
                pNode = pNode->pNext;

                cout << pDelete->m_szName << endl;
                delete pDelete;
            }

            m_HeadNode.pNext = nullptr;
        }

        void addNewNode(const char *pszName) {
            CNode *pNode = new CNode(pszName);

            // 리스트에 새로운 노드를 추가
            pNode->pNext = m_HeadNode.pNext;
            m_HeadNode.pNext = pNode;
        }

    private:
        CNode m_HeadNode;
};

// 사용자 코드
int main(int argc, char* argv[]) {
    // 메모리 추가/삭제 코드가 등장하지 않는다.
    CMyList list;
    list.addNewNode("길동");
    list.addNewNode("철수");
    list.addNewNode("영희");

    return 0;
}