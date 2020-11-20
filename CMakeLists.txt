cmake_minimum_required(VERSION 3.17)
project(methods_for_solving_the_eigenvalue_problem)

set(CMAKE_CXX_STANDARD 14)
 
add_executable(methods_for_solving_the_eigenvalue_problem
        main.cpp main.h
        parser/parser.cpp parser/parser.h
        print_slae.cpp
        norm.cpp
        QR_method/QR_method.cpp QR_method/create_matrix.cpp QR_method/QR_method.h
        is_degenerate.cpp
        multiplication.cpp
        subtraction.cpp
        reverse_traverse.cpp
        transposition.cpp
        find_eigenvalues.cpp
        to_Hessenberg_shape.cpp
        normalization.cpp)