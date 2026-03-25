//
// Created by juanl on 25/03/2026.
//
/******************************************************************************
 * Módulo: Hospital.c                                                         *
 * Tipo: Programa ( )   Interfaz-Implementación TAD (X)   Otros ( )           *
 * Autor/es: [Juan Luis Sánchez Olivares]                                     *
 * Fecha de actualización: 25/03/2026                                         *
 * Descripción: Lógica circular de médicos y control de camas.                *
 ******************************************************************************/
#include"Hospital.h"


void crearHospitalVacio(tHospital *hospital) {
    hospital -> camasDisponibles = 75;
    hospital -> turno = 0;
    CrearColaVacia(&(hospital -> listaPacientes));
    for (int i = 0; i < 5; i++) {
        printf("Ingrese el nombre y apellidos del medico: ");
        fgets(hospital-> medicos[i], 50, stdin);
        int n= strlen(hospital-> medicos[i]);
        for (int j = 0; j < n; j++) {
            if (hospital-> medicos[i][j] == '\n') {
                hospital-> medicos[i][j] = '\0';
            }
        }
    }
}

void insertarEnHospital (tHospital *hospital, tElemento paciente) {
    if (hospital -> camasDisponibles >0) {
        hospital -> camasDisponibles--;
        Insertar(&(hospital ->listaPacientes), paciente);
        printf("Paciente ingresado con exito. Camas restantes: %d", hospital -> camasDisponibles);
    }
    else printf("ERROR: No hay camas disponibles");
}

char* consultarMedico (tHospital *hospital){
    if (!EsColaVacia(&(hospital ->listaPacientes))) {
int indice = hospital-> turno;
    Eliminar(&(hospital->listaPacientes));
    hospital -> turno = (hospital -> turno + 1) % 5 ;
    hospital -> camasDisponibles ++;
    return hospital-> medicos[indice];
}
    else return NULL;
}

tPaciente consultarPrimero (tHospital *hospital) {
       return PrimeroCola(&(hospital ->listaPacientes));
}

void quitarPrimero (tHospital *hospital) {
    if (!EsColaVacia(&(hospital ->listaPacientes))) {
        Eliminar((&(hospital ->listaPacientes)));
        hospital -> camasDisponibles++;
        hospital -> turno = (hospital->turno + 1) % 5;
    }
    else printf("ERROR: Hospital vacio");
}

int esHospitalVacio (tHospital *hospital) {
    if (EsColaVacia(&(hospital ->listaPacientes))) {
        return 1;
    }
    else return 0;
}



