grammar poly_gram;

polynome: 



COEFF : [1-9][0-9]+('.'|',')[0-9]+ ;
WS    : [ \t\r\n]+ -> skip ;
MUL   : '*' ;
ADD   : '+' ;