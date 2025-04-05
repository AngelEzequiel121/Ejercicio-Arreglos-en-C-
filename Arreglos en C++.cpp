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
void marcarDia() { //opcion para marcar los dias si no tenemos habitos agregados la funcion if nos devolvera lo siguiente
    if (total == 0) {
        cout << "Primero agregue al menos un habito.\n";
        return;
    }

    int dia; // esta variable es donde indicamos el dia que queremos marcar como cumplido nuestro habito si el dia no es del 1 al 7 muestra lo siguiente
    cout << "Dia (1-7): ";
    cin >> dia;
    if (dia < 1 || dia > 7) {
        cout << "Dia invalido.\n";
        return;
    }
    dia--;

    for (int i = 0; i < total; i++) {
        char hecho; // esta funcion char nos sirve para ingresar nuestra respuesta de un caracter en este caso s y n que significan si o no
        cout << " ¿Cumpliste '" << habitos[i] << "'? (s/n): ";
        cin >> hecho;
        registro[i][dia] = (hecho == 's' || hecho == 'S') ? 1 : 0;
    }
}

