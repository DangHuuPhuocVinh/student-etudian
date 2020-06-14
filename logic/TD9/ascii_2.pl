readin:-get0(X),process(X).
process(10).
process(X):-X=\=10,convert(X,Y),put(Y),nl,readin.

convert(X,X):-X < 65.
convert(X,X):-X > 90.
convert(X,Y):-X > 64, X < 91, Y is X + 32.

