// Manolo Ramirez Pintor - A01706155
// Eduardo Rodriguez Gil - A01274913
// main.cpp
// Actividad 4.4 Implementacion Randomized QuickSort
// 07-11-2021

// El codigo del programa esta basada en la implementacion
// de QuickSort - Geeks for Geeks. URL:
// https://www.geeksforgeeks.org/quick-sort/

//Complejidad O(n*lon(n))

#include<bits/stdc++.h>

using namespace std;

// Toma el ultimo elemento como un pivote
// lo pone en una en una posicion donde
// el arreglo ya esta acomodado y acomoda
// a la izquierda los elementos mas pequenos
// que sean mas grandes del pivote a la derecha.
int part(int elems[], int ini, int fin) {
  
  // Creamos una nueva variable para indicar
  // la posicion del pivote que se encontro.
  int ind = ini;

  // Recorremos en el ciclo de lo que obtuvimos
  for(int i=ini; i<fin; i++) {
    
    // Si el elemento es mas pequeno se incrementa
    // el indice y se hace swap entre la posicion 
    // actual del for y el indice en cuestion.
    if(elems[i] < elems[fin]) {
        swap(elems[i], elems[ind]);
        ind = ind+1;
    }
  }

  // Realizamos un swap para el indice que
  // se quedo igual o cambio por el fin.
  swap(elems[fin], elems[ind]);
  
  // Al final regresamos el valor de indice
  // que quedo despues del swap.
  return ind;
}

// Funciona para obtener el pivote inicial a partir
// del arreglo que tenemos y los valores de inicio/fin.
int getRandomPivot(int elems[], int ini, int fin) {

  // Primer obtenemos un numero aleatorio
  int ran = rand();

  // Establecemos el valor inicial de nuestro pivote
  // y luego lo sumamos con el inicial de un numero
  // random dentro de los valores que tenemos en ini/fin.
  int pvt = ini + ran%(fin-ini+1); 
  
  // Hacemos un intercambio entre el valor final
  // y el pivote que obtuvimos anteriormente.
  swap(elems[fin], elems[pvt]);

  // Retornamos el entero procesando los datos
  // que tenemos del pivote utilizado mediante
  // la funcion de particion que acompana al
  // QuickSort.
  return part(elems, ini, fin);
}

// Lo que hace el QuickSort en si es ordenar los
// elementos del array pero este esta un poco
// modificado para que sea Randomized QuickSort
// mediante el uso del metodo de "Las Vegas"
void QuickSort(int arr[], int ini, int fin){
  
  // Verificamos si el inidce inicial no
  // es mayor al final, si no, no se hace nada
  if(ini < fin) {
    
    // Aqui obtenemos el pivote para usarlo en nuestro
    // Randomized QuickSort con lo que tenemos en el
    // el arreglo, el valor de inicio y de fin.
    int ind = getRandomPivot(arr, ini, fin);
    
    // Mediante dos elementos separados se hace
    // el QuickSort antes y despues de la particion:
    // (Cabe mencionar que esto es recursivo):
    
    // Antes:
    QuickSort(arr, ini, ind-1);

    // Despues:
    QuickSort(arr, ind+1, fin);
  }
}

int main() {

  // Variables inciales
  int n, parr; // Numero de elementos
  
  // Primero ingresamos el numero de elementos
  cin >> n;

  int elems[0xfffff]; // Arreglo de elementos

  // Luego ingresamos todos los numeros que
  // tenemos en nuestro arreglo desordenado
  for (int i = 0; i < n; i++) {
    
    // Entra el elemento
    cin >> elems[i];
  }

  // Obtenemos el tamano arreglado para
  // nuestra funcion de QuickSort

  // Qui
  parr=n-1;

  // Inmediatamente despues llamamos a
  // nuestro QuickSort con el areglo, el
  // indice inicial y el num de elementos.
  
  // Dentro se va a ejecutar como un
  // Randomized QuickSort y obtendremos
  // al final todo nuestro arreglo acomodado.
  QuickSort(elems, 0, parr);

  // Finalmente imprimimos todos nuestros
  // elementos ordenados del arreglo.
  for (int i=0; i<n; i++) {
    
    // Sale el elemento del arreglo correspondiente
    cout<<elems[i]<<" "; 
  }
}