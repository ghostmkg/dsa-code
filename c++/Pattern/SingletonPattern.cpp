#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    Singleton() {}  // private constructor

public:
    static Singleton* getInstance() {
        if(!instance)
            instance = new Singleton();
        return instance;
    }
    void showMessage() { cout << "Hello from Singleton!" << endl; }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s = Singleton::getInstance();
    s->showMessage();
    return 0;
}
