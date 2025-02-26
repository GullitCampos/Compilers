#include "lexer.h"
#include "exp.h"
/* Carrega uma string como entrada */
YY_BUFFER_STATE buffer;
int inicializa()
{
    char str[256];
    printf("Arquivo: ");
    scanf("%255s", str);
    FILE *f = fopen(str, "r");

    if (f == NULL)
    {
        perror("Erro ao abrir o arquivo");
        return 0;
    }

    yyin = f;

    return 1;
}
Token *proximo_token()
{
    return yylex();
}
void imprime_token(Token *tok)
{
    /* Aqui deve implementar o código para mostrar o token retornado pelo
    analisador léxico <token, atributo> de acordo com o tipo do token
    (obs: lembre-se que alguns tokens não possuem atributo)*/
    if (tok->tipo == TOK_INT)
    {
        printf("<Inteiro, %s >\n", tok->valor);
    }
    else if (tok->tipo == TOK_FLOAT)
    {
        printf("<FLOAT, %s >\n", tok->valor);
    }
    else if (tok->tipo == TOK_SEP)
    {
        printf("<SEP, - >\n");
    }
    else if (tok->tipo == TOK_ID)
    {
        printf("<ID, %s >\n", tok->valor);
    }
    else if (tok->tipo == TOK_RELOP)
    {
        printf("<RELOP, %s >\n", tok->valor);
    }
    else if (tok->tipo == TOK_COMENT)
    {
        printf("<COMENT, - >\n");
    }
    else if (tok->tipo == TOK_ATRI)
    {
        printf("<ATR, - >\n");
    }
    else if (tok->tipo == TOK_EOF)
    {
        printf("<EOF, - >\n");
    }
    else if (tok->tipo == TOK_BEGIN)
    {
        printf("<BEGIN, - >\n");
    }
    else if (tok->tipo == TOK_END)
    {
        printf("<END, - >\n");
    }
    else if (tok->tipo == TOK_WHILE)
    {
        printf("<WHILE, - >\n");
    }
    else if (tok->tipo == TOK_REPEAT)
    {
        printf("<REPEAT, - >\n");
    }
    else if (tok->tipo == TOK_UNTIL)
    {
        printf("<UNTIL, - >\n");
    }
    else if (tok->tipo == TOK_OP)
    {
        printf("<OP, %s >\n", tok->valor);
    }
    else if (tok->tipo == TOK_PONT)
    {
        printf("<PONT, %s >\n", tok->valor);
    }
}
int main()
{
    if (inicializa())
    {
        Token *tok;
        while ((tok = proximo_token()) != NULL)
        {
            imprime_token(tok);
            if (tok->tipo == TOK_EOF)
            {
                break;
            }
        }
    }
    return 0;
}