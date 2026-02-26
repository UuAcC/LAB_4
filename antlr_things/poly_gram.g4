grammar poly_gram;

polynome: polynome ADD monome
        | monome 
        ;

monome  : '-' monome          # unaryMinus
        | '(' monome ')'      # parens
        | COEFF MUL 
        ;

COEFF : [1-9][0-9]+('.'|',')[0-9]+  # monomeCoefficient
      ;
DEG   : [0-9]+                      # varDegree
      ;
WS    : [ \t\r\n]+ -> skip 
      ;
MUL   : '*' 
      ;
ADD   : '+' 
      ;