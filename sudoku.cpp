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
	return (sudoku_esTableroValido(t) && sudoku_esFilaParcialmenteResuelto(t) && sudoku_esColumnaParcialmenteResuelto(t) && sudoku_sonRegionesParcialmenteResueltas(t));
}

// start funciones auxiliares para esTableroParcialmenteResuelto

bool sudoku_esFilaParcialmenteResuelto(Tablero t){
	int result = 0;
	for (int i = 0; i < 9; i++){
		result += cantidadRepetidos(t[i]);
	}
	return (result == 0);
}

bool sudoku_esColumnaParcialmenteResuelto(Tablero t){
	int result = 0;
	for (int j = 0; j < 9; j++){
		int subArray[9];
		for (int i = 0; i < 9; i++){
			subArray[i] = t[i][j];
		}
		result += cantidadRepetidos(subArray);
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
			result += cantidadRepetidos(subArray);
		}
	}
	return (result == 0);
}

int cantidadRepetidos(int l[]){
	int result = 0;
	for (int i = 0; i < 9; i++){
		if (l[i] != 0){
			for (int j = 0; j < 9; j++){
				if (i != j && l[i] == l[j]){
					result++;
				}
			}
		}
	}
	return result;
}

//end funciones auxiliares para esTableroParcialmenteResuelto

bool sudoku_esTableroTotalmenteResuelto(Tablero t) {
	return (sudoku_esTableroParcialmenteResuelto(t) && sudoku_noHayCeldasVacias(t));
}
//start funciones auxiliares para esTableroTotalmenteResuelto

bool sudoku_noHayCeldasVacias(Tablero t) {
	int counter = 0;
	for(int i = 0; i < 9 && counter == 0; i++) {
		for(int j = 0; j < 9 && counter == 0; j++) {
			if(t[i][j] == 0) {
				counter++;
			}
		}
	}
	return counter == 0;
}

//end funciones auxiliares para esTableroTotalmenteResuelto

bool sudoku_esSubTablero(Tablero t0, Tablero t1) {
	int soyCero = 0;
	for(int i = 0; i < 9 && soyCero == 0; i++) {
		for(int j = 0; j < 9 && soyCero == 0; j++) {
			if(t0[i][j] != 0 && t0[i][j] != t1[i][j]) {
				soyCero++;
			}
		}
	}
	return soyCero == 0;
}

bool sudoku_resolver(Tablero& t){
    Tablero sudokus[1000];
    copiarTablero(t, sudokus[0]);
	int count = 0;
	sudoku_resolverAux(t, sudokus, count, count);
	return sudoku_resolverAux(t, sudokus, count, count);
}

//start funciones auxiliares para resolver

bool sudoku_resolverAux(Tablero& t, Tablero (&sudokus)[], int& count1, int& count2){
	bool result = true;
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (t[i][j] == 0){
				for (int x = 1; x < 10; x++){
					sudoku_llenarCelda(t, i, j, x);
					if (sudoku_esTableroParcialmenteResuelto(t) && tableroNoRepetido(t, sudokus)){
						count1++;
						copiarTablero(t, sudokus[count1]);
						count2 = count1;
						break;
					}
					if (x == 9){
						if (count2 == 0){
							result = false;
							break;
						}
						else{
						sudoku_resolverAux(sudokus[count2 - 1], sudokus, count1, count2 - 1);
						}
					}
				}
			}
		}
	}
	return true;
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

void copiarTablero(Tablero t, Tablero& s){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			s[i][j] = t[i][j];
		}
	}
}

//end funciones auxiliares para resolver

bool sudoku_resolver(Tablero t, int& count){
	return false;
}

