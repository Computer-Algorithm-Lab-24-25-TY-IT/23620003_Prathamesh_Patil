#include <iostream>
#include <vector>

using namespace std;

void inputMatrix(vector<vector<int>> &matrix, int numRows, int numCols)
{
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int value : row)
        {
            cout << value << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>> &matrixA, const vector<vector<int>> &matrixB, int numRowsA, int numColsA, int numColsB)
{
    vector<vector<int>> productMatrix(numRowsA, vector<int>(numColsB, 0));

    for (int i = 0; i < numRowsA; ++i)
    {
        for (int j = 0; j < numColsB; ++j)
        {
            for (int k = 0; k < numColsA; ++k)
            {
                productMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return productMatrix;
}

int main()
{
    int numRowsA, numColsA, numRowsB, numColsB;

    cout << "Enter the number of rows and columns for the first matrix: ";
    cin >> numRowsA >> numColsA;

    vector<vector<int>> matrixA(numRowsA, vector<int>(numColsA));
    inputMatrix(matrixA, numRowsA, numColsA);

    cout << "Enter the number of rows and columns for the second matrix: ";
    cin >> numRowsB >> numColsB;

    if (numColsA != numRowsB)
    {
        cout << "Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication." << endl;
        return 1;
    }

    vector<vector<int>> matrixB(numRowsB, vector<int>(numColsB));
    inputMatrix(matrixB, numRowsB, numColsB);

    vector<vector<int>> productMatrix = multiplyMatrices(matrixA, matrixB, numRowsA, numColsA, numColsB);

    cout << "Product matrix is:" << endl;
    printMatrix(productMatrix);

    return 0;
}
