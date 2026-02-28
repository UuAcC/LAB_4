grammar poly_gram;

polynome: polynome ADD monome
        | monome 
        ;

monome  : '-' monome                                  
        | '(' monome ')'                              
        | COEFF MUL x_var MUL y_var MUL z_var
        ;

x_var   : 'x' '^' DEG
        ;
y_var   : 'y' '^' DEG
        ;
z_var   : 'z' '^' DEG
        ;

COEFF : ('0' | [1-9][0-9]*) (('.' | ',') [0-9]+)?     
      ;
DEG   : [1-9][0-9]+    
      | '-' DEG                            
      ;
WS    : [ \t\r\n]+ -> skip 
      ;
MUL   : '*' 
      ;
ADD   : '+' 
      ;