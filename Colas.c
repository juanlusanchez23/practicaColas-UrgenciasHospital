//
// Created by juanl on 25/03/2026.
//
/******************************************************************************
 * Módulo: Colas.c                                                            *
 * Tipo: Programa ( )   Interfaz-Implementación TAD (X)   Otros ( )           *
 * Autor/es: [Juan Luis Sánchez Olivares]                                     *
 * Fecha de actualización: 25/03/2026                                         *
 * Descripción: Implementación de las funciones de cola dinámica.             *
 ******************************************************************************/
#include "Colas.h"


//CONSTRUCTORAS GENERADORAS
void CrearColaVacia(tCola *cola) {
    cola -> cabecera = NULL;
    cola -> final = NULL;
}
void Insertar(tCola *cola, tElemento elem) {
    tNodoCola *nodo;
    nodo = (tNodoCola *)malloc(sizeof(tNodoCola));
    nodo ->info = elem;
    nodo -> sig = NULL;
    if (cola -> cabecera == NULL) {
        cola -> cabecera = nodo;
    }
    else {
        cola -> final -> sig = nodo;
    }
    cola -> final = nodo;
}

//OBSERVADORAS SELECTORAS

tElemento PrimeroCola(tCola *cola) {
    tElemento elem;
    tElemento elemVacio = {0, "", 0, ""};
    if (!EsColaVacia(cola)) {
        elem = cola -> cabecera->info;
        return elem;
    }
    else return elemVacio;
}
void Eliminar(tCola *cola) {
    tNodoCola *aux;
    if (!EsColaVacia(cola)) {
aux = cola -> cabecera;
        cola -> cabecera = cola -> cabecera -> sig;
        if (cola -> cabecera == NULL) {
            cola -> final = NULL;
        }
        free(aux);
    }
}

//OBSERVADORAS NO SELECTORAS
int EsColaVacia(tCola *cola) {
    if (cola -> cabecera == NULL && cola -> final == NULL) {
        return 1;
    }
    else return 0;
}
int IgualCola(tCola *cola1, tCola *cola2) {
    tNodoCola *aux1;
    tNodoCola *aux2;
    aux1 = cola1 -> cabecera;
    aux2 = cola2 -> cabecera;

    while ((aux1 != NULL && aux2 != NULL) ) {
        if (aux1 -> info.exp != aux2 -> info.exp) {
            return 0;
        }
        if (strcmp(aux1 -> info.nombre, aux2 -> info.nombre) != 0) {
            return 0;
        }
        if (aux1 -> info.edad != aux2 -> info.edad) {
            return 0;
        }
        if (strcmp(aux1 -> info.dolencia, aux2 -> info.dolencia) != 0) {
            return 0;
        }

        aux1= aux1 -> sig;
        aux2= aux2 -> sig;
    }
    if (aux1 == NULL && aux2 == NULL) {
        return 1;
    }
    else return 0;
}

//CONSTRUCTORAS NO GENERADORAS
void CopiarCola(tCola *colaOriginal, tCola *colaCopia) {
    tNodoCola *aux;
    aux = colaOriginal -> cabecera;
    CrearColaVacia(colaCopia);
    while (aux != NULL) {
        Insertar(colaCopia, aux -> info);
        aux = aux -> sig;
    }
}
