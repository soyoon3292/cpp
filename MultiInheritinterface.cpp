class CMyUSB {
    public:
        virtual int getUsbVersion() = 0;
        virtual int getTransferRate() = 0;
};

class CMySerial {
    public:
        virtual int getSignal() = 0;
        virtual int getRate() = 0;
};

class CMyDevice : public CMyUSB, public CMySerial {
    public:
        // USB 인터페이스
        virtual int getUsbVersion() { return 0; }
        virtual int getTransferRate() { return 0; }

        // 시리얼 인터페이스
        virtual int getSignal() { return 0; }
        virtual int getRate() { return 0; }
};

int main(int argc, char* argv[]) {
    CMyDevice dev;

    return 0;
}