/*
 * Copyright (C) Mohsen Zohrevandi, 2017
 *               Rida Bazzi 2019
 * Do not share this file with anyone
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "lexer.h"
#include "parser.h"
#include "CFG.h"

using namespace std;

// read grammar
void ReadGrammar()
{
    cout << "0\n";
}

// Task 1
void Task1()
{
    cout << "1\n";
}

// Task 2
void Task2()
{
    cout << "2\n";
}

// Task 3
void Task3()
{
    cout << "3\n";
}

// Task 4
void Task4()
{
    cout << "4\n";
}

// Task 5
void Task5()
{
    cout << "5\n";
}
    
int main (int argc, char* argv[])
{
    int task;

    if (argc < 2)
    {
        cout << "Error: missing argument\n";
        return 1;
    }

    /*
       Note that by convention argv[0] is the name of your executable,
       and the first argument to your program is stored in argv[1]
     */

    task = atoi(argv[1]);
    
    LexicalAnalyzer lexer = LexicalAnalyzer();
    Parser p = Parser(lexer);
    CFG c = p.parse_input();
    std::cout << "HELLO";
    std::cout << "Printing CFG" << std::endl;
    c.print();
    ReadGrammar();  // Reads the input grammar from standard input
                    // and represent it internally in data structures
                    // ad described in project 2 presentation file
    switch (task) {
        case 1: Task1();
            break;

        case 2: Task2();
            break;

        case 3: Task3();
            break;

        case 4: Task4();
            break;

        case 5: Task5();
            break;

        default:
            cout << "Error: unrecognized task number " << task << "\n";
            break;
    }
    return 0;
}

