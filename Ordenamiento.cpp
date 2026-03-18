#include <iostream>

using namespace std;


int main(){
    int arreglo[5] = {5, 2, 9, 1, 5};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5 - i - 1 ; j++)
        {
            int temp;
            if (arreglo[j] > arreglo[j + 1])
            {
                temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout<<arreglo[i]<<" ";
    }
    
    
    return 0;
}