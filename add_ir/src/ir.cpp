#include "ast.h"
#include "ir.h"
using namespace std;


void exchange(unique_ptr<BaseAST> &ast,FILE *out){
    string s;
    
    CompUnitAST *comp_unit = static_cast<CompUnitAST *>(ast.get());
    //进入function
    s+="fun ";
    s+="@";
    FuncDefAST *func_def = static_cast<FuncDefAST *>(comp_unit->func_def.get());
    //第一个block
    s+=func_def->ident+"(): ";
    FuncTypeAST *func_type = static_cast<FuncTypeAST *>(func_def->func_type.get());
    if(func_type->type=="int")
    s+="i32 ";
    s+="{\n";
    BlockAST *block=static_cast<BlockAST *>(func_def->block.get());
    //进入block
    s+="%entry:\n";
    StmtAST *stmt=static_cast<StmtAST *>(block->stmt.get());
    //第一条语句
    s+="ret "+to_string(stmt->number)+"\n";


    //退出block
    s+="}";

    fputs(s.c_str(), out);
}