# compilers

Primeira - Parte do Trabalho. 

### Tabela 1: Definição da Gramática Livre de Contexto (GLC)

| **Produção**               | **Regra em EBNF**                                                                 |
|----------------------------|-----------------------------------------------------------------------------------|
| `<prog>`                  | `programa TOK_MAIN TOK_ID <bloco>`                                               |
| `<bloco>`                 | `TOK_BEGIN <declaracao_vars>? <bloco_linha>`                                     |
| `<bloco_linha>`           | `TOK_END` \| `<cmds> TOK_END`                                                    |




| **Token**            | **Tipo de Token**          | **Valor do Atributo** (quando aplicável) | **Descrição**                                                                 |
|-----------------------|----------------------------|------------------------------------------|-------------------------------------------------------------------------------|
| `TOK_MAIN`           | Palavra-chave              | `programa`                               | Indica o início de um programa.                                               |
| `TOK_BEGIN`          | Palavra-chave              | `begin`                                  | Início de um bloco de código.                                                 |
| `TOK_END`            | Palavra-chave              | `end`                                    | Fim de um bloco de código.                                                    |
