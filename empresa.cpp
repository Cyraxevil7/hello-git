#include <iostream>

using namespace std;

struct Ventas
{
    int codigo;
    float cuota;
    int cantidad;
};
struct Cursos 
{
    int NumHor;
    string nombre;
    string instituto;
    float costo;
};


struct Vendedor
{
    string nombre;
    int ci;
    string direccion;
    string correo;
    Ventas infoVen[10];
    Cursos capacitacion[10];
    float gastosEnCap;

};
void cargarDatos(Vendedor listado[], int tam);
Vendedor buscarPorCi(Vendedor listado[], int tam, int ci );
void cualGastoMas(Vendedor listado[], int tam);


int main(){
    Vendedor vendedores[20];
    int tam;
    int opcion;
    bool runing = true;
    do
    {
        cout<<"ingrese la cantidad de vendedores y que no supere los 20\n";
        cin>>tam;

    }while(tam > 20 || tam < 0);

    cargarDatos(vendedores, tam);

    do
    {
        cout<<"Que desea hacer ahora: \n0. Para salir \n1. Para ver quien gasto mas en cursos";
        cin>>opcion;



        switch ( opcion)
        {
        case 1:
            cualGastoMas(vendedores, tam);
            break;

        case 0:
            runing = false;
            break;
        
        default:

            break;
        }
    } while (runing);
    
    
    
    
    


}


void cargarDatos(Vendedor listado[], int tam){
    for (int i = 0; i < tam; i++)
    {
        cout<<"ingrese el nombre: ";
        cin>>listado[i].nombre;

        cout<<"Ingrese el numero de cedula: ";
        cin>>listado[i].ci;

        cout<<"ingrese el correo de la persona: ";
        cin>>listado[i].correo;
        
        int cantidad;
        do{
        cout<<"ingrese la cantidad de productos que se vendieron y que no supere los 10 productos : ";
        
        
        cin>>cantidad;}while(cantidad< 0 || cantidad > 20);
        

        for (int j = 0; j < cantidad; j++)
        {
            cout<<"ingrese el codigo del producto: ";
            cin>>listado[i].infoVen[j].codigo;
            cout<<"ingrese la cuota del producto: ";
            cin>>listado[i].infoVen[j].cuota;
            cout<<"Ingrese el numero de veces que se vendio el producto: ";
            cin>>listado[i].infoVen[j].cantidad;
        }
        cout<<"ingrese la cantidad de cursos que realizo la persona";
        int cantidadC;
        float inversionEnCursos = 0;
        cin>>cantidadC;
        for (int k = 0; k < cantidadC; k++)
        {
            cout<<"ingrese el nombre del curso: ";
            cin>>listado[i].capacitacion[k].nombre;

            cout<<"ingrese el numero de horas dedicadas: ";
            cin>>listado[i].capacitacion[k].NumHor;

            cout<<"ingrese el nombre de la institucion donde se realizo el curso: ";
            cin>>listado[i].capacitacion[k].instituto;

            cout<<"ingrese el dinero invertido en el curso: ";
            cin>>listado[i].capacitacion[k].costo;

            inversionEnCursos += listado[i].capacitacion[k].costo;
            

        }
        listado[i].gastosEnCap =inversionEnCursos;
        


    }
    
}

void cualGastoMas(Vendedor listado[], int tam){
    float mayor;
    int mayorGastador;
    for (int i = 0; i < tam; i++)
    {
        if (i == 0)
        {
            mayor = listado[i].gastosEnCap;
            mayorGastador = i;
        }else if (listado[i].gastosEnCap > mayor)
        {
            mayor = listado[i].gastosEnCap;
            mayorGastador = listado[i].ci;
        }
        
        
    }
    Vendedor ElMasGastador = buscarPorCi(listado,tam,mayorGastador);
    cout<<"El que gasto mas dinero en cursos fue: "<<ElMasGastador.nombre<<"\nCon la cedula: "<<ElMasGastador.ci<<"\nCon un gasto total de: "<<mayor<<" Bs\n";
}

Vendedor buscarPorCi(Vendedor listado[], int tam, int ci ){
    for (int i = 0; i < tam; i++)
    {
        if (listado[i].ci == ci)
        {
            return listado[i];
            break;
        }

        
    }
    cout<<"no se encontro\n";
    
    

}