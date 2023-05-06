#pragma once
#include <memory>
#include <iostream>
#include <string>

#include "ast.h"
using namespace std;

void exchange(unique_ptr<BaseAST> &ast,FILE *out);
