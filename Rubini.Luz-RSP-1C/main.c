#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"
int main()
{
    system("color 0f");
    char seguir='s';
    int opcion;
    ArrayList* listaEmpleados=al_newArrayList();
    ArrayList* listaFiltrada;
    FILE* miArchivo=NULL;
    int bandera=0;
    int banderaDos=0;
    int i;
    //Empleado* auxEmpleado;

    while(seguir=='s')
    {
        printf("1- Cargar lista de empleados\n");
        printf("2- Lista filtrada\n");
        printf("3- Nuevo archivo\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);
        while(opcion<1 || opcion>4)
        {
            printf("Error! Ingrese una opcion valida: ");
            scanf("%d",&opcion);
        }
        switch(opcion)
        {
            case 1:
                parserEmpleado(miArchivo,listaEmpleados);
                mostrarEmpleados(listaEmpleados);
                bandera=1;
                break;
            case 2:
                if(bandera==1)
                {
                    for(i=0;i<al_len(listaEmpleados);i++)
                    {
                        listaFiltrada=al_filter(listaEmpleados,funcionQueFiltra);
                    }
                    if(listaFiltrada!=NULL)
                    {
                        mostrarEmpleados(listaFiltrada);
                    }
                    else
                    {
                        printf("No se puede mostrar la lista");
                    }
                    banderaDos=1;
                }
                else
                {
                    printf("No se puede crear una nueva lista sin haber cargado un archivo\n");
                }
                break;
            case 3:
                if(banderaDos==1)
                {
                    EscribirTexto(listaFiltrada);
                }
                else
                {
                    printf("No se puede crear un archivo lista sin haber creado la lista filtrada\n");
                }

                break;
            case 4:
                seguir = 'n';
                break;
        }

        system("pause");
        system("cls");
    }

    return 0;
}
