
#include"Header.h"
int main()
{
    int field[5][5]; 

        ifstream file("input.txt"); 
        for (int i = 0; i < 5; i++) { 
            for (int j = 0; j < 5; j++)
            {
                file >> field[i][j]; 
            }
        }
     
        
    
    int A[5];
    for (int k = 0; k < 5; k++)
        A[k] = 0;
    stack<int> Stack;

    TopSort(Stack,A,field);
    
    saveResultToFile(A);
   
    return 0;
 
  
}
