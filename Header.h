//
//  Header.h
//  calc1
//
//  Created by Шахова Анастасия on 11.09.2020.
//  Copyright © 2020 Шахова Анастасия. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <stdio.h>
#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;
struct Elem {
    virtual double Evaluate() const=0;
};
class Value : public Elem {
    const int val;
    
public:
    Value(int digit): val(digit){}
    double Evaluate() const override {return val;}
};

class Operation :public Elem {
    const char op;
    shared_ptr<const Elem> left,right;
public:
    const int precedence;
    void SetLeft( shared_ptr<Elem> elem) { left=elem;}
    void SetRight(shared_ptr<Elem> elem) { right=elem;}
    int Prec(char value){
        if (value == '*' ||value == '/')
               return 2;
        else
               return 1;
        
    }
    Operation(char value):precedence(Prec(value)),op(value){}
    double Evaluate() const override{
        if(op=='*')
                return left->Evaluate()*right->Evaluate();
                
             else if (op=='+')
                return left->Evaluate()+right->Evaluate();
            
            else if (op=='-')
                return left->Evaluate()-right->Evaluate();
            
            else if (op=='/' && right->Evaluate()!=0)
               return left->Evaluate()/right->Evaluate();
            
            else if(op=='/' && right->Evaluate()==0)
                exit(1);
          else  return 0;
        
    }
};
template <typename Iterator>
shared_ptr<Elem>Parse(Iterator token,Iterator end){
    if(token==end)
        return make_shared<Value>('0');
    stack<int> valueParts;
    stack<shared_ptr<Elem>>values;
    stack<shared_ptr<Operation>>ops;
    
    auto Pop0ps = [&](int precedence) {
        while (!ops.empty() && ops.top()->precedence >= precedence) {
            auto value1 = values.top();
            values.pop();
            auto value2 = values.top();
            values.pop();
            auto op = ops.top();
            ops.pop();
            op->SetRight(value1);
            op->SetLeft(value2);
            values.push(op);
        }
    };
  int number = 0;
    while (token != end) {
        
        const auto& value = *token;
        bool flag= value >= '0' && value <= '9';

        if (flag)
            valueParts.push(value - '0');
        ++token;
        if(!flag || token == end){
            int presision = 1;
            while (!valueParts.empty()) {
                number += valueParts.top() * presision;
                presision *= 10;
                valueParts.pop();
            }
            values.push(make_shared<Value>(number));
            number = 0;

            if (value == '*' || value == '/') {
                Pop0ps(2);
                ops.push(make_shared<Operation>(value));
            }
            else if (value == '+' || value == '-') {
                Pop0ps(1);
                ops.push(make_shared<Operation>(value));
            }
           
        }

    }
        while(!ops.empty())
            Pop0ps(0);
        return values.top();
        
}

#endif /* Header_h */
