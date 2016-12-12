//идея метода релаксации заключаеться в том что на каждом шаге обращаеться в
//нуль максимальный по модулю вектор начальных изменений путем изменения
//значения соответствуйщей компоненты приблежения . Процесс заканчиваеться когда
// все невязки последней преобразованной
//системы будут равны нулю с заданой точностью

#include <stdio.h>
#include <iostream>
#include <math.h>

const float eps = 1E-4;
const int maxSize = 10;

void data_input(int &n, float a[][maxSize], float b[]);
void print_matrix(int &n, float a[][maxSize]);

int main() {
  int n;
  // индекс макимальной привязки
  int  iMaxR;
  //float a[maxSize][maxSize], b[maxSize], R[maxSize], maxR;
  float R[maxSize], maxR, dx;
  // задаем начальное приближение
  float x[maxSize] = {0,0,0,0,0,0,0,0,0,0};
  // вводим занчения коэффициентов
  //data_input(n, a, b);
  n = 3;
  // --------------
  float a[maxSize][maxSize] = {
    {0 ,0, 0, 0},
    {0, 2, 1, 3},
    {0, 11, 7, 5},
    {0, 9, 8, 4}
  };
  float b[maxSize] = {0, 1, -6, -5};
  // --------------

  // Вычисляем B[i] и начальные невязки
  for (int i = 1; i <= n; i++) {
    // вычисляем начальные невязки
    b[i] /= a[i][i];
    R[i] = b[i];
  }
  // Вычисляем новые коэффициенты при x
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++){
      if (i != j)
        a[i][j] /= -a[i][i];
    }
    a[i][i] = -1;
  }
  // выводим промежуточный результат
  print_matrix(n, a);

  printf("Начальные невязки:\n");
  for (int i = 1; i <= n; i++)
    printf("R[%d] = %f \n", i, R[i]);
  do {
    // вычисляем максимальную невязку
    maxR = 0;
    iMaxR = 1;
    for (int i = 1; i <= n; i++){
      if (maxR < fabs(R[i])) {
        maxR = fabs(R[i]);
        iMaxR = i;
      }
    }
    // прибавляем к x[iMaxR] невязку
    x[iMaxR] += R[iMaxR];
    // вычисляем новые привязки
    dx = R[iMaxR];
    for (int i = 1; i <= n; i++){
      R[i] += a[i][iMaxR] * dx;
    }
  } while(maxR > eps);

  printf("Ответ: \n");
  for (int i = 1; i <= n; i++)
    printf("X[%d] = %f \n", i, x[i]);
    printf("\n");
  return 0;
}

void data_input(int &n, float a[][maxSize], float b[]) {
  printf("%s\n", "Введите размер матрицы коэфициентов: ");
  scanf("%d", &n);

  printf("%s\n", "Введите матрицу коэффициентов (А): ");
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <=n; j++)
      scanf("%f", &a[i][j]);

  printf("%s\n", "Введите столбец свободных членов (В): ");
  for (int i = 1; i <= n; i++)
    scanf("%f", &b[i]);

  printf("%s\n", "Введена матрица:");
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      printf("%f ", a[i][j]);
      printf("\n");
  }
}

void print_matrix(int &n, float a[][maxSize]) {
  printf("\n--------------------------------------\n");
  printf("Промежуточный результат\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++){
      printf("%f ", a[i][j]);
    }
    printf("\n");
  }
  printf("\n--------------------------------------\n");

}
