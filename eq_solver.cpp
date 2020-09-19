#ifdef DEBUG
#include "test_defines.h"
#endif
#include "functions.h"

//-------------------------------------------------------------------------------------------------

int main() {
    double a = NAN, b = NAN, c = NAN;
    
#ifdef DEBUG
    TEST_IS_ZERO(1.0, 0);
    TEST_IS_ZERO(1E-10, 1);
    
    TEST_DISCRIMINANT_COUNTER(10.0, 20.0, 5.0, 200.0);
    TEST_DISCRIMINANT_COUNTER(10.0, 20.0, 30.0, -800.0);
    
    TEST_SOLVE_LINEAR_EQUATION(6.0, -3.0, 1, 0.5);
    TEST_SOLVE_LINEAR_EQUATION(0.0, 7.0, 0, 0.0);
    TEST_SOLVE_LINEAR_EQUATION(0.0, 0.0, INFINITY_OF_ROOTS, 0.0);
    
    TEST_SOLVE_QUADRATIC_EQUATION(5.0, 3.0, 6.0, 0, 0.0, 0.0);
    TEST_SOLVE_QUADRATIC_EQUATION(1.0, -4.0, 4.0, 1, 2.0, 0.0);
    TEST_SOLVE_QUADRATIC_EQUATION(4.0, 2.0, -2.0, 2, -1.0, 0.5);
    
    TEST_SOLVE_QUADRATIC_EQUATION(6.0, 0.0, 0.0, 1, 0.0, 0.0);
    
    return 0;
#endif
    
    while (ReadData(a, b, c)) {
        std::cout << "Your input is not a double value. Try again." << std::endl;
    }
    
    double root1 = NAN, root2 = NAN;
    int rootsNumber = SolveQuadraticEquation(a, b, c, root1, root2);
    
    if (rootsNumber == FINITE_ERROR) {
        return 0;
    }
    
    PrintAnswer(rootsNumber, root1, root2);
    
    return 0;
}
