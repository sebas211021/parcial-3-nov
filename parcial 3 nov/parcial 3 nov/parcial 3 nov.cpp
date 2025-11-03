#include <iostream>
#include <string>
using namespace std;

// Función para calcular el total ganado
int calcularTotal(int distancia[], int costo[], int numViajes) {
    int total = 0;
    for (int i = 0; i < numViajes; i++) {
        total += distancia[i] * costo[i];
    }
    return total;
}

// Función para calcular el promedio de distancia
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
        cout << "\nCONDUCTOR #" << i + 1 << endl;
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
            cout << "\nViaje #" << j + 1 << endl;
            cout << "Distancia (km): ";
            cin >> distancia[j];
            cout << "Costo por km: ";
            cin >> costo[j];
        }

        totalGanado[i] = calcularTotal(distancia, costo, numViajes);
        promedioDistancia[i] = calcularPromedio(distancia, numViajes);
    }

    cout << "\nRESULTADOS\n";
    for (int i = 0; i < cantidadConductores; i++) {
        cout << "\nConductor: " << nombres[i] << endl;
        cout << "Total ganado: $" << totalGanado[i] << endl;
        cout << "Promedio distancia: " << promedioDistancia[i] << " km" << endl;
    }

    return 0;
}
