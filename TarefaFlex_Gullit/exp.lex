%option noyywrap
%option nodefault
%option outfile="lexer.c" header-file="lexer.h"

%{ 
    #include "exp.h" 
%}

NUM_INT [0-9]+
NUM_FLOAT [-+]?{NUM_INT}.?{NUM_INT}
LETRA  [A-Za-z]
ID ({LETRA}|_)({NUM_INT}|{LETRA}|_)*
RELOP <|>|<=|>=|=|!=
SEPARADOR [ \t\n]
COMENTARIO \/\*(.)*\*\/
BEGIN   "begin"
END     "end"
WHILE   "while"
REPEAT  "repeat"
UNTIL   "until"
ATRIBUICAO ":="

%%

{NUM_INT}       { return token(TOK_INT, yytext); }
{NUM_FLOAT}     { return token(TOK_FLOAT, yytext); }
\+          { return token(TOK_OP, SOMA); }
-           { return token(TOK_OP, SUB); }
\*          { return token(TOK_OP, MULT); }
\/          { return token(TOK_OP, DIV); }
\(          { return token(TOK_PONT, PARESQ); }
\)          { return token(TOK_PONT, PARDIR); }
{RELOP}     { return token(TOK_RELOP, yytext); }
{SEPARADOR} { return token(TOK_SEP, NULL); }
{COMENTARIO} { return token(TOK_COMENT, NULL); }
{BEGIN}     { return token(TOK_BEGIN, NULL); }
{END}       { return token(TOK_END, NULL); }
{WHILE}     { return token(TOK_WHILE, NULL); }
{REPEAT}    { return token(TOK_REPEAT, NULL); }
{UNTIL}     { return token(TOK_UNTIL, NULL); }
{ATRIBUICAO}     { return token(TOK_ATRI, NULL); }
{ID}        { return token(TOK_ID, yytext); }
<<EOF>>		{ return token(TOK_EOF, NULL); }
.           { return token(TOK_ERROR, 0); }

%%

// variavel global para um token 
Token tok;
Token * token (int tipo, char* valor) {
	tok.tipo = tipo;
	tok.valor = valor ? strdup(valor) : "-";
	return &tok;
}