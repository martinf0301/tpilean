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

void sudoku_vaciarTablero(Tablero &t) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
			t[i][j] = 0;
		}
	}
}

int sudoku_nroDeCeldasVacias(Tablero t) {
  int total = 0;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (t[i][j] == 0) {
        total++;
      }
    }
  }
  return total;
}

int * primerCeldaVacia(Tablero t) {
  static int celda [2] = {0,0};
  bool primera = true;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (t[i][j] == 0 && primera == true) {
        celda[0] = i;
        celda[1] = j;
        primera = false;
      }
    }
  }
  return celda;
}

int sudoku_primerCeldaVaciaFila(Tablero t) {
	int *fila;
  fila = primerCeldaVacia(t);
  return fila[0];
}

int sudoku_primerCeldaVaciaColumna(Tablero t) {
	int *columna;
  columna = primerCeldaVacia(t);
  return columna[1];
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
  bool valido = true;
	for (int i = 0; i < 9; i++) {
	  for (int j = 0; j < 9; j++) {
	    if (t[i][j] > 9) {
	      valido = false;
	    }
	  }
	}
	return valido;
}

//start funciones para esTableroParcialmenteResuelto

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
				for(int l = j; l < j + 3; l++) {
					subArray[pos] = t[k][l];
					pos++;
				}
			}
			result += cantidadRepetidos(subArray);
		}
	}
	return (result == 0);
}

bool sudoku_esTableroParcialmenteResuelto(Tablero t) {
	return (sudoku_esTableroValido(t) &&
          sudoku_esFilaParcialmenteResuelto(t) &&
          sudoku_esColumnaParcialmenteResuelto(t) &&
          sudoku_sonRegionesParcialmenteResueltas(t));
}

//end funciones auxiliares para esTableroParcialmenteResuelto

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

bool sudoku_esTableroTotalmenteResuelto(Tablero t) {
	return (sudoku_esTableroParcialmenteResuelto(t) && sudoku_noHayCeldasVacias(t));
}

//end funciones auxiliares para esTableroTotalmenteResuelto

bool sudoku_esSubTablero(Tablero t0, Tablero t1) {
	int esSubTablero = true;
	for(int i = 0; i < 9 && esSubTablero; i++){
		for(int j = 0; j < 9 && esSubTablero; j++){
			if(t0[i][j] != 0 && (t0[i][j] != t1[i][j])){
				esSubTablero = false;
			}
		}
	}
	return esSubTablero;
}

bool sudoku_resolver(Tablero& t){
    Tablero sudokus[1000];
    copiarTablero(t, sudokus[0]);
	int count1 = 0;
	int count2 = 0;
	sudoku_resolverAux(t, sudokus, count1, count2);
	return sudoku_resolverAux(t, sudokus, count1, count2);
}

//start funciones auxiliares para resolver

bool sudoku_resolverAux(Tablero& t, Tablero sudokus[], int& count1, int& count2){
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
						} else {
						sudoku_resolverAux(sudokus[(count2 - 1)], sudokus, count1, count2 - 1);
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
	for (int i = 0; i < 1000; i++){
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

//bool sudoku_resolver(Tablero t, int& count){
//	return false;
//}

