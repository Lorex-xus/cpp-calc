#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

[[noreturn]] void error(const char* message) {
    cerr << message << '\n';
    std::exit(EXIT_FAILURE);
}

int main() {
    cout << "Please enter expression (we can handle +, -, *, and /)\n";
    cout << "add an x to end expression (e.g., 1+2*3x): ";

    int lval = 0;
    int rval = 0;
    cin >> lval; // read left-most operand
    if (!cin)
        error("no first operand");
    for (char op; cin >> op;) { // read operator and right-hand operand repeatedly
        if (op == 'x') {
            cout << "Result: " << lval << '\n';
            return 0;
        }
        if (!(cin >> rval))
            error("no second operand");
        switch(op) {
            case '+':
                lval += rval; // add: lval = lval + rval
                break;
            case '-':
                lval -= rval; // subtract: lval = lval - rval
                break;
            case '*':
                lval *= rval; // multiply: lval = lval * rval
                break;
            case '/':
                if (rval == 0)
                    error("division by zero");
                lval /= rval; // divide: lval = lval / rval
                break;
            default:
                error("unsupported operator");
        }
    }
    error("bad expression");
}