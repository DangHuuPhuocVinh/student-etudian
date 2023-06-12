/* Ex 1 */
alterner([],[],[]).
alterner([X|Liste],[],[X|Liste]).
alterner([],[Y|Liste],[Y|Liste]).
alterner([X|Liste1],[Y|Liste2],[X|Liste]):-X =< Y,!,alterner(Liste1,[Y|Liste2],Liste).
alterner([X|Liste1],[Y|Liste2],[Y|Liste]):-alterner([X|Liste1],Liste2,Liste).

/* Ex 2 */
rue(v1,v2,20).
rue(v2,v3,15).
rue(v3,v4,10).
rue(v3,v6,4).
rue(v1,v3,10).
rue(v1,v4,30).
rue(v1,v5,5).
rue(v1,v6,15).
rue(v6,v5,7).
rue(v5,v4,9).
rue(v3,v6,4).

chemin(X,Y,A):-rue(X,Y,B),write(X),write(" -> "),write(Y),write(": "),write(B),A is B,nl.
chemin(X,Y,A):-rue(Z,Y,B),chemin(X,Z,C),write(Z),write(" -> "),write(Y),write(": "),write(B),A is B+C,nl.
traverser(X,Y):-findall(A,(chemin(X,Y,A),write("Total: "),write(A),nl),List),length(List, L), L>0.


