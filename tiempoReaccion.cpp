# include <iostream>
# include <stdlib.h>
# include <ctime>

using namespace std;

int main(int argc, char* argv[]) {
	int iteraciones = 1;
	if (argc > 1) {
		int iteraciones =  atoi(argv[1]);
		for (int i = 1; i <= iteraciones; i++) {
			cout << endl;
			cout << i << ")Pulse la tecla de fin de linea, por favor ...";
			clock_t T0 = clock ();
			cin.ignore();
			clock_t Ti = clock ();
			cout << "Su tiempo de reaccion ha sido de " << fixed << float(Ti-T0) / CLOCKS_PER_SEC << "segundos" << endl;
		}
	}
	cout << "1)Pulse la tecla de fin de linea, por favor ...";
	clock_t T0 = clock ();
	cin.ignore();
	clock_t Ti = clock ();
	cout << "Su tiempo de reaccion ha sido de " << float(Ti-T0) / CLOCKS_PER_SEC << "segundos" << endl;
	
	return 0;
}
