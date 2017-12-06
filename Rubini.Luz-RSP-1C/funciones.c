#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"
#include <string.h>

int parserEmpleado(FILE* pFile,ArrayList* listaEmpleado)
{
    char nombre[100],profesion[100],edad[20],id[20];
    Empleado* empleado;

    if(listaEmpleado!=NULL)
    {
        pFile=fopen("empleados.csv","r");
        if(pFile!=NULL)
        {
            while(!feof(pFile))
            {
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,profesion,edad);
                empleado=empleado_new();
                strcpy(empleado->nombre,nombre);
                strcpy(empleado->profesion,profesion);
                empleado->id=atoi(id);
                empleado->edad=atoi(edad);

                al_add(listaEmpleado,empleado);
           }
        }
    }
    fclose(pFile);

    return 0;
}
int funcionQueFiltra(void* empleado)
{
    int retorno=0;
    if(((Empleado*)empleado)->edad>30)
    {
        if(strcmp(((Empleado*)empleado)->profesion,"Programador")==0)
        {
           retorno=1;
        }
    }
    else
    {
        retorno=0;
    }
    return retorno;
}
Empleado* empleado_new(void)
{

    Empleado*returnAux=NULL;
    returnAux=(Empleado*)malloc(sizeof(Empleado));
    return returnAux;

}
void mostrarEmpleados(ArrayList* lista)
{
    int i;
    Empleado* aux;
    system("pause");
    system("cls");
    printf("LISTA DE EMPLEADOS\n\n");
    printf("ID\t\tNOMBRE\t\t\tPROFESION\t\tEDAD\n");
    for(i=0; i<lista->len(lista); i++)
    {
        aux=lista->get(lista,i);
        empleado_print(aux);
    }
}
void empleado_print(Empleado* this)
{
    if(this!=NULL)
    {
        printf("%d\t%20s\t%20s\t\t%d\n",this->id,this->nombre,this->profesion,this->edad);
    }
}
void EscribirTexto(ArrayList* listaFil)
{
    Empleado* empleadoAux;
    FILE* archivo;
    int i;
    char fileName[50]="out.csv";
    if(listaFil!=NULL)
    {
        archivo=fopen(fileName,"wa");
        if(archivo!=NULL)
        {
            for(i=0;i<al_len(listaFil);i++)
            {
                    empleadoAux=(Empleado*) al_get(listaFil,i);
                    fprintf(archivo,"%d,%s,%s,%d\n",empleadoAux->id,empleadoAux->nombre,empleadoAux->profesion,empleadoAux->edad);
            }

        }

        fclose(archivo);
    }
    else
    {
        printf("No se pudo generas el archivo");
        exit(0);
    }
}
