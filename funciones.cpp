#include <iostream>
#include "funciones.h"
#include "rlutil.h"
using namespace std;
using namespace rlutil;


//DEFINIMOS LAS FUNCIONES

//-----------------------------------   Definicion de FUNCIONES (MENU, JUGAR, REGLAS, CREDITOS, ESTADISTICAS)   -----------------------------------------------

//FUNCION MENU
void Menu() {

  setColor (YELLOW);
  cout << R"(
____________________________________        ________________________________________________
  _______  __    _  ______  _______ \      / ______   _    _   ____    / _ \             +
  \  ____\ \ \  / \ \   __\ \  ___ \ \    / /  ____/ / \  / / / __ \  (_( ) ) _|_     |
   \ \___   \ \/   \ \ \__   \ \__\ \ \  / / /__    /   \/ / / / / / / / / /   |   ___|___
    \  __\   \      \ \  _\   \  _  /  \/ /  __/   /      / / / / / / /_/ /           |
     \ \_____ \   /\ \ \ \     \ \ \ \   / /____  / /\   / / /_/ / / _ / (__      +   |
      \______\ \_/  \_\ \_\     \_\ \_\ /______/ /_/  \_/ |_____/ /_/ |____/      _|_
                                                                                   |

    )" << endl;

  setColor (BROWN);
  cout << "---------------------------- E N F R E N D A D O S ----------------------" << endl;
  setColor (LIGHTCYAN);
  cout << "-------------------------------------------------------------------------" << endl;
  cout << "                               1 = JUGAR                                 " << endl;
  cout << "             2 = REGLAS                            3 = CREDITOS          " << endl;
  cout << "                                4 = ESTADISTICAS                         " << endl;
  cout << "-------------------------------------------------------------------------" << endl;
  setColor(RED);
  cout << "0 = SALIR" << endl;
  setColor (WHITE);
}


