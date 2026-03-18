#include <iostream>
#define MaxfilasM 12
#define MaxColumnasM 12
#define MaxfilasI 10
#define MaxColumnasI 10
bool esPrimo(int numero);
void ColumnaConMasprimos(int matriz[][12], int filas, int columnas);
void ColumnaConMasprimosMenor(int matriz[][10], int filas, int columnas);
void seEncuentraDentroDeLaMatriz(int matrizMadre[][12], int matrizInterna[][10], int filasMadre, int columnasMadre, int filasInterna, int columnasInterna);

void llenarMatriz(int matriz[][12], int filas, int columnas);
void llenarMatrizMenor(int matriz[][10], int filas, int columnas);
using namespace std;


int main(){ 

    //Son las matrices que estuve usando paa ir probando las funciones, aunque igual deje la opcion de que el usuario ingrese las matrices por el enunciado del ejercicio  
    
    
    /*int matrizMayor[MaxfilasM][MaxColumnasM] = {{1,2,3,4,5,6,7,8,9,10,11,12},
                                {13,14,15,16,17,18,19,20,21,22,23,24},
                                {25,26,27,28,29,30,31,32,33,34,35,36},
                                {37,38,39,40,41,42,43,44,45,46,47,48},
                                {49,50,51,52,53,54,55,56,57,58,59,60},
                                {61,62,63,64,65,66,67,68 ,69 ,70 ,71 ,72},
                                {73 ,74 ,75 ,76 ,77 ,78 ,79 ,80 ,81 ,82 ,83 ,84},
                                {85 ,86 ,87 ,88 ,89 ,90 ,91 ,92 ,93 ,94 ,95 ,96},
                                {97 ,98 ,99 ,100 ,101 ,102 ,103 ,104 ,105 ,106 ,107 ,108},
                                {109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120},
                                {121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132},
                                {133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144}};

    int matrizMenor[MaxfilasI][MaxColumnasI] = {{1,2,3},
                            {13,14,15},
                            {25,26,27}};

    ColumnaConMasprimos(matrizMayor);         
    seEncuentraDentroDeLaMatriz(matrizMayor, matrizMenor, 12, 12, 3, 3);    */

    int opcion;
    
    
    int columnasMayor, columnasMenor;
    do
    {
        
        cout<<"ingrese el numero de columnas y filas de la matriz y que sea menor a 12\n";
        cin>>columnasMayor;
        
        cout<<"ingrese el numero de columnas y filas de la matriz menor y que sea menor a 10\n";
        cin>>columnasMenor;

    } while ( (columnasMayor < columnasMenor) || (columnasMayor > MaxColumnasM ||  columnasMenor > MaxColumnasI));

    int matrizMayor[MaxfilasM][12];
    int matrizMenor[MaxfilasI][10];

    cout<<"ingrese la matriz mayor\n";
    llenarMatriz(matrizMayor, columnasMayor, columnasMayor);

    cout<<"ingrese la matriz menor\n";
    llenarMatrizMenor(matrizMenor, columnasMenor, columnasMenor);

    cout<<"ingrese 1 para dectectar si la matriz menor esta dentro de la mayor\nIngrese 2 para hallar la columna de la que tiene mas primos\n";
    cin>>opcion;
    int opcion2;
    bool runing = true;
    

    switch (opcion)
    {
    case 1:
        seEncuentraDentroDeLaMatriz(matrizMayor, matrizMenor, columnasMayor, columnasMayor, columnasMenor, columnasMenor);
        break;
    case 2: 
        do{
        cout<<"Presione 1 si quiere buscar en la matriz mas grade o presione 2 para buscar en la mas pequenia o 3 para salir\n";
        cin>>opcion2;

        if (opcion2 == 1)
        {
            ColumnaConMasprimos(matrizMayor, columnasMayor, columnasMayor);
        }else if (opcion2 == 2)
        {
            ColumnaConMasprimosMenor(matrizMenor, columnasMenor, columnasMenor);
        
        }else if(opcion2 == 3)
        {
            runing = false;
            
        }}while(runing);
        break;
        
    
    default:
        break;
    
    
    }
}

