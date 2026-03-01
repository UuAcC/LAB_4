grammar poly_gram;

// Лексемы 
DOUBLE: ('0' | [1-9][0-9]*) (('.' | ',') [0-9]+)?;
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
         | coeff MUL variable MUL variable MUL variable  # FinalMonome
         ;

variable : var=('x'|'y'|'z') '^' degree ;

degree   : '-' degree  # UnaryMinusDegree
         | CHAR        # Char
         ;

coeff    : DOUBLE # Double ;                          