//FUNCION JUGAR
void Jugar (int &puntajeMaximo, string &jugadorPuntajeMaximo) {
    string comienzaPrimero,comienzaSegundo;
    string nombreJugador1;
    string nombreJugador2;
    int cantDadosJugadorInicial = 6; //Cantidad de DADOS
    int CantDadosJugadorSegundo = 6; //Cantidad de DADOS
    int PuntajeTotalJugadorInicial = 0;
    int PuntajeTotalJugadorSegundo = 0;


    setColor (LIGHTRED);
    cout << "Introducir el nombre del JUGADOR 01: ";
    cin >> nombreJugador1;
    setColor(LIGHTBLUE);

    cout << "Introducir el nombre del JUGADOR 02: ";
    cin >> nombreJugador2;
    setColor (WHITE);
    cout << endl;

    comienzaPrimero = quienComienza(nombreJugador1,nombreJugador2);   /// Llamamos funcion para designar quien comienza
    if(comienzaPrimero == nombreJugador1){
        comienzaSegundo = nombreJugador2;
    }else{
        comienzaSegundo = nombreJugador1;
    }

    //Asigna color según jugador
    int colorJugador1;
    int colorJugador2;

    if (comienzaPrimero == nombreJugador1) {
        colorJugador1 = LIGHTRED;
        colorJugador2= LIGHTBLUE;
    } else {
        colorJugador1= LIGHTBLUE;
        colorJugador2= LIGHTRED;
    }

    for (int i=1;i<=3;i++){ //FOR para 3 rondas

        setColor (LIGHTGREEN);
        cout << "RONDA " << i << ": "<< endl<< endl;
        setColor (WHITE);

        ///ACCEDO A (Jugador que va a jugar , puntaje del que juega , dados del que juega , dados del contrincante)
        int resultado1 = jugarRonda (comienzaPrimero,PuntajeTotalJugadorInicial,cantDadosJugadorInicial,CantDadosJugadorSegundo,colorJugador1);
        // Valido si se retorno el valor 10MIL, para que corte la ejecucion ya que GANAMOS!!!!
        if (resultado1 == 10000){
            break;
        }

        ///ACCEDO A (Jugador que va a jugar , puntaje del que juega , dados del que juega , dados del contrincante)
        int resultado2 =  jugarRonda (comienzaSegundo,PuntajeTotalJugadorSegundo,CantDadosJugadorSegundo,cantDadosJugadorInicial,colorJugador2);
        // Valido si se retorno el valor 10MIL, para que corte la ejecucion ya que GANAMOS!!!!
        if (resultado2 == 10000){
            break;
        }

    }
    cout << "El Jugador ";

    setColor (colorJugador1);
    cout << comienzaPrimero;
    setColor (WHITE);

    cout << " tiene: ";

    setColor (LIGHTGREEN);
    cout << PuntajeTotalJugadorInicial << " PUNTOS." << endl;
    setColor (WHITE);

    cout << "El Jugador ";

    setColor (colorJugador2);
    cout << comienzaSegundo;
    setColor (WHITE);

    cout << " tiene: ";

    setColor (LIGHTGREEN);
    cout << PuntajeTotalJugadorSegundo << " PUNTOS." << endl<< endl;
    setColor (WHITE);

    //Verificamos QUIEN GANO o si es EMPATE
    if (PuntajeTotalJugadorInicial > PuntajeTotalJugadorSegundo){

        cout << "El Jugador ";

        setColor (colorJugador1);
        cout << comienzaPrimero;

        setColor (YELLOW);
        cout << " es el GANADOR!!!"<< endl;

        //Verificaremos PUNTAJES MAXIMOS
        if (PuntajeTotalJugadorInicial >= puntajeMaximo){
            puntajeMaximo = PuntajeTotalJugadorInicial;
            jugadorPuntajeMaximo = comienzaPrimero;
        }

    }else if(PuntajeTotalJugadorInicial < PuntajeTotalJugadorSegundo){

        cout << "El Jugador ";

        setColor (colorJugador2);
        cout << comienzaSegundo;

        setColor (YELLOW);
        cout << " es el GANADOR!!!"<< endl;

        //Verificaremos PUNTAJES MAXIMOS
        if (PuntajeTotalJugadorSegundo >= puntajeMaximo){
            puntajeMaximo = PuntajeTotalJugadorSegundo;
            jugadorPuntajeMaximo = comienzaSegundo;
        }
    }else{
        cout << "Los Jugadores ";

        setColor (colorJugador1);
        cout << comienzaPrimero;

        setColor (WHITE);
        cout << " y ";

        setColor (colorJugador2);
        cout << comienzaSegundo;

        setColor (WHITE);
        cout << " tienen los mismos ";

        setColor (LIGHTGREEN);
        cout << "PUNTOS";

        setColor (WHITE);
        cout << "."<< endl;

        cout << "Se ha declarado un ";

        setColor (GREEN);
        cout << "EMPATE!!!"<< endl;
    }
}

//TIRADA PARA VER QUIEN COMIENZA

string quienComienza(string nombreJugador1, string nombreJugador2){

    int  tiradaJ1,tiradaJ2;
    string comienzaPrimero,comienzaSegundo;

    do{
        tiradaJ1 = tiradaDado6Caras();
        tiradaJ2 = tiradaDado6Caras();

        cout << endl;

        setColor (LIGHTRED);
        cout << nombreJugador1;
        setColor(WHITE);

        cout << " tira: ";
        setColor (LIGHTRED);
        cout << " [";
        setColor (WHITE);

        cout << tiradaJ1;

        setColor (LIGHTRED);
        cout << "] " << endl;
        setColor (WHITE);

        cout << endl;

        setColor (LIGHTBLUE);
        cout << nombreJugador2;
        setColor (WHITE);

        cout << " tira: ";
        setColor (LIGHTBLUE);
        cout << " [";
        setColor (WHITE);

        cout << tiradaJ2;

        setColor (LIGHTBLUE);
        cout << "] " << endl;
        setColor (WHITE);

        cout << endl;

        if (tiradaJ1 == tiradaJ2){
            cout << "Empate, se repite la tirada." << endl;
        }
    }while (tiradaJ1 == tiradaJ2);

    if(tiradaJ1 > tiradaJ2){
        setColor (LIGHTRED);
        comienzaPrimero = nombreJugador1;
        comienzaSegundo = nombreJugador2;
    }else{
        setColor (LIGHTBLUE);        comienzaPrimero = nombreJugador2;
        comienzaSegundo = nombreJugador1;
    }

    cout <<  endl <<comienzaPrimero;

    cout << " COMIENZA LA PARTIDA" << endl<< endl;

    cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
    setColor (WHITE);

    return comienzaPrimero;
}

