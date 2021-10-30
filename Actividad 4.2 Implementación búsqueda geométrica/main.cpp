//=========================================================
// File: main.cpp
// Author: Michelle Aylin Calzada Montes - A01706202
//         Eduardo Rodríguez Gil - A01274913
// Date: 24/10/2021
//=========================================================

#include <bits/stdc++.h>
#include "algoritmo.h"

using namespace std;

//Para definir el número límite de puntos, para casos extremos
#define limit 999999

int main(){

   int n;
   double x, y;
   struct Punto p[limit];

  //Entrada de cuantos puntos se crearán
  scanf(" %d",&n);
  
  //Entrada de los puntos
  for(int i = 0; i < n; i++){
    scanf("%lf %lf", &x, &y);
    p[i].x=x;
    p[i].y=y;
  }

  //Busca el par más cercano
  busca(p,n);

  //Imprime el resultado
  cout << "El par mas cercano: (" << cerca1.x << "," << cerca1.y << "), (" << cerca2.x << "," << cerca2.y << ")" << endl;

  return 0;
}