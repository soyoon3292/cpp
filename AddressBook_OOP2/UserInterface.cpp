#include "UserInterface.h"
#include "MyList.h"
#include "UserData.h"
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
    m_List.addNewNode(new CUserData(szName, szPhone));
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

    pNode = m_List.findNode(szName);
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