#include <iostream>
#include <math.h>
#include <string>

//-------------------------------------------------------------------------------------------------

#define INFINITY_OF_ROOTS -1
#define ACCURACY 1E-8

//-------------------------------------------------------------------------------------------------

#define TEST_IS_ZERO(x, answer) \
            if (IsZero(x) == answer) { \
                std::cout << "\033[0;32m" << "[PASSED]\033[0;37m IsZero(" << x << ") == " \
                    << answer  << " == " << answer << std::endl; \
            } else { \
                std::cout << "\033[0;31m" << "[ERROR] \033[0;37m IsZero(" << x << ") == " \
                    << IsZero(x) << " != " << answer << std::endl; \
            }

//-------------------------------------------------------------------------------------------------

#define TEST_SOLVE_LINEAR_EQUATION(b, c, answerRootsNumber, answerRoot) { \
            double root; \
            int rootsNumber = SolveLinearEquation(b, c, root); \
            switch (rootsNumber) { \
                case 0: \
                    if (answerRootsNumber != 0) { \
                        std::cout << "\033[0;31m" << "[ERROR] \033[0;37m SolveLinearEquation(" \
                            << b << ", " << c << ", root) == 0 != "<< answerRootsNumber \
                            << std::endl; \
                    } else { \
                        std::cout << "\033[0;32m" << "[PASSED]\033[0;37m SolveLinearEquation(" \
                            << b << ", " << c << ", root) == 0 == 0" << std::endl; \
                    } \
                    break; \
                case 1: \
                    if (answerRootsNumber != 1) { \
                        std::cout << "\033[0;31m" << "[ERROR] \033[0;37m SolveLinearEquation(" \
                            << b << ", " << c << ", root) == 1 != " << answerRootsNumber \
                            << std::endl; \
                    } else if (root != answerRoot) { \
                        std::cout << "\033[0;31m" << "[ERROR] \033[0;37m SolveLinearEquation(" \
                            << b << ", " << c << ", root) == 1 == 1" << std::endl \
                            << "         root == " << root << " != " << answerRoot << std::endl; \
                    } else { \
                        std::cout << "\033[0;32m" << "[PASSED]\033[0;37m SolveLinearEquation(" \
                        << b << ", " << c << ", root) == 1 == 1" << std::endl \
                        << "         root == " << root << " == " << answerRoot << std::endl; \
                    } \
                    break; \
                case INFINITY_OF_ROOTS: \
                    if (answerRootsNumber != INFINITY_OF_ROOTS) { \
                        std::cout << "\033[0;31m" << "[ERROR] \033[0;37m SolveLinearEquation(" \
                            << b << ", " << c << ", root) == infinity != " << answerRootsNumber \
                            << std::endl; \
                    } else { \
                        std::cout << "\033[0;32m" << "[PASSED]\033[0;37m SolveLinearEquation(" \
                            << b << ", " << c << ", root) == infinity == infinity" << std::endl; \
                    } \
                    break; \
                default: \
                    std::cout << "\033[0;31m" << "[ERROR] \033[0;37m SolveLinearEquation(" \
                        << b << ", " << c << ", root) == " << rootsNumber << " != " \
                        << answerRootsNumber << std::endl; \
            } \
        }

//-------------------------------------------------------------------------------------------------

