//
//  test.cpp
//  calc1
//
//  Created by Шахова Анастасия on 11.09.2020.
//  Copyright © 2020 Шахова Анастасия. All rights reserved.
//

#define CATCH_CONFIG_MAIN

#include "include/catch.hpp"
#include <stdio.h>
#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <string>
#include <stdlib.h>
#include "Header.h"

TEST_CASE("Operrrr+","[O]"){
    Operation op('+');
    op.SetLeft(make_shared<Value>(4));
    op.SetRight(make_shared<Value>(3));
    REQUIRE(op.Evaluate() == 7);
}

TEST_CASE("Operrrr-","[O]"){
    Operation op('-');
    op.SetLeft(make_shared<Value>(15));
    op.SetRight(make_shared<Value>(4));
    REQUIRE(op.Evaluate() == 11);
    }
TEST_CASE("Operrrr*","[O]"){
Operation op('*');
op.SetLeft(make_shared<Value>(22));
op.SetRight(make_shared<Value>(4));
REQUIRE(op.Evaluate() == 88);
}
TEST_CASE("Operrrr/","[O]"){
Operation op('/');
op.SetLeft(make_shared<Value>(22));
op.SetRight(make_shared<Value>(4));
    REQUIRE(op.Evaluate() == 5.5);
}



