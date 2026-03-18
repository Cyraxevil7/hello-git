/******************************************************************************
Una empresa desea manejar la información de sus 20 vendedores que
incluyen
Nombre Cedula Dirección Correo

Y la información de ventas por cada uno de los diez artículos que maneja la
compañía de los cuales se tiene:
Código del
Articulo

Cuota de
venta

Cantidad
vendida

También se maneja la información de capacitación que contiene:
Nombre del
Curso

Nro de
Horas

Institución Costo
en Bs

Se tiene información de que cada empleado realiza entre 3 y 5 cursos. Se pide
lo siguiente:
 Definir las estructuras
 Realizar una función para cargar los datos
 Una función para mostrar por cada vendedor aquellos productos en que
no ha cubierto su cuota de ventas.
 Una funcione que especifique en cual vendedor se ha invertido más
dinero en cursos.
 Función para especificar cuál es el producto más vendido.
 Dando el nombre de un curso, muestre las instituciones que lo dictan y
cuál es su costo.

*******************************************************************************/
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define max 20
#define max2 5
using namespace std;
struct capacitacion{
    char nomcur[20];
    float horas ;
    float costo;
    long int mayor=0;
    int posi=0;
};

struct articulo{
    int codigo;
    int cuota;
    int vendida;
}ventas[10];

struct vendedores{
    char nombre[20];
    long int cedula;
    char direcion[30];
    char correo[40];
    struct capacitacion curso[max2];
    struct articulo ventas[10];
   
}vendedor[max];


int   cargardatos(vendedores vendedor[max]);
void    mostrarcuota(vendedores vendedor[max],int n);
void    inversioncurso(vendedores vendedor[max],int n);
void    productomasvendido(vendedores vendedor[max],int n);



int main(){
    vendedores vendedor[max];
  int n;
  n=cargardatos(vendedor);
   
    mostrarcuota(vendedor,n);
    inversioncurso(vendedor,n);
    productomasvendido(vendedor,n);
  
   
}
int   cargardatos(vendedores vendedor[max]){
    int i,j,n,k,masvendida=0;
    cout<<" ingrese la cantida de vendedores: ";cin>>n;
    cin.ignore();
   
    for(i=0;i<n;i++){
        //fflush(stdin);
        cout<<" ingrese el nombre: ";cin.getline(vendedor[i].nombre,20);
        cout<<" ingrese la cedula: ";cin>>vendedor[i].cedula;
        //cin.ignore();
        cout<<" ingrese la dirrecion: ";cin.getline(vendedor[i].direcion,30);
        cout<<" ingrese el correo: ";cin.getline(vendedor[i].correo,40);
        
        for(j=0;j<max2;j++){
            fflush(stdin);
            cout<<" ingrese el nombre del curso:";cin.getline(vendedor[i].curso[j].nomcur,20);
            cout<<" ingrese las horas vista de curso:";cin>>vendedor[i].curso[j].horas;
            cin.ignore();
            cout<<" ingrese el costo de el curso realizado en bolibares: ";cin>>vendedor[i].curso[j].costo;
            if(vendedor[i].curso[j].costo>vendedor[i].curso[j].mayor){
                vendedor[i].curso[j].mayor=vendedor[i].curso[j].costo;
                vendedor[i].curso[j].posi=i;
            }
           
        }
        fflush(stdin);
        cin.ignore();
        for(k=0;k<10;k++){
            cout<<" ingrese el codigo de la venta:";cin>>vendedor[i].ventas[k].codigo;
            cout<<" ingrese la cuota vendida: ";cin>>vendedor[i].ventas[k].cuota;
            cout<<" ingrese la cantida vendida: ";cin>>vendedor[i].ventas[k].vendida;
            if(vendedor[i].ventas[k].vendida>masvendida){
                masvendida=vendedor[i].ventas[k].vendida;
                
            }
        }
    }
    return n;
}

void    mostrarcuota(vendedores vendedor[max],int n){
    int i,j;
    for(i=0;i<n;i++){
        cout<<vendedor[i].nombre;
        bool paso=true;
        for(j=0;j<10;j++){
            if(vendedor[i].ventas[j].vendida<vendedor[i].ventas[j].cuota){
                cout<<" codigo: "<<vendedor[i].ventas[j].codigo;
                cout<<" falto: "<<vendedor[i].ventas[j].cuota-vendedor[i].ventas[j].vendida;
                paso=false;
            }
        }
        if(paso){
            cout<<" felizidades cubrio su cuotas: ";
        }
    }
}
void    inversioncurso(vendedores v[max],int n){
  int i,j,posi=0;
 
    long int mayor=0,suma=0;
    for(i=0;i<n;i++){
        for(j=0;j<max2;j++){
            suma+=vendedor[i].curso[j].costo;
        }
        if(suma>mayor){
            mayor=suma;
            posi=i;
        }
    }
    
    cout<<" el empleado con mayor inversion es: "<<vendedor[posi].nombre;
    cout<<" el costo total es: "<<mayor<<" Bs ";

}

void    productomasvendido(vendedores vendedor[max],int n){
    int i,j;
    long int masventa=0;
    char vender[20];
    int codigo;
    for(i=0;i<n;i++){
        for(j=0;j<10;j++){
            if(vendedor[i].ventas[j].vendida>masventa){
                masventa=vendedor[i].ventas[j].vendida;
                codigo=vendedor[i].ventas[j].codigo;
                strcpy(vender,vendedor[i].nombre);
            }
        }
    }
    cout<<"el vendedor de mas ganagncia: "<<vender;
    cout<<"el producto mas vendido: "<<codigo;
    cout<<"el numero de el producto mas vendedi es: "<<masventa;
}
