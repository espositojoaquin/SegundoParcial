struct
{
    int id;
    char nombre[100];
    char profesion[100];
    int edad;
}typedef Empleado;

/**
 * Genera espacio en momoria para una estructura Empleado
 * @param variable tipo void
 * @return espacio para la estructura
 */
Empleado* empleado_new(void);
/**
 * Filtra empleados segun profesion y edad
 * @param puntero a void
 * @return [0] si el empleado debe ser filtrado
            [1] si el empleado se queda.
 */
int funcionQueFiltra(void*);
/**
 * Lee un archivo con la lista de empleados.
 * @param puntero al archivo
 * @param puntero a ArrayList
 * @return lista dinamica de empleados
 */
int parserEmpleado(FILE* pFile , ArrayList* listaEmpleado);
/**
 * Muestra un empleados de la lista
 * @param puntero a la estructura
 * @return Un empleado
 */
void empleado_print(Empleado* this);
/**
 * Muestra todos los empleados de la lista
 * @param puntero a ArrayList
 * @return lista de empleados
 */
void mostrarEmpleados(ArrayList* lista);
/**
 * Genera una nueva lista para poder filtrar
 * @param puntero a ArrayList (lista original)
 * @param puntero a ArrayList (lista a filtrar)
 * @return lista de empleados
 */
void parserEmpleadoFiltrado(ArrayList* empleados,ArrayList* empleadoFiltrado);
void EscribirTexto(ArrayList*);
