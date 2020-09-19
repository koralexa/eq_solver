#ifndef __TEST_DEFINES_H__
#define __TEST_DEFINES_H__

#include <stdio.h>

//-------------------------------------------------------------------------------------------------

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define WHITE "\033[0;37m"


//-------------------------------------------------------------------------------------------------

#define PRINT_PASSED \
            printf("%s%s%s", GREEN, "[PASSED] ", WHITE);

#define PRINT_ERROR \
            printf("%s%s%s", RED, "[ERROR]  ", WHITE);

//-------------------------------------------------------------------------------------------------

#define IS_ZERO_OK(x, answer, right_answer) \
            printf("%s%s%s %s%G%s%d %s %d\n", \
                    GREEN, \
                    "[PASSED]", \
                    WHITE, \
                    "IsZero(", \
                    x, \
                    ") == ", \
                    answer, \
                    "==", \
                    right_answer);



#define IS_ZERO_ERR(x, answer, right_answer) \
            printf("%s%s%s %s%G%s%d %s %d\n", \
                    RED, \
                    "[ERROR] ", \
                    WHITE, \
                    "IsZero(", \
                    x, \
                    ") == ", \
                    answer, \
                    "!=", \
                    right_answer);

//-------------------------------------------------------------------------------------------------

#define DISCRIMINANT_COUNTER_OK(a, b, c, answer, right_answer) \
            printf("%s%s%s %s%G%s %G%s %G%s %G %s %G\n", \
                    GREEN, \
                    "[PASSED]", \
                    WHITE, \
                    "DiscriminantCounter(", \
                    a, \
                    ",", \
                    b, \
                    ",", \
                    c, \
                    ") == ", \
                    answer, \
                    "==", \
                    right_answer);



#define DISCRIMINANT_COUNTER_ERR(a, b, c, answer, right_answer) \
            printf("%s%s%s %s%G%s %G%s %G%s %G %s %G\n", \
                    RED, \
                    "[ERROR] ", \
                    WHITE, \
                    "DiscriminantCounter(", \
                    a, \
                    ",", \
                    b, \
                    ",", \
                    c, \
                    ") == ", \
                    answer, \
                    "!=", \
                    right_answer);

//-------------------------------------------------------------------------------------------------

#define PRINT_LINEAR_NUMBER_OK(b, c, rootsNumber, answerRootsNumber) \
            printf("%s%G%s %G%s %d %s %d\n", \
                    "SolveLinearEquation(", \
                    b, \
                    ",", \
                    c, \
                    ", root) ==", \
                    rootsNumber, \
                    "==", \
                    answerRootsNumber);

#define PRINT_LINEAR_NUMBER_ERR(b, c, rootsNumber, answerRootsNumber) \
            printf("%s%G%s %G%s %d %s %d\n", \
                    "SolveLinearEquation(", \
                    b, \
                    ",", \
                    c, \
                    ", root) ==", \
                    rootsNumber, \
                    "!=", \
                    answerRootsNumber);

//-------------------------------------------------------------------------------------------------

#define PRINT_QUADRATIC_NUMBER_OK(a, b, c, rootsNumber, answerRootsNumber) \
            printf("%s%G%s %G%s %G%s %d %s %d\n", \
                    "SolveQuadraticEquation(", \
                    a, \
                    ",", \
                    b, \
                    ",", \
                    c, \
                    ", root1, root2) ==", \
                    rootsNumber, \
                    "==", \
                    answerRootsNumber);



#define PRINT_QUADRATIC_NUMBER_ERR(a, b, c, rootsNumber, answerRootsNumber) \
            printf("%s%G%s %G%s %G%s %d %s %d\n", \
                    "SolveQuadraticEquation(", \
                    a, \
                    ",", \
                    b, \
                    ",", \
                    c, \
                    ", root1, root2) ==", \
                    rootsNumber, \
                    "!=", \
                    answerRootsNumber);

//-------------------------------------------------------------------------------------------------

#define PRINT_ROOT_OK(root, answerRoot) \
            printf("%s %G %s %G\n", \
                    "         root == ", \
                    root, \
                    "==", \
                    answerRoot);

#define PRINT_ROOT_ERR(root, answerRoot) \
            printf("%s %G %s %G\n", \
                    "         root == ", \
                    root, \
                    "!=", \
                    answerRoot);

//-------------------------------------------------------------------------------------------------

#define TEST_IS_ZERO(x, answer) { \
            bool is_zero = IsZero(x); \
            if (is_zero == answer) { \
                IS_ZERO_OK(x, is_zero, answer); \
            } else { \
                IS_ZERO_ERR(x, is_zero, answer); \
            } \
        }

//-------------------------------------------------------------------------------------------------

#define TEST_DISCRIMINANT_COUNTER(a, b, c, answer) { \
            double discr = DiscriminantCounter(a, b, c); \
            if (IsZero(discr - answer)) { \
                DISCRIMINANT_COUNTER_OK(a, b, c, discr, answer); \
            } else { \
                DISCRIMINANT_COUNTER_ERR(a, b, c, discr, answer); \
            } \
        }

//-------------------------------------------------------------------------------------------------

