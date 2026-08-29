#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>
using namespace std;

//DECLARACION DE FUNCIONES

void Menu(); //Menu de opciones

void Jugar (int &puntajeMaximo, string &jugadorPuntajeMaximo);  // Funcion pricipal del juego - Traigo por REFERENCIA las variables para cambiarlas y usarlas en ESTADISTICAS

int tiradaDado6Caras();   // Tirada de DADO de 6

int tiradaDado12Caras(); //Tirada de DADO de 12

string quienComienza(string nombreJugador1, string nombreJugador2);  // Elige quien comienza

int jugarRonda (string jugador, int &puntajeJugador, int &cantidadDados, int &cantidadDadosContrincante, int colorJugador);  //Juega el turno de cada jugador

void Creditos (); //Nombres del EQUIPO

void Reglas ();  //REGLAS del juego

void Estadisticas (int puntajeMaximo, string jugadorPuntajeMaximo);  // Muestra el MAXIMO PUNTAJE y nombre del JUGADOR


#endif // FUNCIONES_H_INCLUDED
