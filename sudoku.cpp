#include <iostream>
using namespace std;

typedef int Tablero[9][9];

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
  static int celda [2] = {-1,-1};
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

// start funciones auxiliares para esTableroParcialmenteResuelto

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

bool sudoku_esSubTablero(Tablero t0, Tablero t1) {
	int celdasDiferentes = 0;
	for(int i = 0; i < 9 && celdasDiferentes == 0; i++){
		for(int j = 0; j < 9 && celdasDiferentes == 0; j++){
			if(t0[i][j] != 0 && (t0[i][j] != t1[i][j])){
				celdasDiferentes++;
			}
		}
	}
	return celdasDiferentes == 0;
}

void copiarTablero(Tablero t, Tablero& s){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			s[i][j] = t[i][j];
		}
	}
}
