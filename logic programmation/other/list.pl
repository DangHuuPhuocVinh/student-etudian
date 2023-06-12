membre(X,[X|Y]).
membre(X,[Y|L]):-membre(X,L).
longuer([],0).
longuer([T|Q],N):-longuer(Q,N1),N is N1 + 1.    
concat([],[],[]).
concat([],L,L).
concat([X|Q],L,[X|LR]):-concat(Q,L,LR).
inverse([],[]).
inverse([T|Q],R):-inverse(Q,R1),concat(R1,[T],R).
/* dùng biến tạm để lưu mảng*/
longuer(L,N):-longuer_(L,0,N).
longuer_([],N,N).
longuer_([T|Q],Acc,N):-NN is Acc + 1, longuer(Q,NN,N).

prefixe(P,L):-append(P,_,L).
suffixe(S,L):-append(_,S,L).
sousliste(SousL,Liste):-suffixe(Suffixe,Liste), prefixe(SousL,Suffixe).