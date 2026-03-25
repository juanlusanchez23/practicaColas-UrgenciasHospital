//
// Created by juanl on 25/03/2026.
//
/******************************************************************************
 * Módulo: Hospital.h                                                         *
 * Tipo: Programa ( )   Interfaz-Implementación TAD (X)   Otros ( )           *
 * Autor/es: [Juan Luis Sánchez Olivares]                                                         *
 * Fecha de actualización: 25/03/2026                                         *
 * Descripción: Interfaz del TAD Hospital (Encapsulación Nota 2).             *
 ******************************************************************************/
#ifndef PRACTICACOLAS_URGENCIASHOSPITAL_HOSPITAL_H
#define PRACTICACOLAS_URGENCIASHOSPITAL_HOSPITAL_H
#include "Colas.h"
typedef struct {
    tCola listaPacientes;
    int camasDisponibles;
    char medicos[5][50];
    int turno;
} tHospital;
/* * OPERACIÓN: crearHospitalVacio
 * PRE: El hospital no ha sido inicializado.
 * POST: Hospital listo con 75 camas, 5 médicos y cola vacía.
 * COMPLEJIDAD: O(M) donde M es el número de médicos.
 */
void crearHospitalVacio(tHospital *hospital);
/* * OPERACIÓN: insertarEnHospital
 * PRE: Hospital inicializado y paciente con datos válidos.
 * POST: Paciente en cola y una cama menos si había sitio.
 * COMPLEJIDAD: O(1). [cite: 53, 67]
 */
void insertarEnHospital (tHospital *hospital, tElemento paciente);
/* * OPERACIÓN: consultarMedico
 * PRE: El hospital no debe estar vacío.
 * POST: Muestra asignación, elimina paciente, suma cama y rota turno.
 * COMPLEJIDAD: O(1).
 */
char* consultarMedico (tHospital *hospital);
/* * OPERACIÓN: consultarPrimero
 * PRE: El hospital no debe estar vacío.
 * POST: Devuelve la información del paciente al frente de la cola.
 * COMPLEJIDAD: O(1).
 */
tPaciente consultarPrimero (tHospital *hospital);
/* * OPERACIÓN: quitarPrimero
 * PRE: El hospital no debe estar vacío.
 * POST: Elimina al primero, libera cama y actualiza turno médico.
 * COMPLEJIDAD: O(1).
 */
void quitarPrimero (tHospital *hospital);
/* * OPERACIÓN: esHospitalVacio
 * PRE: Hospital inicializado.
 * POST: Devuelve 1 si no hay pacientes, 0 en caso contrario.
 * COMPLEJIDAD: O(1).
 */
int esHospitalVacio (tHospital *hospital);

#endif //PRACTICACOLAS_URGENCIASHOSPITAL_HOSPITAL_H