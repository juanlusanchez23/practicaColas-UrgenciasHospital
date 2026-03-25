//
// Created by juanl on 25/03/2026.
//
/******************************************************************************
 * Módulo: main.c                                                             *
 * Tipo: Programa (X)   Interfaz-Implementación TAD ( )   Otros ( )           *
 * Autor/es: [Juan Luis Sánchez Olivares]                                     *
 * Fecha de actualización: 25/03/2026                                         *
 * Descripción: Interfaz de usuario para la simulación del hospital.          *
 ******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hospital.h"
int main() {
    tHospital miHospital;
    int opcion;
    tPaciente paciente;
    char *nombreMedico;
    printf("----CREANDO NUEVO HOSPITAL...----\n ");
    crearHospitalVacio(&miHospital);
    do{
        printf("\n--- MENU DE GESTION HOSPITALARIA ---\n");
        printf("1. Admitir nuevo paciente (Insertar)\n");
        printf("2. Atender paciente (Consultar Medico)\n");
        printf("3. Ver proximo paciente en espera (Consultar Primero)\n");
        printf("4. Retirar paciente sin atender (Quitar Primero)\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("\n--- Formulario de Ingreso ---\n");
                printf("Numero de Expediente: ");
                scanf ("%d", paciente.exp);
                getchar();
                printf("Nombre y Apellidos: ");
                fgets(paciente.nombre, 50, stdin);
                int n = strlen(paciente.nombre);
                for (int i = 0; i < n; i++) {
                    if (paciente.nombre[i] == '\n') {
                        paciente.nombre[i] = '\0';
                    }
                }
                printf("Edad: ");
                scanf("%d", &paciente.edad);
                getchar();
                printf("Dolencia: ");
                fgets(paciente.dolencia, 50, stdin);
                n = strlen(paciente.dolencia);
                for (int i = 0; i < n; i++) {
                    if (paciente.dolencia[i] == '\n') {
                        paciente.dolencia[i] = '\0';
                    }
                }
                insertarEnHospital(&miHospital, paciente);
                break;
                case 2:
                if (!esHospitalVacio(&miHospital)) {
                    nombreMedico = consultarMedico(&miHospital);
                    printf("\nPaciente atendido por: %s\n", nombreMedico);
                } else {
                    printf("\nNo hay pacientes esperando en la cola.\n");
                }
                break;
                case 3:
                if (!esHospitalVacio(&miHospital)) {
                    paciente = consultarPrimero(&miHospital);
                    printf("\n El siguiente es: %s (Exp: %d) con: %s\n",
                            paciente.nombre, paciente.exp, paciente.dolencia);
                } else {
                    printf("\nLa cola de espera esta vacia.\n");
                }
                break;

            case 4:
                if (!esHospitalVacio(&miHospital)) {
                    quitarPrimero(&miHospital);
                    printf("\nEl primer paciente ha sido retirado de la lista.\n");
                } else {
                    printf("\nNo hay nadie a quien retirar.\n");
                }
                break;

            case 5:
                printf("\nSaliendo del programa y liberando recursos...\n");
                break;

            default:
                printf("\nOpcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 5);
    return 0;
}