readin:-get0(X),process(X).
process(42).
process(X):-X=\=42,write(X),nl,readin.

readin:-get0(X),process(X).
process(10).
process(X):-X=\=42,write(X),nl,readin.