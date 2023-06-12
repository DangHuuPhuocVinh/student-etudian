output_values(X,X).
output_values(X,Y):-X < Y, write(X),nl,XX is X + 1, output_values(XX,Y).