#define TEST_SOLVE_QUADRATIC_EQUATION(a, b, c, answerRootsNumber, answerRoot1, answerRoot2) { \
            double root1, root2, buf; \
            int rootsNumber = SolveQuadraticEquation(a, b, c, root1, root2); \
            if ((rootsNumber == 2) && (root1 == answerRoot2)) { \
                buf = root2; \
                root2 = root1; \
                root1 = buf; \
            } \
            switch (rootsNumber) { \
                case 0: \
                    if (answerRootsNumber != 0) { \
                        std::cout << "\033[0;31m" << "[ERROR] \033[0;37m SolveQuadraticEquation(" \
                            << a << ", " << b << ", " << c << ", root1, root2) == 0 != " \
                            << answerRootsNumber << std::endl; \
                    } else { \
                        std::cout << "\033[0;32m" << "[PASSED]\033[0;37m SolveQuadraticEquation(" \
                            << a << ", " << b << ", " << c << ", root1, root2) == 0 == 0" \
                            << std::endl; \
                    } \
                    break; \
                case 1: \
                    if (answerRootsNumber != 1) { \
                        std::cout << "\033[0;31m" << "[ERROR] \033[0;37m SolveQuadraticEquation(" \
                            << a << ", " << b << ", " << c << ", root1, root2) == 1 != " \
                            << answerRootsNumber << std::endl; \
                    } else if (root1 != answerRoot1) { \
                        std::cout << "\033[0;31m" << "[ERROR] \033[0;37m SolveQuadraticEquation(" \
                            << a << ", " << b << ", " << c << ", root1, root2) == 1 == 1" \
                            << std::endl << "         root == " << root1 << " != " \
                            << answerRoot1 << std::endl; \
                    } else { \
                        std::cout << "\033[0;32m" << "[PASSED]\033[0;37m SolveQuadraticEquation(" \
                            << a << ", " << b << ", " << c << ", root1, root2) == 1 == 1" \
                            << std::endl << "         root == " << root1 << " == " << answerRoot1 \
                            << std::endl; \
                    } \
                    break; \
                case 2: \
                    if (answerRootsNumber != 2) { \
                        std::cout << "\033[0;31m" << "[ERROR] \033[0;37m SolveQuadraticEquation(" \
                            << a << ", " << b << ", " << c << ", root1, root2) == 2 != " \
                            << answerRootsNumber << std::endl; \
                    } else if ((root1 != answerRoot1) && (root2 != answerRoot2)) { \
                        std::cout << "\033[0;31m" << "[ERROR] \033[0;37m SolveQuadraticEquation(" \
                            << a << ", " << b << ", " << c << ", root1, root2) == 2 == 2" \
                            << std::endl << "         root1 == " << root1 << " != " << answerRoot1 \
                            << std::endl << "         root2 == " << root2 << " != " << answerRoot2 \
                            << std::endl; \
                    } else if (root1 != answerRoot1) { \
                        std::cout << "\033[0;31m" << "[ERROR] \033[0;37m SolveQuadraticEquation(" \
                            << a << ", " << b << ", " << c << ", root1, root2) == 2 == 2" \
                            << std::endl << "         root1 == " << root1 << " != " << answerRoot1 \
                            << std::endl << "         root2 == " << root2 << " == " << answerRoot2 \
                            << std::endl; \
                    } else if (root2 != answerRoot2) { \
                        std::cout << "\033[0;31m" << "[ERROR] \033[0;37m SolveQuadraticEquation(" \
                            << a << ", " << b << ", " << c << ", root1, root2) == 2 == 2" \
                            << std::endl << "         root1 == " << root1 << " == " << answerRoot1 \
                            << std::endl << "         root2 == " << root2 << " != " << answerRoot2 \
                            << std::endl; \
                    } else { \
                        std::cout << "\033[0;32m" << "[PASSED]\033[0;37m SolveQuadraticEquation(" \
                            << a << ", " << b << ", " << c << ", root1, root2) == 2 == 2" \
                            << std::endl << "         root1 == " << root1 << " == " << answerRoot1 \
                            << std::endl << "         root2 == " << root2 << " == " << answerRoot2 \
                            << std::endl; \
                    } \
                    break; \
                default: \
                    std::cout << "\033[0;31m" << "[ERROR] \033[0;37m SolveQuadraticEquation(" \
                        << b << ", " << c << ", root1, root2) == " << rootsNumber << " != " \
                        << answerRootsNumber << std::endl; \
            } \
        }

//-------------------------------------------------------------------------------------------------

int ReadData(double &a, double &b, double &c);
int IsZero(double x);
int SolveLinearEquation(double b, double c, double &root1);
int SolveQuadraticEquation(double a, double b, double c, double &root1, double &root2);
void PrintAnswer(int rootsNumber, double root1, double root2);

//-------------------------------------------------------------------------------------------------

int main() {
    double a = 0, b = 0, c = 0;
    
#ifdef DEBUG
    TEST_IS_ZERO(1, 0);
    TEST_IS_ZERO(1E-10, 1);
    
    TEST_SOLVE_LINEAR_EQUATION(6, -3, 1, 0.5);
    TEST_SOLVE_LINEAR_EQUATION(0, 7, 0, 0);
    TEST_SOLVE_LINEAR_EQUATION(0, 0, INFINITY_OF_ROOTS, 0);
    
    TEST_SOLVE_QUADRATIC_EQUATION(5, 3, 6, 0, 0, 0);
    TEST_SOLVE_QUADRATIC_EQUATION(1, -4, 4, 1, 2, 0);
    TEST_SOLVE_QUADRATIC_EQUATION(4, 2, -2, 2, -1, 0.5);
    
    TEST_SOLVE_QUADRATIC_EQUATION(6, 0, 0, 1, 0, 0);
    
    return 0;
#endif
    
    while (ReadData(a, b, c)) {
        std::cout << "Your input is not a double value. Try again." << std::endl;
    }
    
    double root1 = 0, root2 = 0;
    int rootsNumber = 0;
    
    if (IsZero(a)) {
        rootsNumber = SolveLinearEquation(b, c, root1);
    } else {
        rootsNumber = SolveQuadraticEquation(a, b, c, root1, root2);
    }
    
    PrintAnswer(rootsNumber, root1, root2);
    
    return 0;
}

