#ifndef SUDOKU_H_
#define SUDOKU_H_

/**
 * Definicion de Tablero
 */
typedef int Tablero[9][9];

/**
 * Indica si la celda en la posicion <f,c> esta vacia
 */
bool sudoku_esCeldaVacia(Tablero t, int f, int c);

/**
 * Elimina todas las celdas del tablero.
 */
void sudoku_vaciarTablero(Tablero t);

/**
 * Retorna la cantidad de celdas vacias
 */
int sudoku_nroDeCeldasVacias(Tablero t);

/**
 * Dado un tablero con al menos una celda vacia, retorna la fila de la primer celda vacia encontrada.
 */
int sudoku_primerCeldaVaciaFila(Tablero t);

/**
 * Dado un tablero con al menos una celda vacia, retorna la columna de la primer celda vacia encontrada.
 */
int sudoku_primerCeldaVaciaColumna(Tablero t);

/**
 * Requiere que la celda en la posicion <f,c> no este vacia.
 * Retorna el valor en la celda n la posicion <f,c>
 */
int sudoku_valorEnCelda(Tablero t, int f, int c);

/**
 * Actualiza el valor de la celda en la posicion <f,c>
 */
void sudoku_llenarCelda(Tablero t, int f, int c, int v);

/**
 * Elimina el valor de la celda en la posicion <f,c>.
 * La celda queda vacia.
 */
void sudoku_vaciarCelda(Tablero t, int f, int c);

/**
 * Indica si un tablero es valida.
 * Un tablero es valido cuando:
 * - es una matriz de 9x9
 * - todos sus valores son enteros del 0 al 9.
 */
bool sudoku_esTableroValido(Tablero t);

/**
 * Indica si un tablero esta parcialmente resuelto.
 * Un tablero esta parcialmente resuelto si:
 * - es un tablero valido
 * - ninguna fila tiene un numero repetido
 * - ninguna columna tiene un numero repetido
 * - ninguna de las 9 regiones tiene un numero repetido
 */

bool sudoku_esFilaParcialmenteResuelto(Tablero t);


bool sudoku_esColumnaParcialmenteResuelto(Tablero t);


int noHayRepetidos(int l[]);


bool sudoku_esTableroTotalmenteResuelto(Tablero t);

/**
 * Indica que un tablero esta contendio en otro tablero.
 * Es decir, toda celda definida del tablero t0 tiene el mismo valor en el tablero t2.
 */
bool sudoku_esSubTablero(Tablero t0, Tablero t1);

/**
 * Dado un tablero valido, retorna true si el tablero puede ser resuelto
 * (y modifica el tablero con la solucion).
 * Si el tablero no puede ser resuelto, retorna false y no modifica
 * el tablero.
 */
bool sudoku_resolver(Tablero t);


bool sudoku_resolverAux(Tablero t, Tablero sudokus[], int count1, int count2);


bool tableroNoRepetido(Tablero t, Tablero s[]);

/**
 * Idem a la operacion sudoku_resolver, pero almacena en count la cantidad de operaciones
 * de vaciado y llenado de celdas.
 */
bool sudoku_resolver(Tablero t, int& count);

/**
 * Imprime el tablero actual por pantalla.
 */
void sudoku_print(Tablero t);

#endif /* SUDOKU_H_ */

/**bool sudoku_esFilaParcialmenteResuelto(Tablero t){
	int i = 0;
	int j = 0;
	int c = 0;
	int x = 0;
	while (i < 9){
		while (j < 9){
			if (t[i][j] != 0){
				while (c < 9){
					if (j != c){
						if (t[i][j] == t[i][c]){
							x++;
							c++;
						}
						else {
							c++;
						}
					}
				}
			}
			else{
				j++;
			}
		}
		i++;
	}
	return x == 0;
}

bool sudoku_esColumnaParcialmenteResuelto(Tablero t){
	int i = 0;
	int j = 0;
	int f = 0;
	int x = 0;
	while (j < 9){
		while (i < 9){

			if (t[i][j] != 0){
				while (f < 9){
					if (j != f){
						if (t[i][j] == t[f][j]){
							x++;
							f++;
						}
						else {
							f++;
						}
					}
				}
			}
			else{
				i++;
			}
		}
		j++;
	}
	return x == 0;
}
*/
