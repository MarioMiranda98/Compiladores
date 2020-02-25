%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>
    #include <ctype.h>
    #include"vector_cal.c"

    int yyerror(char *s);
    int yylex();
%}

%union{
    double val;
    Vector *vector;
}

%token<val> NUMBER

%type<vector> exp        
%type<vector> vector    
%type<val> number      

%left '+' '-'
%left '*'
%left 'x' '.'

%%
    inputString:
      | inputString list;
      ;

    list: '\n'
      | exp     '\n'  {imprimeVector($1);}
      | number  '\n'  {printf("%lf\n", $1);}
      ;

    exp: vector
      | exp '+' exp     {$$ = sumaVector($1, $3);}
      | exp '-' exp     {$$ = restaVector($1, $3);}
      | exp '*' NUMBER     {$$ = escalarVector($3, $1);}
      | NUMBER '*' exp  {$$ = escalarVector($1, $3);}
      | exp 'x' exp     {$$ = productoCruz($1, $3);}
    ;

    number: NUMBER
      | vector '.' vector {$$ = productoPunto($1, $3);}
      | '|' vector '|' {$$ = vectorMagnitud($2);}
      ;

    vector : '[' NUMBER NUMBER NUMBER ']' {Vector *v = creaVector(3);
                                            v -> vec[0] = $2;
                                            v -> vec[1] = $3;
                                            v -> vec[2] = $4;
                                            $$ = v;}
      ;
%%

void main(){
  yyparse();
}

int yylex (){
  	int c;
  	while ((c = getchar ()) == ' ' || c == '\t')
  		;
 	if (c == EOF)
    		return 0;
  if(isdigit(c)){
      ungetc(c, stdin);
      scanf("%lf", &yylval.val);
      return NUMBER;
  }
  return c;
}

int yyerror(char *s){
  printf("%s\n", s);
  return 0;
}