//TIRADA DE DADOS
int tiradaDado6Caras(){
    return rand() % 6 + 1;
}

int tiradaDado12Caras (){
    return rand() % 12 + 1;
}

//   JUGAMOS CON LOS DADOS STOCK
int jugarRonda (string jugador, int &puntajeJugador, int &cantidadDadosStock,int &cantidadDadosContrincante, int colorJugador) {

    int colores[6] = { YELLOW, BROWN, BROWN, GREY, LIGHTGREEN, DARKGREY};

    int dadosStock[11] = {}; //INICIALIZAMOS TODO A 0

    for (int i=0;i<11;i++){ //Usamor el FOR para crear un numero ALEATORIO para cada INDICE
        dadosStock[i] = tiradaDado6Caras (); ///PARA FORZAR LOS 10MIL PUNTOS - inicializar la variable en 1;
    };

    bool dadoUsado[11] = {};//Inicializa todo en FALSE y esta BANDERA se usa para que no se REPITAN la impresion (se reemplaza por una "X")
    int tiradaObjetivo[2] = {tiradaDado12Caras (), tiradaDado12Caras()};   ///PARA FORZAR LOS 10MIL PUNTOS - inicializar la variable en {3,3};
    int opcion;
    int cantDadosElegidos = 0; // Se usa para que si es TIRADA EXITOSA, esa cantidad de dados se TRANSFERIRA a el contrincante.
    int numeroObjetivo = tiradaObjetivo[0] + tiradaObjetivo[1];/// PARA FORZAR LOS 10MIL PUNTOS - inicializar la variable en 6;  // DADOS OBJETIVO
    int sumaSeleccionada = 0; // Variable para ir SUMANDO los DADOS ELEGIDO
    int puntajeTotal = 0;   //Puntaje de esta RONDA

    //Cout que mostrara la tirada objetivo y valores de ambos dados D12
    cout << "Turno de ";

    setColor (colorJugador);
    cout << jugador << endl<< endl;
    setColor (WHITE);

    cout << "Stock Actual: ";

    setColor (BROWN);
    cout << cantidadDadosStock << " DADOS."<< endl;

    setColor (YELLOW);
    cout << endl << "DADOS OBJETIVO de ";

    setColor (colorJugador);
    cout << jugador;
    setColor (WHITE);

    cout << ":" << endl;  //EJEMPLO:   "DADOS OBJETIVO de PEPITO"

    cout << endl;
    for (int i = 0; i < 2; i++){
            setColor (LIGHTMAGENTA);
        cout <<" <";
            setColor(WHITE);

            setColor (YELLOW);
        cout << tiradaObjetivo[i];
            setColor (WHITE);

            setColor (LIGHTMAGENTA);
        cout << "> ";   //EJEMPLO : "10 8"
            setColor (WHITE);
    }
    cout << " = ";

    setColor (YELLOW );
    cout << numeroObjetivo;
    setColor (WHITE);

    cout << " (Numero Objetivo)"<<endl << endl; //EJEMPLO "= 18"

    //Cout que informa de quien es la tirada
    cout << "Tirada de ";


    setColor (colorJugador);
    cout << jugador;
    setColor (WHITE);

    cout << " (Valores):" << endl; //EJEMPLO: "Tirada de PEPITO"

    //For para mostrar los DADOS STOCK
    for(int i = 0; i< cantidadDadosStock ; i++){

        setColor (BROWN);
        cout << "  d[";

        setColor (YELLOW);
        cout << i+1;

        setColor (BROWN);
        cout << "]";  //EJEMPLO: d[1]  d[2]  d[3]  d[4]  d[5]  d[6]
        setColor (WHITE);
    }

    setColor (YELLOW);
    cout << " -> POSICIONES";
    setColor (WHITE);

    cout << " (Ingresa el numero de dado (";

    setColor (BROWN);
    cout << "d";
    setColor (WHITE);

    cout << ") (o 0 para terminar turno)." << endl;
    //For para mostrar la linea de los DADOS STOCK
    for(int i = 0; i< cantidadDadosStock ; i++){

        setColor (YELLOW);
        cout << "    | ";    //EJEMPLO: "   |     |     |     |     |     |"
        setColor (WHITE);
    }
    cout << endl;
    //For para mostrar la punta de flecha de los DADOS STOCK
    for(int i = 0; i<cantidadDadosStock ; i++){

        setColor (YELLOW);
        cout << "    v ";  //EJEMPLO: "   v     v     v     v     v     v"
        setColor (WHITE);
    }
    cout << endl;
    //EJEMPLO COMO SE IMPRIME EN PANTALLA:
    //cout << " d[1]  d[2]  d[3]  d[4]  d[5]  d[6] -> POSICIONES (selecciona ingresando el numero de dado (d) (o 0 para terminar turno)."
    //cout << "   |     |     |     |     |     |"
    //cout << "   v     v     v     v     v     v"

    for (int i = 0; i < cantidadDadosStock; i++) {

        int valor = dadosStock[i];

        setColor (colorJugador);
        cout << "   [";

        setColor (colores[valor - 1]);
        cout << dadosStock[i];

        setColor (colorJugador);
        cout << "]";  //EJEMPLO:  [3] [2] [7] [1] [6] [3]
        setColor (WHITE);
    }

    //DO WHILE con los DADOS que tenemos de momento.
    //Tambien va CAMBIANDO a X los USADOS.
    do{
        cout << endl <<endl <<"Opcion: ";
        cin >> opcion;

        if (opcion == 0) break; // Si elige 0  termina el turno

        if ((opcion >= 1) && (opcion <= cantidadDadosStock)) {
            if (!dadoUsado[opcion - 1]) {
                dadoUsado[opcion - 1] = true;
                cantDadosElegidos++;
                sumaSeleccionada += dadosStock[opcion - 1];
            } else {
                setColor (RED);
                cout << "Ya utilizaste el dado d[" << opcion <<"]"<< endl;
                setColor (WHITE);
            }
        }else {
                setColor (RED);
            cout << "Opci¢n no v lida. Eleg¡ un n£mero de DADO v lido entre 1 y " << cantidadDadosStock << " (o 0 para terminar turno)." << endl;
                setColor (WHITE);        }

        //Este FOR muestra los DADOS usados con una X en cada seleccion.
        for (int i = 0; i < cantidadDadosStock; i++) {

            int valor = dadosStock [i];

            if (dadoUsado[i]){
            setColor (colorJugador);
                cout << "   [X]";
            setColor (WHITE);
            }else{
                setColor (colorJugador);
                cout << "   [";

                setColor (colores[valor - 1]);
                cout << dadosStock[i];

                setColor (colorJugador);
                cout << "]";
                setColor (WHITE);
            }
        }
    }while (cantDadosElegidos < cantidadDadosStock  && opcion != 0);

    //Resumen de puntos luego de ELEGIR DADOS o TOCAR 0
    cout << endl<< endl << "- Usted ha seleccionado " << cantDadosElegidos << " DADOS // La suma de ellos es de: " << sumaSeleccionada << endl;
    cout << "- Suma Objetivo: " << numeroObjetivo << endl<< endl;

    //Informar Si es una TIRADA EXITOSA o NO
    if (numeroObjetivo == sumaSeleccionada){
        //Aqui haremos los calculos de los dados
        cantidadDadosStock-=cantDadosElegidos;
        cantidadDadosContrincante+=cantDadosElegidos;
        puntajeTotal = sumaSeleccionada * cantDadosElegidos;

        ///VERIFICACION DE 10MIL PUNTOS
        if(cantidadDadosStock<=0){
            puntajeTotal+=10000;

        setColor (YELLOW);
        cout << R"(
                                                                           |
                                                          _|_              |
                                                           |    *         \|/
                                    +     |                         + ----=*=----
                   +       *  +  _|_  *___|___   -|-  *      +            /|\
          -+-   <[*]~~~*~~+~~~~~~~|~~~+~~~|~~~~~~~~~~~~~*~~~~~~[*]> *      |
        -|- *   <°\°/\/\/\/\/\/\/\/\/\/\/\|/\/\/\/\/\/\/\/\/\/\°/°>   -+-  |
         _|_  + <°\°Te quedaste SIN DADOS ~ VICTORIA AUTOMATICA°/°>
          |  *  <°V°==°==°==°==°==°==°==°|YYY|°==°==°==°==°==°=°V°>
       +    |     *                  °==°|\V/|°==°
           -+-                        °=°|_T_|°=°
            | )" << endl << endl << endl;
        setColor (WHITE);

            setColor (YELLOW);
            cout << "- FELICIDADES ";

            setColor (colorJugador);
            cout << jugador;
            setColor (WHITE);

            setColor (YELLOW);
            cout <<" OBTUVISTE";
            setColor (LIGHTGREEN);
            cout << " 10000 PUNTOS";

            setColor (YELLOW);
            cout << "!!!";

            cout  << endl;

            cout <<"-        HAS GANADO EL JUEGO!!!" << endl;
            cout << "-         PUNTAJE FINAL: ";
            puntajeJugador += puntajeTotal;

            setColor (LIGHTGREEN);
            cout << puntajeJugador << endl<< endl;
            setColor (WHITE);

            setColor (YELLOW);
            cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
            setColor (WHITE);

            return 10000; //Finaliza la instancia de ejecucion por el RETURN (Ese valor luego se usa para una validacion en la funcion jugar()
            //exit(0);  // Finaliza completamente el programa
        }

        ///TIRADA EXITOSA
        //Nos RESTAREMOS la cantidad de DADOS usados para llegar a la SUMA.
        //Le TRANSFERIREMOS esa cantidad al contrincante
        setColor (CYAN);
        cout << R"(
                   {+}^^^^^^^^^^^^^^^^^^^^^^^^^^{+}
                   °|°/\/\/\/\/\/\/\/\/\/\/\/\/\°|°
                   °|°La TIRADA fue EXITOSA! ! !°|°
                   VV°==°==°==°==°==°==°==°==°==°VV)" << endl << endl << endl;
        setColor (WHITE);

        cout << "- LOS "<<cantDadosElegidos << " DADOS USADOS SERAN TRANSFERIDOS A SU CONTRINCANTE."<< endl << endl;
        cout << "- Jugador ";

        setColor (colorJugador);
        cout << jugador;
        setColor (WHITE);

        cout << " - DADOS RESTANTES: " << cantidadDadosStock<< endl;
        cout <<endl << "- Puntaje total: " << cantDadosElegidos << " x " << sumaSeleccionada << " = " << puntajeTotal<< endl<< endl;
        puntajeJugador += puntajeTotal;

        setColor (CYAN);
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
        setColor (WHITE);

    }else{
        ///TIRADA NO EXITOSA
        //Si el CONTRINCANTE tiene mas de 1 DADO, nos TRANSFERIRA 1 de ellos.
        //Nos sumamos 1 dado mas como PENALIZACION
        if(cantidadDadosContrincante > 1){
            cantidadDadosStock++;
            cantidadDadosContrincante--;
        }

        setColor (RED);
        cout << R"(
                   _=°==°==°==°==°==°==°==°=_
                   |La TIRADA NO fue EXITOSA|
                   ^=°==°==°==°==°==°==°==°=^)" << endl << endl << endl;
        setColor (WHITE);

        setColor (RED);
        cout << "- PENALIZACION: +1 DADO en el proximo turno" << endl<< endl;
        setColor (WHITE);

        cout << "- Jugador ";

        setColor (colorJugador);
        cout << jugador;
        setColor (WHITE);

        cout << " - DADOS RESTANTES: " << cantidadDadosStock<< endl<< endl;
        cout << "- Puntaje total = " << puntajeTotal<< endl<< endl;

        puntajeJugador += puntajeTotal;
        cout << "- Su puntaje por el momento es de: " << puntajeJugador << endl<< endl;
        cout << "  TERMINANDO TURNO..." << endl;

        setColor (RED);
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl << endl;
        setColor (WHITE);
    }


    return puntajeJugador;
}

