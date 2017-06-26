using namespace std;

class MainCpp {
    public:
        void printMsg();
        virtual int mapFileToM(){return 0;};
};

void MainCpp::printMsg() {
    cout << "Just a message" << endl;
}


class PosixMainCpp: public MainCpp {
    public:
      virtual int mapFileToM() {
        cout << "mapping file to memory" << endl;
        return 0;
      }
};

