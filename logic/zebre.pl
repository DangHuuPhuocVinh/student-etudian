find(ZebraOwner,WaterDrinker):-makehouses(5,List).

sublist2([S1,S2],[S1,S2|L]).
sublist2(S,[_|T]):-sublist2(S,T).

L=[maison(M1,M2,M3,M4,M5)].
maison(C,N,A,B,CI).
M1=maison(_,norvegien,_,_,_).
M2=maison(bleue,_,_,_,_).
M3=(_,_,_,lait,_).
M=(rouge,anglais,_,_,_).
M=(verte,_,_,cafe,_).
M=(jaune,_,_,_,kool).
M=(blanche,_,_,_,_).
M=(_,espagnol,chien,_,_).
M=(_,ukrainian,_,the,_).
M=(_,japonais,_,_,craven).
M=(_,_,escargot,_,oldgold).
M=(_,_,_,vin,gitane).
M=(_,_,_,_,chesterfield).
M=(_,_,renard,_,_).
M=(_,_,cheval,_,_).
member(maison(C,N,A,B,CI),L).
main:-member.


voisin_de(A,B,[A,B|_]).
voisin_de(A,B,[B,A|_]).
voisin_de(A,B,[_|Q]):-voisin_de(A,B,Q).