// FUNCION CREDITOS
void Creditos () {

    setColor (BROWN);
    cout << endl << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl << endl ;
    setColor (LIGHTCYAN);
    cout << "* Alan Ciccarelli -------------- LEGAJO: 30934 " << endl;
    setColor (YELLOW);
    cout << "* Thomas Ferreyra Willemet ----- LEGAJO: 33190 " << endl;
    setColor (DARKGREY);
    cout << "* Sandro Samudio Zarate -------- LEGAJO: 32394 " << endl;
    setColor (BROWN);
    cout << endl << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl << endl;
}

// FUNCION REGLAS
void Reglas () {

    setColor (LIGHTCYAN);
    cout << R"(_____________________________________________________________________________
                             REGLAS DEL JUEGO
    --------------------------------------- OBJETIVO DEL JUEGO ----------
    - Sumar la mayor cantidad de puntos en 3 rondas
    - O ganar automaticamente si te quedas sin dados

    --------------------------------------- TURNO DE CADA JUGADOR -------
    1. Lanzar 2 dados de 12 caras (dados objetivo)
    2. Sumar sus caras: Numero objetivo (2 a 24)
    3. Lanzar tus dados stock (dados de 6 caras)
    4. Elegir dados cuya suma = Numero objetivo
    5. Si aciertas, sumas puntos y transfieres esos dados al rival

    --------------------------------------- TIRADA EXITOSA --------------
    - Puntaje = Numero objetivo X cantidad de dados usados
    - Dados usados se transfieren al oponente
    - Si te quedas sin dados Ganas automaticamente +10.000

    --------------------------------------- TIRADA NO EXITOSA -----------
    - Si fallas, recibes 1 dado del rival (si tiene mÃ¡s de 1)

    --------------------------------------- FIN DEL JUEGO ---------------
     Gana quien tenga mas puntos tras 3 rondas
    - O quien se quede sin dados en una tirada exitosa
    - Si empatan en puntos, el juego termina empatado
_____________________________________________________________________________
 )" << endl;
}

//FUNCION ESTADISTICAS
void Estadisticas (int puntajeMaximo, string jugadorPuntajeMaximo) {

        setColor (LIGHTCYAN);
    cout << endl << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl << endl ;
    if (puntajeMaximo > 0) {

        setColor (LIGHTCYAN);
        cout << endl << "EL JUGADOR " << jugadorPuntajeMaximo << " OBTUVO LA MAXIMA PUNTUACION CON " << puntajeMaximo << " PUNTOS." << endl;
    } else {

        setColor (RED);
        cout << endl << "TODAVIA NO SE HA JUGADO NINGUNA PARTIDA." << endl;
    }
        setColor (LIGHTCYAN);
    cout << endl << endl << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"<< endl << endl ;
}
