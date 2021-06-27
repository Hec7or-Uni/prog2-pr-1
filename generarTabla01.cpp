# include <iostream>
# include <cstdlib>
# include <cstring>
# include <iomanip>

using namespace std;

// Pre : 1 <= n AND d <= h AND ( h - d ) <= RAND_MAX
// Post : El vector v [0 , n-1] almacena n datos del intervalo [d,h]
//	  generados de modo pseudoaleatorio
void generar(int v[], const int n, const int d, const int h);

int main(int argc, char* argv[]) {
	int DATOS_T = atoi(argv[1]);	// n
	int MIN 	= atoi(argv[2]);	// d
	int MAX 	= atoi(argv[3]);	// h
	int datos[DATOS_T];
	generar(datos, DATOS_T, MIN, MAX);

	int TAB = strlen(argv[3]) + 1;

	for (int i = 0; i < DATOS_T; i++) {	
		if (i % 10 == 0) 
			cout << endl;
		cout << setw(TAB) << datos[i];
	}
	cout << endl;

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