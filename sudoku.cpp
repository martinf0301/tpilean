#include <iostream>
#include "sudoku.h"

using namespace std;

void sudoku_print(Tablero t) {
	cout << "-------------------";
	cout << endl;
	for (int i = 0; i < 9; i++) {
		cout << "|";
		for (int j = 0; j < 9; j++) {
			if (t[i][j] == 0) {
				cout << " ";
			} else {
				cout << t[i][j];
			}
			cout << "|";
		}
		cout << endl;
		if (i == 8) {
			cout << "+-+-+-+-+-+-+-+-+-+";
		} else {
			cout << "-------------------";
		}
		cout << endl;
	}
}

bool sudoku_esCeldaVacia(Tablero t, int f, int c) {
	return t[f][c] == 0;
}

void sudoku_vaciarTablero(Tablero t) {
	int i = 0;
	int j = 0;
	while (i < 9) {
		while(j < 9) {
			t[i][j] = 0;
			j++;
		}
		i++;
	}
}

int sudoku_nroDeCeldasVacias(Tablero t) {
	int i = 0;
	int j = 0;
	int acum = 0;
	while (i < 9) {
		while (j < 9) {
			if (t[i][j] == 0) {
				acum++;
			}
			j++;
		}
		i++;
	}
	return acum;
}

int sudoku_primerCeldaVaciaFila(Tablero t) {
	int i = 0;
	int j = 0;
	bool lean = false;
	while(i < 9 && lean == false) {
		while(j < 9 && lean == false) {
			if (t[i][j] == 0) {
				lean = true;
			}
		}
	}
	return i;
}

int sudoku_primerCeldaVaciaColumna(Tablero t) {
	int i = 0;
	int j = 0;
	bool lean = false;
	while(i < 9 && lean == false) {
		while(j < 9 && lean == false) {
			if (t[i][j] == 0) {
				lean = true;
			}
		}
	}
	return j;
}

int sudoku_valorEnCelda(Tablero t, int f, int c) {
	return t[f][c];
}

void sudoku_llenarCelda(Tablero& t, int f, int c, int v) {
	t[f][c] = v;
}

void sudoku_vaciarCelda(Tablero& t, int f, int c) {
	t[f][c] = 0;
}

bool sudoku_esTableroValido(Tablero t) {
	int i = 0;
	int j = 0;
	int soyCero = 0;
	while(i < 9) {
		while(j < 9) {
			if (t[i][j] > 9) {
				soyCero++;
			}
			j++;
		}
		i++;
	}
	return soyCero == 0;
}

bool sudoku_esTableroParcialmenteResuelto(Tablero t) {
	// COMPLETAR
	return false;
}

bool sudoku_esFilaParcialmenteResuelto(Tablero t){
	int result = 0;
	for (i = 0; i < 9; i++){
		int subArray[9];
		for (j = 0; j < 9; j++){
			subArray[j] = t[i][j];
		}
		result = result + noHayRepetidos(subArray);
	}
	return (result == 0);
}

bool sudoku_esColumnaParcialmenteResuelto(Tablero t){
	int result = 0;
	for (j = 0; j < 9; j++){
		int subArray[9];
		for (i = 0; i < 9; i++){
			subArray[i] = t[i][j];
		}
		result = result + noHayRepetidos(subArray);
	}
	return (result == 0);
}

bool sudoku_sonRegionesParcialmenteResueltas(Tablero t) {
	int result = 0;

	for(int i = 0; i < 9; i = i + 3) {
		for(int j = 0; j < 9; j = j + 3) {
			int subArray[9];
			int pos = 0;
			for(int k = i; k < i + 3; k++) {
				for(int l = k; l < k + 3; l++) {
					subArray[pos] = t[k][l];
					pos++;
				}
			}
			result += sudoku_cantidadRepetidosRegion(subArray);
		}
	}
	return result;
}

int noHayRepetidos(int l[]){
	int result = 0;
	for (i = 0; i < 9; i++){
		if (l(i) != 0){
			for (j = 0; j < 9; j++){
				if (i != j && l[i] == l[j]){
					result++;
				}
			}
		}
	}
	return result;
}

int sudoku_cantidadRepetidosRegion(int arr[]) {
	int i = 0;
	int j = 0;
	int res = 0;
	while(i < 9) {
		while(j < 9) {
			if(arr[i] == arr[j]) {
				res++;
			}
			j++;
		}
		i++;

	}
	return res;
}

bool sudoku_esTableroTotalmenteResuelto(Tablero t) {
	// COMPLETAR
	return false;
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

bool sudoku_resolver(Tablero t){
	Tablero sudokus[1000];
	sudokus[0] = t;
	int count = 0;
	sudoku_resolverAux(t, sudokus, count, count);
}

bool sudoku_resolverAux(Tablero t, Tablero sudokus[], int count1, int count2){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (t[i][j] == 0){
				for (int x = 1; x < 10; x++){
					sudoku_llenarCelda(t, i, j, x);
					if (sudoku_esTableroParcialmenteResuelto(t) && tableroNoRepetido(t, sudokus)){
						count1++;
						sudokus[count1] = t;
						count2 = count1;
						break;
					}
					if (x == 9){
						sudoku_resolverAux(sudokus[count2 - 1], sudokus, count1, count2 - 1);
					}
				}
			}
		}
	}
}

bool tableroNoRepetido(Tablero t, Tablero s[]){
	int result = 0;
	for (int i = 0; i < sizeof(s); i++){
		if (sudoku_esSubTablero(t, s[i])){
			result++;
		}
	}
	return result == 0;
}
