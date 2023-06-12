byCar(auckland,hamilton).
byCar(hamilton,raglan).
byCar(valmont,saarbruecken).
byCar(valmont,metz).
byTrain(metz,frankfurt).
byTrain(saarbruecken,frankfurt).
byTrain(metz,paris).
byTrain(saarbruecken,paris).
byPlane(frankfurt,bangkok).
byPlane(frankfurt,singapore).
byPlane(paris,losAngeles).
byPlane(bangkok,auckland).
byPlane(losAngeles,auckland).
travel(X,X).
travel(X,Y):-myCar(X,Z), travel(Z,Y).
travel(X,Y):-myTrain(X,Z), travel(Z,Y).
travel(X,Y):-myPlane(X,Z), travel(Z,Y).
travel(X,Y,byCar):-byCar(X,Y).