#include <iostream>
#include <string>
#include "Vertex.h"
#include "Utilities.h"
#include "Calculator.h"

using namespace std;

int main() {
    string expr;
    std::getline(cin, expr);
    float result = Calculator::evaluate(expr);
    cout << "= " << result << std::endl;
    return 0;
}
