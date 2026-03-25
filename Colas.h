//
// Created by juanl on 25/03/2026.
//
/******************************************************************************
 * Módulo: Colas.h                                                            *
 * Tipo: Programa ( )   Interfaz-Implementación TAD (X)   Otros ( )           *
 * Autor/es: [Juan Luis Sánchez Olivares]                                     *
 * Fecha de actualización: 25/03/2026                                         *
 * Descripción: Interfaz del TAD Cola dinámica para pacientes.                *
 ******************************************************************************/
#ifndef PRACTICACOLAS_REPARTIENDOELBOTIN_COLAS_H
#define PRACTICACOLAS_REPARTIENDOELBOTIN_COLAS_H
#ifndef COLAS_H
#define COLAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct paciente{
    int exp;
    char nombre[20];
    int edad;
    char dolencia[50];
}tPaciente;

typedef tPaciente tElemento;

typedef struct NodoCola {
    tElemento info;
    struct NodoCola *sig;
} tNodoCola;

typedef struct {
    tNodoCola *cabecera;
    tNodoCola *final;
} tCola;

//CONSTRUCTORAS GENERADORAS
void CrearColaVacia(tCola *cola);
void Insertar(tCola *cola, tElemento elem);

//OBSERVADORAS SELECTORAS

tElemento PrimeroCola(tCola *cola);
void Eliminar(tCola *cola);

//OBSERVADORAS NO SELECTORAS
int EsColaVacia(tCola *cola);
int IgualCola(tCola *cola1, tCola *cola2);

//CONSTRUCTORAS NO GENERADORAS
void CopiarCola(tCola *colaOriginal, tCola *colaCopia);

#endif

#endif //PRACTICACOLAS_REPARTIENDOELBOTIN_COLAS_H