//-------------------------------------------------------------------------------------------------

//! Finds out if number is less modulo then accuracy
//!
//! @param [in] x number to check
//!
//! @return 1 in case the number is less modulo then accuracy, 1 otherwise

int IsZero(double x) {
    if (fabs (x) <= ACCURACY) {
        return 1;
    }
    return 0;
}

//-------------------------------------------------------------------------------------------------

//! Reads a, b, and c -coefficients for quadratic equation ax^2 + bx + c = 0
//!
//! @param [out] a a‐coefficient (passed by link)
//! @param [out] b b‐coefficient (passed by link)
//! @param [out] c c‐coefficient (passed by link)
//!
//! @return 0 in case all coefficients are acceptable, 1 otherwise

int ReadData(double &a, double &b, double &c) {
    std::string input_buf;
    std::string::size_type pos = 0;
    try {
        std::cout << "Please, enter coefficients for solving equation ax^2 + bx + c = 0."
                  << std::endl;
        
        std::cout << "a = ";
        getline(std::cin, input_buf);
        a = std::stod(input_buf, &pos);
        if (pos < input_buf.size()) {
            throw std::invalid_argument("Wrong a");
        }
        
        std::cout << "b = ";
        getline(std::cin, input_buf);
        b = std::stod(input_buf, &pos);
        if (pos < input_buf.size()) {
            throw std::invalid_argument("Wrong b");
        }
        
        std::cout << "c = ";
        getline(std::cin, input_buf);
        c = std::stod(input_buf, &pos);
        if (pos < input_buf.size()) {
            throw std::invalid_argument("Wrong c");
        }
        
        return 0;
    } catch (...) {
        return 1;
    }
}

//-------------------------------------------------------------------------------------------------

//! Solves a linear equation bx + c = 0
//!
//! @param [in] b b‐coefficient
//! @param [in] c c‐coefficient
//! @param [out] root1 Variable to save the root (passed by link)
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots, returns INFINITY_OF_ROOTS.

int SolveLinearEquation(double b, double c, double &root1) {
    double buf = 0;
    if (b != 0) {
        buf = - c / b;
        if (IsZero(buf)) {
            root1 = 0;
        } else {
            root1 = buf;
        }
        return 1;
    }
    
    if (c != 0) {
        return 0;
    }
    
    return INFINITY_OF_ROOTS;
}


//-------------------------------------------------------------------------------------------------

//! Solves a square equation ax2 + bx + c = 0
//!
//! @param [in] a a‐coefficient
//! @param [in] b b‐coefficient
//! @param [in] c c‐coefficient
//! @param [out] root1 Variable to save the 1st root (passed by link)
//! @param [out] root2 Variable to save the 2nd root (passed by link)
//!
//! @return Number of roots

int SolveQuadraticEquation(double a, double b, double c, double &root1, double &root2) {
    double sqrt_discriminant = sqrt(b * b - 4 * a * c);
    double buf = 0;
    
    if (sqrt_discriminant == 0) {
        buf = - b / (2 * a);
        if (IsZero(buf)) {
            root1 = 0;
        } else {
            root1 = buf;
        }
        return 1;
    }
    
    if (sqrt_discriminant > 0) {
        buf = (- b + sqrt_discriminant) / (2 * a);
        if (IsZero(buf)) {
            root1 = 0;
        } else {
            root1 = buf;
        }
        buf = (- b - sqrt_discriminant) / (2 * a);
        if (IsZero(buf)) {
            root2 = 0;
        } else {
            root2 = buf;
        }
        return 2;
    }
    
    return 0;
}

//-------------------------------------------------------------------------------------------------

//! Prints number of roots and root/roots for equation ax^2 + bx + c = 0
//!
//! @param [in] rootsNumber Number of roots
//! @param [in] root1 Tthe 1st root
//! @param [in] root2 The 2nd root

void PrintAnswer(int rootsNumber, double root1, double root2) {
    std::cout << std::endl;
    switch (rootsNumber) {
        case 0:
            std::cout << "The equation has no real roots" << std::endl;
            break;
        case 1:
            std::cout << "1 root, root = " << root1 << std::endl;
            break;
        case 2:
            std::cout << "2 roots, root1 = " << root1 << ", root2 = " << root2 << std::endl;
            break;
        case INFINITY_OF_ROOTS:
            std::cout << "Any number can be a root of this equation." << std::endl;
            break;
    }
}
