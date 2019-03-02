#pragma once

class CMyList;

class CUserInterface {
    public:
        CUserInterface(CMyList &rList);
        ~CUserInterface(void);
        void _add(void);

    protected:
        CMyList &m_List;

    public:
        void _search(void);

        void _remove(void);

        int printUI(void);

        int _run(void);

        void printAll(void);
};