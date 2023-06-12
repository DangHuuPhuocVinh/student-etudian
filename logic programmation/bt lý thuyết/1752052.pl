personnes(0, []) :- !.
personnes(N, [(_Nation,_Couleur,_Boisson,_Fumee,_Animal)|T]) :- M is N-1, personnes(M,T).

personne(1, [A|_], A) :- !.
personne(N, [_|T], B) :- M is N-1, personne(M, T, B).

maison1(Persons) :- personne(1, Persons, (norvegien,_,_,_,_)).
maison2([(norvegien,_,_,_,_),(_,bleue,_,_,_)|_]).
maison2([(_,bleue,_,_,_),(norvegien,_,_,_,_)|_]).
maison2([_|T]) :- maison2(T).
maison3(Persons) :- personne(3, Persons, (_,_,lait,_,_)).
maison4([(anglais,rouge,_, _, _)|_]).
maison4([_|T]) :- maison4(T).
maison5([(_,vert,cafe,_,_)|_]).
maison5([_|T]) :- maison5(T).
maison6([(_,jaune,_,kool,_)|_]).
maison6([_|T]) :- maison6(T).
maison7([(_,vert,_,_,_),(_,blanche,_,_,_)|_]).
maison7([_|T]) :- maison7(T).
maison8([(espagnol,_,_,_,chien)|_]).
maison8([_|T]) :- maison8(T).
maison9([(ukrainien,_,the,_,_)|_]).
maison9([_|T]) :- maison9(T).
maison10([(japonais,_,_,craven,_)|_]).
maison10([_|T]) :- maison10(T).
maison11([(_,_,_,escargort,oldgold)|_]).
maison11([_|T]) :- maison11(T).
maison12([(_,_,duvin,gitane,_)|_]).
maison12([_|T]) :- maison12(T).
maison13([(_,_,_,chesterfield,_),(_,_,_,_,renard)|_]).
maison13([(_,_,_,_,renard),(_,_,_,chesterfield,_)|_]).
maison13([_|T]) :- maison13(T).
maison14([(_,_,_,kool,_),(_,_,_,_,cheval)|_]).
maison14([(_,_,_,_,cheval),(_,_,_,kool,_)|_]).
maison14([_|T]) :- maison14(T).

question1([(_,_,_,_,zebre)|_]).
question1([_|T]) :- question1(T).
question2([(_,_,eau,_,_)|_]).
question2([_|T]) :- question2(T).

solution(Persons) :-
  personnes(5, Persons),
  maison1(Persons),
  maison2(Persons),
  maison3(Persons),
  maison4(Persons),
  maison5(Persons),
  maison6(Persons),
  maison7(Persons),
  maison8(Persons),
  maison9(Persons),
  maison10(Persons),
  maison11(Persons),
  maison12(Persons),
  maison13(Persons),
  maison14(Persons),
  question1(Persons),
  question2(Persons).