#include <iostream>

using namespace std;

class illegalParameterValue {
public:
    illegalParameterValue():
        message("illegal parameter value"){}
    illegalParameterValue(string theMessage) {
    // illegalParameterValue(const char* theMessage) {
        message = theMessage;
    }
    void outputMessage() { cout << message << endl; }
private:
    string message;
    // const char* message
};

template <class T>
T abc(T a, T b, T c){
    if (c <= 0) {
        throw illegalParameterValue("The first parameter is less than or equal to 0");
    }
    return (a + b) / c;
}

int main() {
    try {
        abc(1, 2, 0);
    } catch (illegalParameterValue e) {
        e.outputMessage();
    }
    return 0;
}