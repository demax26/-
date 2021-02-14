#include"Header.h"
void saveResultToFile(int * A)
{
    ofstream fout;
    fout.open("output.txt");
    for (int i = 0; i < 5; i++)
        fout << A[i]<<"  ";
    fout.close();
}



void TopSort(stack<int>Stack,int *A, int field[5][5]) {
    int mas[5][5];
    for (int i = 0; i < 5; i++) { //цыкл
        for (int j = 0; j < 5; j++)
        {
            mas[i][j] = field[i][j]; //записываем в массив даные
        }
    }
    int nodes[5]; // вершины графа
    int g = 0;
    for (int i = 0; i < 5; i++) // исходно все вершины равны 0
        nodes[i] = 0;
    Stack.push(0); // помещаем в очередь первую вершину
    while (!Stack.empty())
    { // пока стек не пуст
        int node = Stack.top(); // извлекаем вершину
        Stack.pop();
        if (nodes[node] == 2) continue;
        nodes[node] = 2; // отмечаем ее как посещенную
        for (int j = 4; j >= 0; j--)
        { // проверяем для нее все смежные вершины
            if (mas[node][j] == 1 && nodes[j] != 2)
            { // если вершина смежная и не обнаружена
                Stack.push(j); // добавляем ее в cтек
                nodes[j] = 1; // отмечаем вершину как обнаруженную
            }
        }
        std::cout <<  node + 1 << std::endl; // выводим номер вершины
        A[g] = node + 1;
        g++;
    }
    
    
}


