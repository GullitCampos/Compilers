#include "lexer.h"
#include "exp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Global buffer for input */
YY_BUFFER_STATE buffer;

/* Function to initialize the lexer with a file */
int initialize_lexer()
{
    char filename[256];
    printf("Enter the file name: ");
    scanf("%255s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0; // Return 0 to indicate failure
    }

    yyin = file; // Set the input file for the lexer
    return 1;    // Return 1 to indicate success
}

/* Function to get the next token from the lexer */
Token *get_next_token()
{
    return yylex();
}

/* Function to print the token in the required format */
void print_token(Token *token)
{
    if (token == NULL)
    {
        printf("<NULL_TOKEN>\n");
        return;
    }

    switch (token->tipo)
    {
    case TOK_INT:
        printf("<INT, %s>\n", token->valor);
        break;
    case TOK_FLOAT:
        printf("<FLOAT, %s>\n", token->valor);
        break;
    case TOK_ID:
        printf("<ID, %s>\n", token->valor);
        break;
    case TOK_RELOP:
        printf("<RELOP, %s>\n", token->valor);
        break;
    case TOK_SEP:
        printf("<SEP, ->\n");
        break;
    case TOK_COMENT:
        printf("<COMENT, ->\n");
        break;
    case TOK_ATRI:
        printf("<ATRI, ->\n");
        break;
    case TOK_EOF:
        printf("<EOF, ->\n");
        break;
    case TOK_BEGIN:
        printf("<BEGIN, ->\n");
        break;
    case TOK_END:
        printf("<END, ->\n");
        break;
    case TOK_WHILE:
        printf("<WHILE, ->\n");
        break;
    case TOK_REPEAT:
        printf("<REPEAT, ->\n");
        break;
    case TOK_UNTIL:
        printf("<UNTIL, ->\n");
        break;
    case TOK_OP:
        printf("<OP, %s>\n", token->valor);
        break;
    case TOK_PONT:
        printf("<PONT, %s>\n", token->valor);
        break;
    case TOK_ERROR:
        printf("<ERROR, ->\n");
        break;
    default:
        printf("<UNKNOWN_TOKEN, ->\n");
        break;
    }
}

int main()
{
    if (!initialize_lexer())
    {
        return 1; // Exit if file initialization fails
    }

    Token *token;
    while ((token = get_next_token()) != NULL)
    {
        print_token(token);
        if (token->tipo == TOK_EOF)
        {
            break; // Stop when EOF is reached
        }
    }

    return 0;
}