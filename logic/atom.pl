termetype(T,atom):-atom(T).
termetype(T,variable):-var(T).
termetype(T,constant):-atomic(T).
termetype(T,simple_term):-termetype(T,constant).
termetype(T,simple_term):-termetype(T,variable).
complexterm(X):-nonvar(X),functor(X,_,A),A  >  0.
termetype(T,complex_term):- complexterm(T).
termetype(T,term):-termetype(T,complex_term).
termetype(T,term):-termetype(T,simple_term).


