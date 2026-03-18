#include <iostream>

using namespace std;
int contaPalabras(string oracion);
void intercambio(string *oracion);



int main(){
    string oracion;
    string *apo = &oracion;
    *apo = "hola como estas bro";
    intercambio(apo);
    cout<<*apo;


}

void intercambio(string *oracion){
    int tam = contaPalabras(*oracion);
    //string 
    int count = 0;
    

    for (int i = 0; i <= tam  ; i++)
    {
        if ((*oracion)[i] == ' '|| (*oracion)[i] == '\0')
        {    
            //cout<<"true";
            if (count % 2 == 0 )
            {
                cout<<"true\n";
                int index =  i - count ;
                
                for (int j = i - 1; j >= index; j--)
                {   
                    
                    char  temp ;
                    temp = (*oracion)[index];
                    (*oracion)[index] = (*oracion)[j];
                    (*oracion)[j] = temp;
                    index++;
                    

                }
                
            }
            
            count = 0;
        }else{
        cout<<count<<endl;
        count++;
        
        }
        
    }
    

    
    

}

int contaPalabras(string oracion){
    int count = 0;
    //string oracionDes = *oracion; 
    while (oracion[count] != '\0')
    {
        count++;
    }
    return count;


}