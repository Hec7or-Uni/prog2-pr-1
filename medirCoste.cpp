# include <iostream>
# include <cstdlib>
# include <cstring>
# include <iomanip>
// #include <algorithm> //para la funcion sort()

using namespace std;

// Pre : 1 <= n AND d <= h AND ( h - d ) <= RAND_MAX
// Post : El vector v [0 , n-1] almacena n datos del intervalo [d,h]
//	  generados de modo pseudoaleatorio
void generar(int v[], const int n, const int d, const int h);

// Pre:  a = X y b = Y
// Post: a = Y y b = X
void permutar(int &a, int &b);

// Pre: n>0
// Post: v[0..n-1] es una permutación de los datos iniciales de v[0..n-1] y todos
//       ellos están ordenados de menor a mayor valor
void ordenar(int v[], const int n);

int main(int argc, char* argv[]) {
	int DATOS_T = atoi(argv[1]);	// n
	int MIN 	= atoi(argv[2]);	// d
	int MAX 	= atoi(argv[3]);	// h
	int datos[DATOS_T];
	
	generar(datos, DATOS_T, MIN, MAX);

	cout << "Datos a ordenar:" << endl;
	int TAB = strlen(argv[3]) + 1;
	// primeros 20 numeros DESORDENADOS
	for (int i = 0; i < 20; i++) {
		if (i % 10 == 0) cout << endl;
		cout << setw(TAB) << datos[i];
	}
	cout << endl;
	// ultimos 20 numeros DESORDENADOS
	for (int i = DATOS_T; i > DATOS_T - 20; i--) {	
		if (i % 10 == 0) cout << endl;
		cout << setw(TAB) << datos[i-1];
	}
	cout << endl;
	cout << "\nOrdenando " << DATOS_T << " datos enteros ..." << endl;
	time_t t1 = time(nullptr);
	// sort(datos, datos + DATOS_T); //sort() ordena un vector
	ordenar(datos, DATOS_T);
	time_t t2 = time(nullptr);
	int segundos = int(t2 - t1);
	cout << "\nDatos ordenados:" << endl;
	
	// primeros 20 numeros ORDENADOS
	for (int i = 0; i < 20; i++) {
		if (i % 10 == 0) cout << endl;
		cout << setw(TAB) << datos[i];
	}
	cout << endl;
	// ultimos 20 numeros ORDENADOS
	for (int i = DATOS_T - 20; i < DATOS_T ; i++) {	
		if (i % 10 == 0) 
			cout << endl;
		cout << setw(TAB) << datos[i];
	}
	cout << endl;
	cout << "Tiempo de CPU para ordenar " << DATOS_T << " enteros : " << segundos << " segundos." << endl;

	return 0;
}

// Pre : 1 <= n AND d <= h AND ( h - d ) <= RAND_MAX
// Post : El vector v [0 , n-1] almacena n datos del intervalo [d,h]
//	  generados de modo pseudoaleatorio
void generar ( int v[] , const int n , const int d , const int h ) {
	time_t semilla = time(nullptr);	// tiempo actual como semilla
	srand(semilla);		// Inicializa el generador de
				// núms.pseudoaleatorios
	for ( int i = 0; i < n ; i++ ) {
		// Asigna a v [i] un pseudoaleatorio del intervalo [d, h]
		v[i] = d + rand() % (h - d + 1);
	}
}

// Fichero ordenar.h que contiene un algoritmo genérico
// de ordenación de vectores

// Definición de predicados utilizados para simplificar las especificaciones
// de las funciones genéricas de este fichero:
//
//   sonPermutacion(v1, v2, desde, hasta) =
//         (PT alfa EN [desde,hasta].
//                (NUM beta EN [desde,hasta].v1[alfa]=v1[beta])
//                = (NUM beta EN [desde,hasta].v1[alfa]=v2[beta]) )
//
//   estaOrdenado(v, desde, hasta) = 
//         (PT alfa EN [desde,hasta-1].v[alfa] <= v]alfa+1])

// Pre:  a = X y b = Y
// Post: a = Y y b = X
void permutar(int &a, int &b) {
    int aux = a;
    a = b;  b = aux;
}

// Pre: n>0
// Post: v[0..n-1] es una permutación de los datos iniciales de v[0..n-1] y todos
//       ellos están ordenados de menor a mayor valor
void ordenar(int v[], const int n) {
    // Ordenación de v[0,n-1] por el método de selección
    for (int i = 0; i < n - 1; ++i) {
        // Los datos de v[0..i-1] son los menores y ya están ordenados 
        // Selecciona el dato menor de v[i..n-1]
        int iMenor = i;
        for (int j = i + 1; j < n; ++j) {
            // v[iMenor] es el menor de v[i..j-1]
            if (v[j] < v[iMenor]) {
                iMenor = j;
            }
            // v[iMenor] es el menor de v[i..j]
        }
        // v[iMenor] es el menor de v[i..n-1]. Permuta v[i] y v[iMenor]
        permutar(v[i], v[iMenor]);
        // Los datos de v[0..i] son los menores y ya están ordenados
    }
    // Los datos de v[0..n-1] ya están ordenados
}
