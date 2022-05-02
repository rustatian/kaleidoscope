#include <string>
#include "lexer.h"

enum Token
{
    tok_eof = -1,

    // commands
    tok_def = 2,
    tok_extern = -3,

    // primary
    tok_identifier = -4,
    tok_number = -5,
};

static std::string IdentifierStr; // filled in if tok_identifier
static double NumVal;             // filled in if tok_number

// returns the next token from std input
static int gettok()
{
    static int LastChar = ' ';

    while (std::isspace(LastChar))
    {
        LastChar = getchar();
    }

    if (std::isalpha(LastChar))
    {
        IdentifierStr = std::to_string(LastChar);

        while (std::isalnum((LastChar = getchar())))
            IdentifierStr += std::to_string(LastChar);

        if (IdentifierStr == "def")
            return tok_def;

        if (IdentifierStr == "extern")
            return tok_extern;

        return tok_identifier;
    }

    /*
     * Note that this isn’t doing sufficient error checking:
     * it will incorrectly read “1.23.45.67” and handle it as if you typed
     * in “1.23”. Feel free to extend it! Next we handle comments:
     */
    if (std::isdigit(LastChar) || LastChar == '.')
    {
        std::string NumStr;
        do
        {
            NumStr += LastChar;
            LastChar = getchar();
        } while (std::isdigit(LastChar) || LastChar == '.');

        NumVal = std::strtod(NumStr.c_str(), nullptr);

        return tok_number;
    }

    if (LastChar == '#')
    {
        do
        {
            LastChar = getchar();
        } while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

        if (LastChar != EOF)
            return gettok();
    }

    // check for end of file, don't eat the EOF.
    if (LastChar == EOF)
    {
        return tok_eof;
    }

    int ThisChar = LastChar;
    LastChar = getchar();
    return ThisChar;
}
