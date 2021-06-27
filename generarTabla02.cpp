# include <iostream>
# include <cstdlib>
# include <cstring>
# include <iomanip>
# include <cmath>

using namespace std;

//CONSTANTES
const int APROX = 3;
const int ESPACIADO = 2;

// Pre : 1 <= n AND d <= h AND ( h - d ) <= RAND_MAX
// Post : El vector v [0 , n-1] almacena n datos del intervalo [d,h]
//	  generados de modo pseudoaleatorio
void generar(double v[], const int n, const double d, const double h);

int main(int argc, char* argv[]) {
	int DATOS_T = atoi(argv[1]);	// n
	double MIN  = atof(argv[2]);	// d
	double MAX  = atof(argv[3]);	// h
	double datos[DATOS_T];
	generar(datos, DATOS_T, MIN, MAX);
	
	int DELIMITADOR = int(log10(MAX)) + ESPACIADO + APROX; 	

	for (int i = 0; i < DATOS_T; i++) {	
		if (i % 10 == 0) 
			cout << endl;
		cout << fixed << setprecision(APROX) << setw(DELIMITADOR) << datos[i];
	}
	cout << endl;

	return 0;
}

// Pre : 1 <= n AND d <= h AND ( h - d ) <= RAND_MAX
// Post : El vector v [0 , n-1] almacena n datos del intervalo [d,h]
//	  generados de modo pseudoaleatorio
void generar ( double v[] , const int n , const double d , const double h ) {
	time_t semilla = time(nullptr);	// tiempo actual como semilla
	srand(semilla);					// Inicializa el generador de
				// núms.pseudoaleatorios
	for ( int i = 0; i < n ; i++ ) {
		// Asigna a v [i] un pseudoaleatorio del intervalo [d, h]
		v[i] = (h - d) * ((double)rand() / (double)RAND_MAX) + d;
	}
}
