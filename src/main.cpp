#include "main.h"
#include "ast.h"
#include "lexer.h"
#include "parser.h"

int main() {
    auto tok = gettok();
    printf("%d", tok);
    return 0;
}