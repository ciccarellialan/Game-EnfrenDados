#include <iostream>
using namespace std;
#include <ctime>
#include "funciones.h"


//----------------------    MAIN    -------------------------------------------------------------------

int main()
{
    srand(time(nullptr));
    int opcion;
    int puntajeMaximoPrograma = 0;
    string jugadorPuntajeMaximoPrograma = "";

    do {
        Menu();

        cout << endl;

        cout << "Elige una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 0:
                cout << "Saliendo del juego..." << endl;
                break;
            case 1:
                Jugar (puntajeMaximoPrograma, jugadorPuntajeMaximoPrograma);
                break;
            case 2:
                Reglas ();
                break;
            case 3:
                Creditos ();
                break;
            case 4:
                Estadisticas (puntajeMaximoPrograma, jugadorPuntajeMaximoPrograma);
                break;
            default:
                cout << "Opcion no valida (elegir unicamente 1-4)." << endl;
        }
    } while(opcion > 0 && opcion <= 4);
        return 0;
}


