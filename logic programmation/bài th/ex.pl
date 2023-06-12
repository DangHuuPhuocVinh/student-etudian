pere_de(Paul,Christine).
pere_de(Paul,Sylvain).
pere_de(Mathias,Catherine).
pere_de(Albert,Francois).
pere_de(Sylvain,Nathalie).
mere_de(Helene,Christine).
mere_de(Helene,Sylvain).
mere_de(Helene,Christine).
mere_de(Sylvie,Catherine).
mere_de(Catherine,Nathalie).
mere_de(Christine,Francois).
enfant_de(X,Y):-pere_de(Y,X).
enfant_de(X,Y):-mere_de(Y,X).
parent_de(X,Y):-pere_de(X,Y).
parent_de(X,Y):-mere_de(X,Y).
grand_mere_de(X,Z):-mere_de(X,Y), mere_de(Y,Z).
grand_pere_de(X,Z):-pere_de(X,Y), pere_de(Y,Z).
grand_parent_de(X,Z):-parent_de(X,Y), parent_de(Y,Z).
femme_de(X,Y):-mere_de(Y,Z), enfant_de(Z,X).
mari_de(X,Y):-pere_de(Y,Z), enfant_de(Z,X).