void ColumnaConMasprimos(int matriz[][12], int filas, int columnas){
    int columnaConMasprimos = 0;
    int IndiceConMasPrimos = 0;
    for (int i = 0; i < columnas; i++)
    {
        int contadorPrimos = 0;
        for (int j = 0; j < filas; j++)
        {
            if (esPrimo(matriz[j][i]))
            {
                contadorPrimos++;
            }
        }
        if (i == 0)
        {
            columnaConMasprimos = contadorPrimos;
            IndiceConMasPrimos = i;
        
        }else if (contadorPrimos > columnaConMasprimos)
        {
            columnaConMasprimos = contadorPrimos;
            IndiceConMasPrimos = i;
        }
        
        
        
    }
    cout<<"columna en el indice"<<IndiceConMasPrimos<<" tiene "<<columnaConMasprimos<<" numeros primos\n";
    


}
void ColumnaConMasprimosMenor(int matriz[][10], int filas, int columnas){
    int columnaConMasprimos = 0;
    int IndiceConMasPrimos = 0;
    for (int i = 0; i < columnas; i++)
    {
        int contadorPrimos = 0;
        for (int j = 0; j < filas; j++)
        {
            if (esPrimo(matriz[j][i]))
            {
                contadorPrimos++;
            }
        }
        if (i == 0)
        {
            columnaConMasprimos = contadorPrimos;
            IndiceConMasPrimos = i;
        
        }else if (contadorPrimos > columnaConMasprimos)
        {
            columnaConMasprimos = contadorPrimos;
            IndiceConMasPrimos = i;
        }
        
        
        
    }
    cout<<"columna en el indice"<<IndiceConMasPrimos<<" tiene "<<columnaConMasprimos<<" numeros primos\n";
    


}

bool esPrimo(int numero){
    if (numero <= 1) return false;
    for (int i = 2; i <= numero / 2; i++)
    {
        if (numero % i == 0)
        {
            return false;
        }
    }
    return true;
}


void seEncuentraDentroDeLaMatriz(int matrizMadre[][12], int matrizInterna[][10], int filasMadre, int columnasMadre, int filasInterna, int columnasInterna){
    int vecesEncontrada = 0;
    for (int i = 0; i < filasMadre; i++)
    {
        for (int j = 0; j < columnasMadre; j++)
        {
            if (matrizMadre[i][j] == matrizInterna[0][0])
            {
                bool encontrado = true;
                for (int k = 0; k < filasInterna; k++)
                {
                    for (int l = 0; l < columnasInterna; l++)
                    {
                        if (matrizMadre[i + k][j + l] != matrizInterna[k][l])
                        {
                            encontrado = false;
                            break;
                        }
                    }
                    if (!encontrado)
                    {
                        break;
                    }
                }
                if (encontrado)
                {
                    cout<<"La matriz interna se encuentra dentro de la matriz madre\n";
                    vecesEncontrada++;
                    cout<<"Se encontro por "<<vecesEncontrada<<" vez\n";
                    //return;
                }
            }
        }
    }
    if (vecesEncontrada == 0)
    {
        cout<<"La matriz interna no se encuentra dentro de la matriz madre\n";
    }


}

void llenarMatriz(int matriz[][12] , int filas, int columnas){
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout<<"ingrese el numero para la posicion ["<<i<<"]["<<j<<"]\n";
            cin>>matriz[i][j];
        }
        
    }
    
}
void llenarMatrizMenor(int matriz[][10] , int filas, int columnas){
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout<<"ingrese el numero para la posicion ["<<i<<"]["<<j<<"]\n";
            cin>>matriz[i][j];
        }
        
    }
    
}