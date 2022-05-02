#include "parser.h"
#include "lexer.h"
#include "ast.h"
#include <memory>

static int CurTok;

static int getNexToken() {
    return CurTok = gettok();
};

std::unique_ptr<ExprAST> LogError(const char *Str) {
    fprintf(stderr, "LogError: %s\n", Str);
    return nullptr;
}

std::unique_ptr<PrototypeAST> LogErrorP(const char *Str) {
    LogError(Str);
    return nullptr;
}