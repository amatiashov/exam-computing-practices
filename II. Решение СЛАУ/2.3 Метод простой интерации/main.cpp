#include <stdio.h>
#include <iostream>
#include <math.h>

const float eps = 1E-4;
//void data_input(int &n, float A[][maxSize], float B[]);


int main()
{
  int n = 3;
  int permutPosition = 0;
  float xNew[n+1];
  float xOld[n+1];
  float delta;
// ----------------------------------------------------------
  float A[4][4] = {
    {0,0,0,0},
    {0,4,1,-1},
    {0,1,-5,1},
    {0,1,-1,4}
  };
  float B[5] = {0,0,1,-1};
// ----------------------------------------------------------
  printf("---------------- B ----------------\n");
  for (int i = 1; i < (n+1); i++){
    B[i] = B[i] / A[i][i];
    printf("%f ", B[i]);
  }
  printf("\n----------------------------------\n");

  for (int i = 1; i < (n+1); i++){
    for (int j = 1; j < (n+1); j++)
      if (i != j)
        A[i][j] = -A[i][j] / A[i][i];
      A[i][i] = 0;
  }

  for (int i = 1; i < (n+1); i++) {
    for (int j = 1; j < (n+1); j++) {
//      printf("%f ", A[i][j]);
    }
//    printf("\n");
  }

  for (int i = 1; i < (n+1); i++)
    xOld[i] = B[i];
  int iter = 0;
  do {
    delta = 0;
    for (int i = 1; i < (n+1); i++) {
      xNew[i] = B[i];
      for (int j = 1; j < (n+1); j++)
        xNew[i] += A[i][j] * xOld[j];
        iter ++;
  //      printf("%f\n", xNew[i]);
        float D = fabs(xNew[i] - xOld[i]);
        xOld[i] = xNew[i];
        if (D > delta)
          delta = D;
    }// for i
  } while(delta > eps);

  printf("------------------- X -------------------\n");
  for (int i = 1; i < (n+1); i++) {
    printf("%f  ", xNew[i]);
  }
  printf("\n------------------- X -------------------\n");

/*
  for (int i = 1; i < (n+1); i++) {
    float answer = 0;
    for (int j = 1; j < (n+1); j++) {
      answer += A[i][j] * xNew[i];
    }
    printf("%f\n", answer);
  }
  printf("%d\n", iter);

  */
}

/*
void data_input(int &n, float A[][maxSize], float B[])
{
  printf("%s\n", "Введите размер матрицы коэфициентов: ");
  scanf("%d", &n);

  printf("%s\n", "Введите матрицу коэффициентов (А): ");
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <=n; j++)
      scanf("%f", &A[i][j]);

  printf("%s\n", "Введите столбец свободных членов (В): ");
  for (int i = 1; i <= n; i++)
    scanf("%f", &B[i]);

  printf("%s\n", "Введена матрица:");
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
      printf("%f ", A[i][j]);
      printf("\n");
  }
}
*/
