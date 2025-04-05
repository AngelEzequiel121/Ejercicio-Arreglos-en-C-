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
void mostrar() { // aca mostramos el resumen de los habitos y cuantos dias los cumplimos si no hay habitos muestra lo siguiente
    if (total == 0) {
        cout << "No hay habitos agregados.\n";
        return;
    }

    cout << "\nResumen de habitos:\n";
    for (int i = 0; i < total; i++) { // este ciclo for muestra el resumen de todos los habitos registrados y que dias se cumplieron
        int suma = 0;
        for (int j = 0; j < DIAS; j++) suma += registro[i][j];
        cout << habitos[i] << ": " << suma << "/7 dias cumplidos\n";
    }
}

int main() {
    int op;
    do {
        cout << "\n1. Agregar habito\n2. Registrar dia\n3. Ver resumen\n4. Salir\nOpcion: "; // aca el bucle do while nos muestra el menu mientras no marquemos un numero que no sea 1 2 3 o 4
        cin >> op;
        switch (op) {
            case 1: agregarHabito(); break;
            case 2: marcarDia(); break;
            case 3: mostrar(); break;
            case 4: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida.\n";
        }
    } while (op != 4);
    return 0;
}

