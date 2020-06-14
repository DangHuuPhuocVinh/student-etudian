/*Đặng Hữu Phước Vinh 1752052*/

/*Ex 2*/
homme(albert).
homme(tom).
homme(daniel).
homme(claude).
homme(michel).
homme(jack).
homme(andre).
homme(bernard).
homme(francois).
homme(roger).

femme(marie).
femme(isabelle).
femme(jacques).
femme(jeanne).
femme(sylvie).
femme(monique).
femme(camille).
femme(nicole).
femme(melia).
femme(rene).
femme(jacqueline).

parent(albert,sylvie).
parent(marie,sylvie).
parent(tom,claude).
parent(isabelle,claude).
parent(jacques,michel).
parent(daniel,michel).
parent(jacques,monique).
parent(daniel,monique).
parent(sylvie,jack).
parent(claude,jack).
parent(sylvie,camille).
parent(claude,camille).
parent(sylvie,andre).
parent(claude,andre).
parent(michel,bernard).
parent(monique,bernard).
parent(michel,nicole).
parent(monique,nicole).
parent(jeanne,melia).
parent(jack,melia).
parent(bernard,rene).
parent(melia,rene).
parent(bernard,francois).
parent(melia,francois).
parent(francois,roger).
parent(jacqueline,roger).

marie_a(albert,marie).
marie_a(tom,isabelle).
marie_a(daniel,jacques).
marie_a(claude,sylvie).
marie_a(michel,monique).
marie_a(jack,jeanne).
marie_a(bernard,melia).
marie_a(francois,jacqueline).

/*Ex 3*/
epoux(X,Y):-homme(X), marie_a(X,Y).
epouse(Y,X):-femme(Y), marie_a(X,Y).

pere(X,Y):-homme(X), parent(X,Y).
mere(X,Y):-femme(X), parent(X,Y).

enfant_de_meme_parent(X,Y):-pere(Z,X),pere(Z,Y).
frere(X,Y):-homme(X), enfant_de_meme_parent(Z,X), enfant_de_meme_parent(Z,Y).
soeur(X,Y):-femme(X), enfant_de_meme_parent(Z,X), enfant_de_meme_parent(Z,Y).

grand_parent(X,Y):-parent(X,Z), parent(Z,Y).
grand_pere(X,Y):-homme(X), parent(X,Z), parent(Z,Y).
grand_mere(X,Y):-femme(X), parent(X,Z), parent(Z,Y).

oncle_ou_tante(X,Y):-enfant_de_meme_parent(X,Z), parent(Z,Y).
oncle(X,Y):-homme(X), enfant_de_meme_parent(X,Z), parent(Z,Y).
tante(X,Y):-femme(X), enfant_de_meme_parent(X,Z), parent(Z,Y).

cousin(X,Y):-oncle_ou_tante(Z,X), parent(Z,Y).

niece_ou_neveu(X,Y):-parent(X,Z), enfant_de_meme_parent(Z,Y).
niece(X,Y):-femme(X), parent(Z,X), enfant_de_meme_parent(Z,Y).
neveu(X,Y):-homme(X), parent(Z,X), enfant_de_meme_parent(Z,Y).

petit_fils(X,Y):-homme(X), parent(Y,Z), parent(Z,X).
petit_fille(X,Y):-femme(X), parent(Y,Z), parent(Z,X).