// Manolo Ramirez Pintor - A01706155
// Eduardo Rodriguez Gil - A01274913
// main.cpp
// Actividad 5.5 Implementación A*
// 12-11-2021

// El codigo del programa esta basada en la implementacion
// de Rat in a Maze Problem when movement in all possible
// directions is allowed - Geeks for Geeks. URL:
// https://www.geeksforgeeks.org/rat-in-a-maze-problem-when-movement-in-all-possible-directions-is-allowed/
// y en la implementación de A* Search Algorithm. URL: (Descartado)
// https://www.geeksforgeeks.org/a-search-algorithm/

// Al final no pudimos implementar A*, decidimos deshacerlo porque
// nos causaba muchos problemas aun así re-estructurando todo.

// Queremos entregar aunque sea una parte de la solucion con la finalidad
// de demostrar nuestro interés por realizar el trabajo e intentar cumplir
// con la solucion del algoritmo. :(

// Gracias prof.

#include <bits/stdc++.h>

using namespace std;

// Determina si puede moverse a uno de los lugares mediante
// true, si no se puede regresa false para intentar con otro
// elemento del array de nuestro laberinto y determinar la ruta.
bool puedeIr(int fila, int columna, int laberinto[][999], int tam, bool ido[][999]) {
  if (fila == -1) {
    return 0;
  }

  else if(fila == tam) {
    return 0;
  }

  else if(columna == -1) {
    return 0;
  }

  else if(columna == tam) {
    return 0;
  }

  else if(ido[fila][columna]) {
    return 0;
  }
  
  else if(laberinto[fila][columna] == 0) {
    return 0;
  }

  else {
    return 1;
  }
}
 
// Esta funcion imprime todos los posibles valores para la
// ruta o rutas desde el inicio hasta el final del arreglo.
void rutaPosible(int fila, int columna, int laberinto[][999], int tam, string& camino, vector<string>&caminosPosibles, bool ido[][999]) {
  
  // Revisar desde el inicio para comenzar el proceso
  // del calculo de todas las rutas posibles.
  if (fila == -1) {
    return;
  }

  else if(fila == tam) {
    return;
  }

  else if(columna == -1) {
    return;
  }

  else if(columna == tam) {
    return;
  }

  else if(ido[fila][columna]) {
    return;
  }

  else if(laberinto[fila][columna]==0) {
    return;
  }

  else {
    // No hacer nada
  }

  // Al llegar a la ultima posicion vamos a guardar
  // el camino obtenido y nos vamos a regresar.
  if (fila == tam - 1 && columna == tam - 1) {
    caminosPosibles.push_back(camino);
    return;
  }

  // Determinamos que ya hemos estado en
  // la posicion actual de la fila y columna
  ido[fila][columna] = 1;

  // En esta parte se realiza un intento de moverse en
  // las cuatro direcciones a partir de las condiciones
  // que tenemos para poder avanzar satisfactoriamente
  // hacia alguno de los cuatro lados disponibles.
  if (puedeIr(fila - 1, columna, laberinto, tam, ido)) {
    camino.push_back('U');
    rutaPosible(fila - 1, columna, laberinto, tam, camino, caminosPosibles, ido);
    camino.pop_back();
  }

  if (puedeIr(fila + 1, columna, laberinto, tam, ido)) {
    camino.push_back('D');
    rutaPosible(fila + 1, columna, laberinto, tam, camino, caminosPosibles, ido);
    camino.pop_back();
  }

  if (puedeIr(fila, columna - 1, laberinto, tam, ido)) {
    camino.push_back('L');
    rutaPosible(fila, columna - 1, laberinto, tam, camino, caminosPosibles, ido);
    camino.pop_back();
  }

  if (puedeIr(fila, columna + 1, laberinto, tam, ido)) {
    camino.push_back('R');
    rutaPosible(fila, columna + 1, laberinto, tam, camino, caminosPosibles, ido);
    camino.pop_back();
  }

  // Marcamos una parte del arreglo como si no
  // hubieramos ido para tomar en cuenta otros
  // caminos posibles del laberinto dado.
  ido[fila][columna] = 0;
}

// En esta parte vamos a guardar y despues
// mostrar todas las rutas posibles obtenidas
void obtSolucion(int laberinto[][999], int tam) {
  vector<string> caminosPosibles; string camino;
  bool ido[tam][999];
  memset(ido, false, sizeof(ido));
    
  // Llamamos a la funcion de a ruta posible comenzando
  // en el inicio de nuestro arreglo (0,0)
  rutaPosible(0, 0, laberinto, tam, camino, caminosPosibles, ido);

  // Aqui imprimimos los caminos que al final pudimos obtener
  for (int i = 0; i < caminosPosibles.size(); i++) {
    cout<<caminosPosibles[i]<<endl;
  }
}
 
// Inicio del programa:
// Aqui se establecera el tamaño del laberinto y
// tambien se ingresaran los datos del mismo para
// luego llamar a la funcion que nos permitira
// obtener el resultado de los caminos posibles
// hasta poder llegar al otro lado sin problema.
int main() {
  // Variables iniciales
  int tam; // Tamaño en (lxl)
  int laberinto[999][999]; // Datos del laberinto en 1's y 0's

  /*  
    Laberinto de ejemplo:
    4
    1 0 0 0
    1 1 0 1
    1 1 0 0
    0 1 1 1
  */
  cin>>tam;

  for(int i = 0; i < tam; i++) {
    for(int j = 0; j < tam; j++) {
      cin >> laberinto[i][j];
    }
  }
  
  // Entra la funcion que buscara la ruta
  obtSolucion(laberinto, tam);
}