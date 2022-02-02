#include <string>
#include "lexer.h"

enum Token {
    tok_eof = -1,

    // commands
    tok_def = 2,
    tok_extern = -3,

    // primary
    tok_identifier = -4,
    tok_number = -5,
};

static std::string IdentifierStr; // filled in if tok_identifier
static double NumVal; // filled in if tok_number

// returns the next token from std input
static int gettok() {
    static int LastChar = ' ';

    // skip whitespaces

    while (std::isspace(LastChar)) {
        LastChar = getchar();
    }
}