#define TEST_SOLVE_LINEAR_EQUATION(b, c, answerRootsNumber, answerRoot) { \
            double root = NAN; \
            int rootsNumber = SolveLinearEquation(b, c, root); \
            switch (rootsNumber) { \
                case 0: \
                    if (answerRootsNumber != 0) { \
                        PRINT_ERROR; \
                        PRINT_LINEAR_NUMBER_ERR(b, c, rootsNumber, answerRootsNumber); \
                    } else { \
                        PRINT_PASSED; \
                        PRINT_LINEAR_NUMBER_OK(b, c, rootsNumber, answerRootsNumber); \
                    } \
                    break; \
                case 1: \
                    if (answerRootsNumber != 1) { \
                        PRINT_ERROR; \
                        PRINT_LINEAR_NUMBER_ERR(b, c, rootsNumber, answerRootsNumber); \
                    } else if (!IsZero(root - answerRoot)) { \
                        PRINT_ERROR; \
                        PRINT_LINEAR_NUMBER_OK(b, c, rootsNumber, answerRootsNumber); \
                        PRINT_ROOT_ERR(root, answerRoot); \
                    } else { \
                        PRINT_PASSED; \
                        PRINT_LINEAR_NUMBER_OK(b, c, rootsNumber, answerRootsNumber); \
                        PRINT_ROOT_OK(root, answerRoot); \
                    } \
                    break; \
                case INFINITY_OF_ROOTS: \
                    if (answerRootsNumber != INFINITY_OF_ROOTS) { \
                        PRINT_ERROR; \
                        PRINT_LINEAR_NUMBER_ERR(b, c, rootsNumber, answerRootsNumber); \
                    } else { \
                        PRINT_PASSED; \
                        PRINT_LINEAR_NUMBER_OK(b, c, rootsNumber, answerRootsNumber); \
                    } \
                    break; \
                default: \
                    PRINT_ERROR; \
                    PRINT_LINEAR_NUMBER_ERR(b, c, rootsNumber, answerRootsNumber); \
            } \
        }

//-------------------------------------------------------------------------------------------------

#define TEST_SOLVE_QUADRATIC_EQUATION(a, b, c, answerRootsNumber, answerRoot1, answerRoot2) { \
            double root1 = NAN, root2 = NAN, buf = NAN; \
            int rootsNumber = SolveQuadraticEquation(a, b, c, root1, root2); \
            if ((rootsNumber == 2) && (root1 == answerRoot2)) { \
                buf = root2; \
                root2 = root1; \
                root1 = buf; \
            } \
            switch (rootsNumber) { \
                case 0: \
                    if (answerRootsNumber != 0) { \
                        PRINT_ERROR; \
                        PRINT_QUADRATIC_NUMBER_ERR(a, b, c, rootsNumber, answerRootsNumber); \
                    } else { \
                        PRINT_PASSED; \
                        PRINT_QUADRATIC_NUMBER_OK(a, b, c, rootsNumber, answerRootsNumber); \
                    } \
                    break; \
                case 1: \
                    if (answerRootsNumber != 1) { \
                        PRINT_ERROR; \
                        PRINT_QUADRATIC_NUMBER_ERR(a, b, c, rootsNumber, answerRootsNumber); \
                    } else if (!IsZero(root1 - answerRoot1)) { \
                        PRINT_ERROR; \
                        PRINT_QUADRATIC_NUMBER_OK(a, b, c, rootsNumber, answerRootsNumber); \
                        PRINT_ROOT_ERR(root1, answerRoot1); \
                    } else { \
                        PRINT_PASSED; \
                        PRINT_QUADRATIC_NUMBER_OK(a, b, c, rootsNumber, answerRootsNumber); \
                        PRINT_ROOT_OK(root1, answerRoot1); \
                    } \
                    break; \
                case 2: \
                    if (answerRootsNumber != 2) { \
                        PRINT_ERROR; \
                        PRINT_QUADRATIC_NUMBER_ERR(a, b, c, rootsNumber, answerRootsNumber); \
                    } else if ((!IsZero(root1 - answerRoot1)) && (!IsZero(root2 - answerRoot2))) { \
                        PRINT_ERROR; \
                        PRINT_QUADRATIC_NUMBER_OK(a, b, c, rootsNumber, answerRootsNumber); \
                        PRINT_ROOT_ERR(root1, answerRoot1); \
                        PRINT_ROOT_ERR(root2, answerRoot2); \
                    } else if (!IsZero(root1 - answerRoot1)) { \
                        PRINT_ERROR; \
                        PRINT_QUADRATIC_NUMBER_OK(a, b, c, rootsNumber, answerRootsNumber); \
                        PRINT_ROOT_ERR(root1, answerRoot1); \
                        PRINT_ROOT_OK(root2, answerRoot2); \
                    } else if (!IsZero(root2 - answerRoot2)) { \
                        PRINT_ERROR; \
                        PRINT_QUADRATIC_NUMBER_OK(a, b, c, rootsNumber, answerRootsNumber); \
                        PRINT_ROOT_OK(root1, answerRoot1); \
                        PRINT_ROOT_ERR(root2, answerRoot2); \
                    } else { \
                        PRINT_PASSED; \
                        PRINT_QUADRATIC_NUMBER_OK(a, b, c, rootsNumber, answerRootsNumber); \
                        PRINT_ROOT_OK(root1, answerRoot1); \
                        PRINT_ROOT_OK(root2, answerRoot2); \
                    } \
                    break; \
                default: \
                    PRINT_ERROR; \
                    PRINT_QUADRATIC_NUMBER_ERR(a, b, c, rootsNumber, answerRootsNumber); \
            } \
        }



#endif
