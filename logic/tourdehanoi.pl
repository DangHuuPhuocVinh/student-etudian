deplacer(1,X,Y,_) :-  
    write('Deplacer '), 
    write(X), 
    write(' vers '), 
    write(Y), 
    nl. 
deplacer(N,X,Y,Z) :- 
    N > 1, 
    M is N-1, 
    deplacer(M,X,Y,Z), 
    deplacer(1,X,Z,_), 
    deplacer(M,Y,Z,X).