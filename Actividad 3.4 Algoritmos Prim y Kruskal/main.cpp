/*
Michelle Aylin Calzada Montes A01706202
Eduardo Rodriguez A01274913
*/

#include <bits/stdc++.h>

using namespace std;

int cosTotal = 0;


//Clase para crear las aristas del grafo
class Arista{
	int vi, vf, peso;

public:

	Arista(int u, int v, int costo) {
		vi = u;
		vf = v;
		this -> peso = costo;
	}

  int obtCosto() {
		return peso;
	}

	int obtVer1() {
		return vi;
	}

	int obtVer2() {
		return vf;
	}

	bool operator < (const Arista& arista2) const{
		return (peso < arista2.peso);
	}
};


//Clase para construir el grafo
class Grafo{
	int numVer;
	vector<Arista> aristas;

public:

	Grafo(int numVer){
		this->numVer = numVer;
	}

	//Crea una arista y la agrega al grafo
	void addArista(int u, int v, int costo) {
		Arista aris(u, v, costo);
		aristas.push_back(aris);
	}

	//Obtiene el subconjunto de un elemento
	int buscar(int sub[], int i) {
		if(sub[i] == -1)
			return i;
		return buscar(sub, sub[i]);
	}

	//Une dos subconjuntos en uno
	void unir(int subset[], int v1, int v2) {
		int vi_set = buscar(subset, v1);
		int vf_set = buscar(subset, v2);

		subset[vi_set] = vf_set;
	}

	//Algoritmo de kruskal
	void kruskal() {
		vector<Arista> res;

		//Ordena las aristas por menor costo
		sort(aristas.begin(), aristas.end());

		//Asigna memoria para subconjuntos de la cantidad de vértices
		int * subset = new int[numVer];

		//Inicializa los subconjuntos como conjuntos de un solo elemento
		memset(subset, -1, sizeof(int) * numVer);

		for(int i = 0; i < aristas.size(); i++) {
			int vi = buscar(subset, aristas[i].obtVer1());
			int vf = buscar(subset, aristas[i].obtVer2());

      //Si son diferentes se agrega a un vector y hace una unión
			if(vi != vf) {				
				res.push_back(aristas[i]);
				unir(subset, vi, vf); 
			}
		}

		//Imprime las aristas seleccionadas con sus costos
		for(int i = 0; i < res.size(); i++) {
			char vi = 'A' + res[i].obtVer1();
			char vf = 'A' + res[i].obtVer2();
			cout << "(" << vi << " - " << vf << ") = " << res[i].obtCosto() << endl;

      //Va sumando el costo total
      cosTotal += res[i].obtCosto();
		}
	}
};

int main() {

  int n, u[100], v[100], costo[100];

  //Agrega el número total de arcos
  cin >> n;

  //Agrega cada arco con este orden "num_vertice_inicial num_vertice_final costo"
  //Ejemplo: 1 2 4
  //Nota: el vértice más pequeño inicia con 0, siendo A=0, B=1, C=2, etc. 
  for(int i = 0; i < n; i++){
    cin >> u[i] >> v[i] >> costo[i];
  }

  //Decide que tamaño va a ter el grafo dependiendo cual es el valor del vértice de mayor valor que se pone
  int numMax = 0;

  for(int i = 0; i < n; i++){
    if (numMax < u[i])
      numMax = u[i];

    if(numMax < v[i])
      numMax = v[i];
  }

  //Crea el grafo y se le agregan las aristas
  Grafo g(numMax+1);

  for(int i = 0; i < n; i++){
    g.addArista(u[i], v[i], costo[i]);
  }
	
  //Recrea el algoritmo de krustal
	g.kruskal();

  //Imprime el costo total
  cout << "Costo total: " << cosTotal << endl; 
	
	return 0;
}