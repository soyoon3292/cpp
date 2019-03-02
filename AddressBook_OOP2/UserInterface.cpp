#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"
#include "MyIterator.h"
#include <iostream>
using namespace std;

CUserInterface::CUserInterface(CMyList &rList) : m_List(rList) {

}

CUserInterface::~CUserInterface() {

}

void CUserInterface::_add(void) {
    char szName[32] = {0};
    char szPhone[32] = {0};

    cout << "Input name : " << endl;
    cin >> szName;
    cout << "Input phone number : " << endl;
    cin >> szPhone;
    int nResult = m_List.addNewNode(new CUserData(szName, szPhone));

    if(nResult == 0) {
        cout << "ERROR: 이미 존재하는 데이터입니다." << endl;

        cin.get();
        cin.get();
    }

    else if(nResult == -1) {
        cout << "ERROR: 욕설을 이름으로 쓸 수 없습니다." << endl;

        cin.get();
        cin.get();
    }
}

int CUserInterface::printUI(void) {
    int nInput = 0;

    system("clear");
    cout << "[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit:" << endl;

    // 사용자가 선택한 메뉴의 값을 반환한다.
    cin >> nInput;

    return nInput;
}

void CUserInterface::_search(void) {
    char szName[32] = {0};
    CMyNode *pNode = NULL;

    cout << "Input name : " << endl;
    cin >> szName;

    pNode = static_cast<CUserData*>(m_List.findNode(szName));
    if(pNode != NULL) {
        pNode->printNode();
    }

    else {
        cout << "ERROR: 데이터를 찾을 수 없습니다." << endl;
    }

    cin.get();
    cin.get();
}

void CUserInterface::_remove(void) {
    char szName[32] = {0};

    cout << "Input name : " << endl;
    cin >> szName;

    m_List.removeNode(szName);
}

int CUserInterface::_run(void) {
    int nMenu = 0;

    // 메인 이벤트 반복문
    while((nMenu = printUI()) != 0) {
        switch(nMenu) {
            case 1: // Add
                _add();
                break;
            
            case 2: // Search
                _search();
                break;

            case 3: // Print all
                m_List.printAll();
                break;

            case 4: // Remove;
                _remove();
                break;
        }
    }

    return nMenu;
}

void CUserInterface::printAll(void) {
    // 리스트에 대한 열거자를 생성한다.
    CMyIterator it = m_List.makeIterator();
    CUserData *pNode = NULL;

    // 열거자를 이용해 리스트 전체에 접근한다.
    while((pNode = static_cast<CUserData*> (it.getCurrent()) != NULL) {
        pNode->printNode();
        it.moveNext();
    }

    cin.get();
    cin.get();
}