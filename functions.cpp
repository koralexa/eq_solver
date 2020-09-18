#include "functions.h"

//-------------------------------------------------------------------------------------------------

//! Finds out if number is less modulo then accuracy
//!
//! @param [in] x number to check
//!
//! @return 1 in case the number is less modulo then accuracy, 0 otherwise
//!
//! @note In case of error returns FINITE_ERROR.

int IsZero(double x) {
    if (!std::isfinite(x)) {
        std::cout << "ERROR: parametr of IsZero became not finite." << std::endl;
        return FINITE_ERROR;
    }
    if (fabs(x) <= ACCURACY) {
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
//! @note In case of infinite number of roots, returns INFINITY_OF_ROOTS, in case of error returns FINITE_ERROR

int SolveLinearEquation(double b, double c, double &root1) {
    if (!std::isfinite(b)) {
        std::cout << "ERROR: b parametr of SolveLinearEquation became not finite." << std::endl;
        return FINITE_ERROR;
    }
    if (!std::isfinite(c)) {
        std::cout << "ERROR: c parametr of SolveLinearEquation became not finite." << std::endl;
        return FINITE_ERROR;
    }
    
    double buf = NAN;
    int is_zero = IsZero(b);
    if (is_zero == FINITE_ERROR) {
        return FINITE_ERROR;
    }
    if (!is_zero) {
        buf = - c / b;
        if (!std::isfinite(buf)) {
            std::cout << "ERROR: buf variable in SolveLinearEquation became not finite." << std::endl;
            return FINITE_ERROR;
        }
        is_zero = IsZero(buf);
        if (is_zero == FINITE_ERROR) {
            return FINITE_ERROR;
        }
        if (is_zero) {
            root1 = 0;
        } else {
            root1 = buf;
        }
        return 1;
    }
    
    is_zero = IsZero(c);
    if (is_zero == FINITE_ERROR) {
        return FINITE_ERROR;
    }
    if (!is_zero) {
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
//!
//! @note In case of infinite number of roots, returns INFINITY_OF_ROOTS, in case of error returns FINITE_ERROR

int SolveQuadraticEquation(double a, double b, double c, double &root1, double &root2) {
    if (!std::isfinite(a)) {
        std::cout << "ERROR: a parametr of SolveQuadraticEquation became not finite." << std::endl;
        return FINITE_ERROR;
    }
    if (!std::isfinite(b)) {
        std::cout << "ERROR: b parametr of SolveQuadraticEquation became not finite." << std::endl;
        return FINITE_ERROR;
    }
    if (!std::isfinite(c)) {
        std::cout << "ERROR: c parametr of SolveQuadraticEquation became not finite." << std::endl;
        return FINITE_ERROR;
    }
    
    int is_zero = IsZero(a);
    if (is_zero == FINITE_ERROR) {
        return FINITE_ERROR;
    }
    if (is_zero) {
        return SolveLinearEquation(b, c, root1);
    }
    
    double discriminant = b * b - 4 * a * c;
    if (!std::isfinite(discriminant)) {
        std::cout << "ERROR: discriminant variable in SolveQuadraticEquation became not finite." << std::endl;
        return FINITE_ERROR;
    }
    double buf = NAN;
    
    is_zero = IsZero(discriminant);
    if (is_zero == FINITE_ERROR) {
        return FINITE_ERROR;
    }
    if (is_zero) {
        buf = - b / (2 * a);
        if (!std::isfinite(buf)) {
            std::cout << "ERROR: buf variable in SolveQuadraticEquation became not finite." << std::endl;
            return FINITE_ERROR;
        }
        is_zero = IsZero(buf);
        if (is_zero == FINITE_ERROR) {
            return FINITE_ERROR;
        }
        if (is_zero) {
            root1 = 0;
        } else {
            root1 = buf;
        }
        return 1;
    }
    
    if (discriminant > 0) {
        double sqrt_discriminant = sqrt(discriminant);
        if (!std::isfinite(sqrt_discriminant)) {
            std::cout << "ERROR: sqrt_discriminant variable in SolveQuadraticEquation became not finite." << std::endl;
            return FINITE_ERROR;
        }
        buf = (- b + sqrt_discriminant) / (2 * a);
        if (!std::isfinite(buf)) {
            std::cout << "ERROR: buf variable in SolveQuadraticEquation became not finite." << std::endl;
            return FINITE_ERROR;
        }
        is_zero = IsZero(buf);
        if (is_zero == FINITE_ERROR) {
            return FINITE_ERROR;
        }
        if (is_zero) {
            root1 = 0;
        } else {
            root1 = buf;
        }
        buf = (- b - sqrt_discriminant) / (2 * a);
        if (!std::isfinite(buf)) {
            std::cout << "ERROR: buf variable in SolveQuadraticEquation became not finite." << std::endl;
            return FINITE_ERROR;
        }
        is_zero = IsZero(buf);
        if (is_zero == FINITE_ERROR) {
            return FINITE_ERROR;
        }
        if (is_zero) {
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
    if (!std::isfinite(rootsNumber)) {
        std::cout << "ERROR: rootsNumber parametr in PrintAnswer became not finite." << std::endl;
        return;
    }
    
    std::cout << std::endl;
    switch (rootsNumber) {
        case 0:
            std::cout << "The equation has no real roots" << std::endl;
            break;
        case 1:
            if (!std::isfinite(root1)) {
                std::cout << "ERROR: root1 parametr in PrintAnswer became not finite." << std::endl;
                return;
            }
            std::cout << "1 root, root = " << root1 << std::endl;
            break;
        case 2:
            if (!std::isfinite(root1)) {
                std::cout << "ERROR: root1 parametr in PrintAnswer became not finite." << std::endl;
                return;
            }
            if (!std::isfinite(root2)) {
                std::cout << "ERROR: root2 parametr in PrintAnswer became not finite." << std::endl;
                return;
            }
            std::cout << "2 roots, root1 = " << root1 << ", root2 = " << root2 << std::endl;
            break;
        case INFINITY_OF_ROOTS:
            std::cout << "Any number can be a root of this equation." << std::endl;
            break;
    }
}
