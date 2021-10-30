//=========================================================
// File: algoritmo.h
// Author: Michelle Aylin Calzada Montes - A01706202
//         Eduardo Rodríguez Gil - A01274913
// Date: 24/10/2021
//=========================================================

//Estructura para armar el punto
struct Punto{
   int x;
   int y;
};

// Puntos más cercanos.
struct Punto cerca1, cerca2;

//Distancia minima entre puntos
double mindist = 1e10; 

//Ayuda a ordenar los puntos por la coordenada x
//Complejidad O(1)
int ordenx(const void *a, const void *b){
   return(((*(struct Punto *)a).x < (*(struct Punto *)b).x)?-1:1);
 }

// Función que calcula la distancia entre dos puntos.
//Complejidad O(1)
double dist(struct Punto a, struct Punto b){
   return(sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)));
}

//Busca cuales son el par de puntos más cercanos
//Complejidad O(n log(n))
void busca(struct Punto *p, int n){
  
  double d;
  int des, has;

  if(n <= 1) 
    return; 

  qsort(p,n,sizeof(struct Punto), ordenx);

  busca(p,n/2);
   
  busca(p+n/2, (n+1)/2);

  for(des = n/2; des>0 && p[n/2].x-p[des].x<mindist; des--);
  for(has=n/2; has<n-1 && p[has].x-p[n/2].x<mindist; has++);
   
  for(int i = des; i <= has; i++)
    for(int j = i+1; j <= has; j++)
      if((d=dist(p[i],p[j])) < mindist){
        mindist=d;
        cerca1.x=p[0].x;
        cerca1.y=p[0].y;
        cerca2.x=p[1].x;
        cerca2.y=p[1].y;
      }
 }