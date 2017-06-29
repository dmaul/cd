#include <iostream>

class MainCpp {
  public:
    void printMsg();
    virtual int mapFileToM(){return 0;};
};

class PosixMainCpp: public MainCpp {
  public:
    int mapFileToM();
};
