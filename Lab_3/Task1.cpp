#include <iostream>

using namespace std;

class Matrix
{

    int rows, cols, **data;

public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;
        data = new int *[r];
        for (int i = 0; i < r; i++)
        {
            data[i] = new int[c];
            for (int j = 0; j < c; j++)
            {
                data[i][j] = 0;
            }
        }
    }

    int getRows()
    {
        return rows;
    }

    int getCols()
    {
        return cols;
    }

    void setElementAtGivenPosition(int r, int c, int value)
    {
        data[r][c] = value;
    }

    void addMatrix(Matrix matrix)
    {
        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = matrix.data[i][j] + data[i][j];
            }
        }

        // print result
        for (int i = 0; i < rows; i++)
        {
            cout << "[";
            for (int j = 0; j < cols; j++)
            {
                cout << result.data[i][j] << ", ";
            }
            cout << "\b\b]" << endl;
        }
    }

    void multiplyMatrix(Matrix matrix)
    {
        Matrix result(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = 0;

                // multiply sum of the specific row
                for (int k = 0; k < rows; k++)
                {
                    result.data[i][j] += (data[i][k] * matrix.data[k][j]);
                }
            }
        }

        // print result
        for (int i = 0; i < rows; i++)
        {
            cout << "[";
            for (int j = 0; j < cols; j++)
            {
                cout << result.data[i][j] << ", ";
            }
            cout << "\b\b]" << endl;
        }
    }
};

int main()
{

    Matrix a(2, 2), b(2, 2), c(2, 2);

    // Get A
    cout << "Enter value for Matrix A: " << endl;
    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            int x;

            cout << "Element[" << i << "][" << j << "]: ";
            cin >> x;
            a.setElementAtGivenPosition(i, j, x);
        }
    }

    // Get B
    cout << "Enter value for Matrix B: " << endl;
    for (int i = 0; i < b.getRows(); i++)
    {
        for (int j = 0; j < b.getCols(); j++)
        {
            int x;

            cout << "Element[" << i << "][" << j << "]: ";
            cin >> x;
            b.setElementAtGivenPosition(i, j, x);
        }
    }

    // Get C
    cout << "Enter value for Matrix C: " << endl;
    for (int i = 0; i < c.getRows(); i++)
    {
        for (int j = 0; j < c.getCols(); j++)
        {
            int x;

            cout << "Element[" << i << "][" << j << "]: ";
            cin >> x;
            c.setElementAtGivenPosition(i, j, x);
        }
    }

    cout << "A + B:" << endl;
    a.addMatrix(b);

    cout << "A * C:" << endl;
    a.multiplyMatrix(c);

    return 0;
}