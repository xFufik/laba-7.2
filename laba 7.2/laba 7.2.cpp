#include <iostream>
#include <locale>

using namespace std;

/*
*Лабораторная работа 7. Задание 2. Индивидуальный вариант 24.
*Для задания 2 лабораторной работы 6 реализовать ввод, формирование/обработку и вывода массивов с применением функций. Обнулить элементы матрицы, лежащие одновременно ниже главной диагонали (включая эту диаго-наль) и выше побочной диагонали (также включая эту диагональ). Условный оператор не использовать.
*return 0 - все ок. return 1 - ошибка.
*/

void vvod(int** matrix, int M) {
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }
}

void obrabotka(int** matrix, int M) {
    matrix[0][0] = 0;
    for (int i = 1; i < M; i++) {
        matrix[i][i] = 0;
        matrix[i][i - 1] = 0;
    }

    matrix[M - 1][0] = 0;
    for (int i = 0; i < M - 1; i++) {
        int j = M - 1 - i;
        matrix[i][j] = 0;
        matrix[i][j - 1] = 0;
    }
}

void vivod(int** matrix, int M) {
    cout << "Результат:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    int M;

    cout << "Введите порядок М квадратной матрицы: ";
    cin >> M;

    if (M <= 0) {
        cerr << "Порядок матрицы должен быть натуральным числом!";
        return 1;
    }

    int** matrix = new int* [M];
    for (int i = 0; i < M; i++) {
        matrix[i] = new int[M];
    }

    vvod(matrix, M);
    obrabotka(matrix, M);
    vivod(matrix, M);

    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
