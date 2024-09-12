#include <stdio.h>

struct SparseMatrixElement
{
   int row;
   int col;
   int value;
};

int main()
{
   int m, n, i, j, k = 0;
   printf("Enter the number of rows and columns of the matrix: \n");
   scanf("%d %d", &m, &n);

   int matrix[m][n];
   printf("Enter the elements of the matrix : \n");
   for (i = 0; i < m; i++)
   {
      for (j = 0; j < n; j++)
      {
         scanf("%d", &matrix[i][j]);
      }
   }

   int nonZeroCnt = 0;
   for (i = 0; i < m; i++)
   {
      for (j = 0; j < n; j++)
      {
         if (matrix[i][j] != 0)
         {
            nonZeroCnt++;
         }
      }
   }

   struct SparseMatrixElement sparse[nonZeroCnt];
   k = 0;
   for (i = 0; i < m; i++)
   {
      for (j = 0; j < n; j++)
      {
         if (matrix[i][j] != 0)
         {
            sparse[k].row = i;
            sparse[k].col = j;
            sparse[k].value = matrix[i][j];
            k++;
         }
      }
   }

   printf("\nSparse Matrix Representation:\n");
   printf("Row \t Column \t Value \n");
   for (i = 0; i < nonZeroCnt; i++)
   {
      printf("%d \t %d \t %d \n", sparse[i].row, sparse[i].col, sparse[i].value);
   }

   return 0;
}
