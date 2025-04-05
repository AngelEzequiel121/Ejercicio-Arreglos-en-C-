#include <iostream>
using namespace std;

const int CAN_HABITOS = 5; 
const int DIAS = 7;

string habitos[CAN_HABITOS]; // se guardara los habitos que agreguemos
int registro[CAN_HABITOS][DIAS];
int total = 0;

void agregarHabito() {
    if (total >= CAN_HABITOS) { // esta parte calcula cuanto habitos hemos agregado y si no alcanzamos el max que son 5
        cout << "Maximo de habitos alcanzado.\n";
        return;
    }
    cin.ignore(); // Limpieza de buffer al elegir otra opcion
    cout << "Nombre del habito: "; 
    getline(cin, habitos[total]); // aca se nos guarda nuestro habito con espacios
    for (int i = 0; i < DIAS; i++) { //en este ciclo for nos repite la cantidad maxima de dias que son 7
        registro[total][i] = 0;
    }
    total++;
}


