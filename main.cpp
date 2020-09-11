//
//  main.cpp
//  calc1
//
//  Created by Шахова Анастасия on 11.09.2020.
//  Copyright © 2020 Шахова Анастасия. All rights reserved.
//
#define CATCH_CONFIG_MAIN

#include <stdio.h>
#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <string>
#include <stdlib.h>
#include "Header.h"
using namespace std;

int main(int argc, const char * argv[]) {
    string tokens;
    cout << "Enter expression:";
    getline(cin, tokens);
    
    auto elem=Parse(tokens.begin(), tokens.end());
    cout << "Expression value:" << elem->Evaluate() << endl;
        return 0;
}
