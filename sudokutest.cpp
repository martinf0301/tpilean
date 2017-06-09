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

//vaciar tablero
void sudoku_vaciarTablero(Tablero t) {
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

// int * primerCeldaVacia(Tablero t) {
//   static int celda [2] = {-1,-1};
//   bool primera = true;
//   for (int i = 0; i < 9; i++) {
//     for (int j = 0; j < 9; j++) {
//       if (t[i][j] == 0 && primera == true) {
//         celda[0] = i;
//         celda[1] = j;
//         primera = false;
//       }
//     }
//   }
//   return celda;
// }

// int sudoku_primerCeldaVaciaFila(Tablero t) {
// 	int *fila;
//   fila = primerCeldaVacia(t);
//   return fila[0];
// }

// int sudoku_primerCeldaVaciaColumna(Tablero t) {
// 	int *columna;
//   columna = primerCeldaVacia(t);
//   return columna[1];
// }

int sudoku_primerCeldaVaciaFila(Tablero t) {
	int fila = -1;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (t[i][j] == 0 && fila == -1) {
        fila = i;
      }
    }
  }
  return fila;
}

int sudoku_primerCeldaVaciaColumna(Tablero t) {
	int columna = -1;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (t[i][j] == 0 && columna == -1) {
        columna = i;
      }
    }
  }
  return columna;

int sudoku_valorEnCelda(Tablero t, int f, int c) {
	return t[f][c];
}

void sudoku_llenarCelda(Tablero t, int f, int c, int v) {
	t[f][c] = v;
}

void sudoku_vaciarCelda(Tablero t, int f, int c) {
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

void copiarTablero(Tablero t, Tablero s){
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			s[i][j] = t[i][j];
		}
	}
}

bool resolviendo(Tablero t){

		if (sudoku_esTableroTotalmenteResuelto(t))
			return true;
		if (sudoku_esTableroParcialmenteResuelto(t) != true)
			return false;

		for (int f = 0; f < 9; f++) {
			for (int c = 0; c < 9; c++) {
				if (t[f][c] == 0) {
					for (int v = 1; v < 10; v++) {
						sudoku_llenarCelda(t, f, c, v);

						system("clear");
						sudoku_print(t);

						if (resolviendo(t) == true) {
							return true;
						} else {
							sudoku_vaciarCelda(t, f, c);
						}
					}
					if (t[f][c] == 0) {
						return false;
					}
				}
			}
		}
		return sudoku_esTableroTotalmenteResuelto(t);
}

bool sudoku_resolver(Tablero t){
	Tablero tableroTemp;
	copiarTablero(t,tableroTemp);
	if (resolviendo(t) == false)
		copiarTablero(tableroTemp, t);

	return (sudoku_esTableroTotalmenteResuelto(t));
}

int main(int argc, char const *argv[]) {

	Tablero test2 =  {{8,3,5,4,1,6,9,2,7},
 									{2,9,6,8,5,7,4,3,1},
 									{4,1,7,2,9,3,6,5,8},
 									{5,6,9,1,3,4,7,8,2},
 									{1,2,3,6,7,8,5,4,9},
 									{7,4,8,5,2,9,1,6,3},
 									{6,5,2,7,8,1,3,9,4},
 									{9,8,1,3,4,5,2,7,6},
 									{3,7,4,9,6,2,8,1,5}};

  Tablero test =  {{0,0,5,4,1,6,9,2,7},
 									{2,9,6,8,5,7,4,3,1},
 									{0,1,7,2,9,3,6,5,8},
 									{5,6,0,1,3,4,0,8,2},
 									{1,2,3,6,7,8,5,4,9},
 									{7,4,8,0,2,9,1,6,3},
 									{6,5,0,7,8,1,3,0,4},
 									{9,8,1,3,4,5,2,0,6},
 									{0,7,4,9,6,2,8,1,5}};

	Tablero testguacho =  {{0,0,0,0,0,0,0,0,0},
												{2,9,0,8,5,7,4,3,1},
												{0,1,7,2,9,3,6,5,0},
												{5,6,0,1,3,4,0,8,2},
												{0,2,3,6,0,0,5,4,9},
												{7,4,8,0,2,9,1,0,3},
												{6,5,0,7,8,1,3,0,4},
												{9,8,1,3,0,5,2,0,6},
												{0,0,4,9,6,2,0,0,7}};

	Tablero testguacho0 =  {{9,8,7,6,5,4,3,2,1},
												{0,0,0,0,0,3,0,8,5},
												{0,0,1,0,2,0,0,0,0},
												{0,0,0,5,0,7,0,0,0},
												{0,0,4,0,0,0,1,0,0},
												{0,9,0,0,0,0,0,0,0},
												{5,0,0,0,0,0,0,7,3},
												{0,0,2,0,1,0,0,0,0},
												{0,0,0,0,4,0,0,0,9}};

	sudoku_print(testguacho);
	sudoku_resolver(testguacho);
	std::cout << "" << '\n';
	sudoku_print(testguacho);
	std::cout << "" << '\n';
	std::cout << "Es tablero valido " << sudoku_esTableroValido(testguacho) << '\n';
	std::cout << "Es tablero parcialmente resuelto " << sudoku_esTableroParcialmenteResuelto(testguacho) << '\n';
	std::cout << "Es tablero resuelto " << sudoku_esTableroTotalmenteResuelto(testguacho) << '\n';
	std::cout << "Celdas vacias " << sudoku_nroDeCeldasVacias(testguacho) << '\n';
  return 0;
}
