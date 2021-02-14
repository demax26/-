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
    for (int i = 0; i < 5; i++) { //����
        for (int j = 0; j < 5; j++)
        {
            mas[i][j] = field[i][j]; //���������� � ������ �����
        }
    }
    int nodes[5]; // ������� �����
    int g = 0;
    for (int i = 0; i < 5; i++) // ������� ��� ������� ����� 0
        nodes[i] = 0;
    Stack.push(0); // �������� � ������� ������ �������
    while (!Stack.empty())
    { // ���� ���� �� ����
        int node = Stack.top(); // ��������� �������
        Stack.pop();
        if (nodes[node] == 2) continue;
        nodes[node] = 2; // �������� �� ��� ����������
        for (int j = 4; j >= 0; j--)
        { // ��������� ��� ��� ��� ������� �������
            if (mas[node][j] == 1 && nodes[j] != 2)
            { // ���� ������� ������� � �� ����������
                Stack.push(j); // ��������� �� � c���
                nodes[j] = 1; // �������� ������� ��� ������������
            }
        }
        std::cout <<  node + 1 << std::endl; // ������� ����� �������
        A[g] = node + 1;
        g++;
    }
    
    
}


