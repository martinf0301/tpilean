// #include <iostream>
// #include "sudoku.h"
//
// using namespace std;
//
// void sudoku_print(Tablero t) {
// 	cout << "-------------------";
// 	cout << endl;
// 	for (int i = 0; i < 9; i++) {
// 		cout << "|";
// 		for (int j = 0; j < 9; j++) {
// 			if (t[i][j] == 0) {
// 				cout << " ";
// 			} else {
// 				cout << t[i][j];
// 			}
// 			cout << "|";
// 		}
// 		cout << endl;
// 		if (i == 8) {
// 			cout << "+-+-+-+-+-+-+-+-+-+";
// 		} else {
// 			cout << "-------------------";
// 		}
// 		cout << endl;
// 	}
// }
//
// bool sudoku_esCeldaVacia(Tablero t, int f, int c) {
// 	return t[f][c] == 0;
// }

// void sudoku_vaciarTablero(Tablero t) {
// 	int i = 0;
// 	int j = 0;
// 	while (i < 9) {
// 		while(j < 9) {
// 			t[i][j] = 0;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int sudoku_nroDeCeldasVacias(Tablero t) {
// 	int i = 0;
// 	int j = 0;
// 	int acum = 0;
// 	while (i < 9) {
// 		while (j < 9) {
// 			if (t[i][j] == 0) {
// 				acum++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return acum;
// }

// int sudoku_primerCeldaVaciaFila(Tablero t) {
// 	int i = 0;
// 	int j = 0;
// 	bool lean = false;
// 	while(i < 9 && lean == false) {
// 		while(j < 9 && lean == false) {
// 			if (t[i][j] == 0) {
// 				lean = true;
// 			}
// 		}
// 	}
//
// 	return i;
// }

// int sudoku_primerCeldaVaciaColumna(Tablero t) {
// 	int i = 0;
// 	int j = 0;
// 	bool lean = false;
// 	while(i < 9 && lean == false) {
// 		while(j < 9 && lean == false) {
// 			if (t[i][j] == 0) {
// 				lean = true;
// 			}
// 		}
// 	}
//
// 	return j;
// }

// int sudoku_valorEnCelda(Tablero t, int f, int c) {
// 	return t[f][c];
// }

// void sudoku_llenarCelda(Tablero t, int f, int c, int v) {
// 	t[f][c] = v;
// }

// void sudoku_vaciarCelda(Tablero t, int f, int c) {
// 	t[f][c] = 0;
// }

// bool sudoku_esTableroValido(Tablero t) {
// 	int i = 0;
// 	int j = 0;
// 	int soyCero = 0;
// 	while(i < 9) {
// 		while(j < 9) {
// 			if (t[i][j] > 9) {
// 				soyCero++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return soyCero == 0;
// }

bool sudoku_esTableroParcialmenteResuelto(Tablero t) {
	// COMPLETAR
	return false;
}
// func auxiliARHHGGG

// bool sudoku_sonRegionesParcialmenteResueltas(Tablero t) {
// 	int result = 0;
//
// 	for(int i = 0; i < 9; i = i + 3) {
// 		for(int j = 0; j < 9; j = j + 3) {
// 			int subArray[9];
// 			int pos = 0;
// 			for(int k = i; k < i + 3; k++) {
// 				for(int l = k; l < k + 3; l++) {
// 					subArray[pos] = t[k][l];
// 					pos++;
// 				}
// 			}
// 			result += sudoku_cantidadRepetidosRegion(subArray);
// 		}
// 	}
// 	return result;
// }
//
// int sudoku_cantidadRepetidosRegion(int arr[]) {
// 	int i = 0;
// 	int j = 0;
// 	int res = 0;
// 	while(i < 9) {
// 		while(j < 9) {
// 			if(arr[i] == arr[j]) {
// 				res++;
// 			}
// 			j++;
// 		}
// 		i++;
//
// 	}
// 	return res;
// }

bool sudoku_esTableroTotalmenteResuelto(Tablero t) {

	return -1;
}

bool sudoku_esSubTablero(Tablero t0, Tablero t1) {
	// COMPLETAR
	return false;
}


bool sudoku_resolver(Tablero t) {
	// COMPLETAR
	return false;
}

bool sudoku_resolver(Tablero t, int& count) {
	// COMPLETAR
	return false;
}
