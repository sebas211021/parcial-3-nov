#include <iostream>
#include <string>
using namespace std;


int calcularTotal(int distancia[], int costo[], int numViajes) {
    int total = 0;
    for (int i = 0; i < numViajes; i++) {
        total += distancia[i] * costo[i];
    }
    return total;
}


int calcularPromedio(int distancia[], int numViajes) {
    int suma = 0;
    for (int i = 0; i < numViajes; i++) {
        suma += distancia[i];
    }
    return suma / numViajes;
}

int main() {

    int cantidadConductores;
    cout << "Ingrese la cantidad de conductores (maximo 10): ";
    cin >> cantidadConductores;

    if (cantidadConductores > 10) {
        cout << "Error: maximo 10 conductores permitidos." << endl;
        return 0;
    }

    string nombres[10];
    int totalGanado[10];
    int promedioDistancia[10];

    for (int i = 0; i < cantidadConductores; i++) {
        cout << "\n=== CONDUCTOR #" << i + 1 << " ===" << endl;
        cout << "Nombre: ";
        cin >> nombres[i];

        int numViajes;
        cout << "Ingrese el numero de viajes realizados (maximo 10): ";
        cin >> numViajes;

        if (numViajes > 10) {
            cout << "Error: maximo 10 viajes permitidos." << endl;
            return 0;
        }

        int distancia[10];
        int costo[10];

        for (int j = 0; j < numViajes; j++) {
            cout << "\nViaje #" << j + 1 << ": " << endl;
            cout << "   Distancia (km): ";
            cin >> distancia[j];
            cout << "   Costo por km ($): ";
            cin >> costo[j];
        }

        totalGanado[i] = calcularTotal(distancia, costo, numViajes);
        promedioDistancia[i] = calcularPromedio(distancia, numViajes);
    }


    cout << "\n_______ historial de viajes   ________" << endl;
    cout << "Conductor\tTotal Ganado ($)\tPromedio Distancia (km)" << endl;
    cout << "-----------------------------------------------------------" << endl;

    for (int i = 0; i < cantidadConductores; i++) {
        cout << nombres[i] << "\t\t" << totalGanado[i] << "\t\t"
            << promedioDistancia[i] << endl;
    }

    int mayor = totalGanado[0];
    int indiceMayor = 0;

    for (int i = 1; i < cantidadConductores; i++) {
        if (totalGanado[i] > mayor) {
            mayor = totalGanado[i];
            indiceMayor = i;
        }
    }

    cout << "\nEl conductor con mayor ingreso fue: "
        << nombres[indiceMayor] << " con $" << mayor << endl;
    cout << "--------------------------------------------------------------" << endl;

    return 0;
}