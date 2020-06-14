last_([],X,X).
last_([T|Q],_,X):-last_(Q,T,X).
last__([T|Q],X):-last_(Q,T,X).

a_similaire_b([],[]).
a_similaire_b([a|Q1],[b|Q2]):-a_similaire_b(Q1,Q2).

tous_a([]).
tous_a([a|Q]):-tous_a(Q).

remplacer_a_b_c([],[]).
remplacer_a_b_c([a|Q1],[b|Q2]):-remplacer_a_b_c(Q1,Q2).
remplacer_a_b_c([b|Q1],[c|Q2]):-remplacer_a_b_c(Q1,Q2).
remplacer_a_b_c([c|Q1],[a|Q2]):-remplacer_a_b_c(Q1,Q2).

nieme([X|_],1,X).
nieme([_|Q],N,X):-N > 1,NN is N-1, nieme(Q,NN,X).

double(Liste):-append(P,P,Liste).

aplatir(Liste,Liste1):-aplatir_(Liste,[],Liste1).
aplatir_([],Acc,Acc).
aplatir_(X,Acc,[X|Acc]):-X\=[], X\=[_|_].
aplatir_([T|Q],Acc,LS):-aplatir_(Q,Acc,LS1),aplatir_(T,LS1,LS).

palindrome(Liste):-reverse(Liste,Liste).

premier_dernier(L,LR):-append([_|LR],[_],L).


echanger([X], [X]).
echanger([], []).
echanger(L,LR) :-append([First|Mid], [Last], L), append([Last|Mid], [First], LR).
