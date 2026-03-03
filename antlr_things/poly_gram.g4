grammar poly_gram;

// Лексемы 
DOUBLE: ('0' | [1-9][0-9]*) '.' [0-9]+;
CHAR  : [0-9]+ ;
WS    : [ \t\r\n]+ -> skip ;
MUL   : '*' ;
ADD   : '+' ;

// Синтаксис
polynome : polynome ADD monome # SumOfMonomesPolynome
         | monome              # SingleMonomePolynome
         ;

monome   : '-' monome            # UnaryMinusMonome
         | '(' monome ')'        # ParensMonome
         | coeff (MUL x_var)? (MUL y_var)? (MUL z_var)?  # FinalMonome
         ;

x_var : 'x^' degree ;
y_var : 'y^' degree ;
z_var : 'z^' degree ;

degree   : '-' degree  # UnaryMinusDegree
         | CHAR        # Char
         ;

coeff    : DOUBLE # Double ;