#include <iostream>
using namespace std;

void eliminarPalabras(string* oracion);
void EliminarPalabra(string *oracion, int inicio, int fin);
int contarLetras(string oracion);
bool compararPalabras(char palabra1[], char palabra2[]);
int contarLetrasW(char oracion[]);

int main(){
    string oracion;
    string *ora = &oracion;
    cout<<"ingrese una oracion\n";
    getline(cin, *ora);
    eliminarPalabras(ora);
    cout<<oracion<<endl;
    


    

    



}

void eliminarPalabras(string* oracion){
    char palabra[20];
    char wordFound[20];
    int index = 0;
    int tam = contarLetras(*oracion);


    cout<<"ingrese la palabra\n";
    cin>>palabra;

    for (int i = 0; i < tam + 1 ; i++)
    {
        if ((*oracion)[i] == ' ' || (*oracion)[i] == '\0')
        {
            //cout<<"llegue hasta aqui\n";
            if (compararPalabras(palabra, wordFound))
            {
               //cout<<"la palabra se encontro\n";
               int inicio = i - contarLetrasW(palabra);
               EliminarPalabra(oracion, inicio, i);


            }
            



            index = 0;

        }else{
            wordFound[index] = (*oracion)[i];
            index++;
        }
        
    }
    


};

int contarLetras(string oracion){
    int count = 0;
    while (oracion[count] != '\0')
    {
        count++;
    }
    return count;
    

}
int contarLetrasW(char oracion[]){
    int count = 0;
    while (oracion[count] != '\0')
    {
        count++;
    }
    return count;
    

}

bool compararPalabras(char palabra1[], char palabra2[]){
    int tam = contarLetrasW(palabra1);
    for (int i = 0; i < tam; i++)
    {
        if (palabra1[i] != palabra2[i])
        {
            return false;
        }
        
    }
    return true;
    

}

void EliminarPalabra(string *oracion, int inicio, int fin){
    //int tam = contarLetras(*oracion);

    for (int i = inicio; i < fin; i++)
    {
        (*oracion)[i] = ' ';
    }
    
    


}