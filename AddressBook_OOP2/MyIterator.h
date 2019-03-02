#pragma once
#include "MyNode.h"
#include <iostream>

class CMyIterator : public CMyNode {
    friend class CMyList;

    public:
        CMyIterator(void);
        ~CMyIterator(void);

        CMyNode* getCurrent(void) const { return m_pCurrent; }
        void moveNext(void) {
            if(m_pCurrent != NULL)
                m_pCurrent = m_pCurrent->pNext;
        }

    private:
        CMyNode *m_pHead;
        CMyNode *m_pCurrent;
};