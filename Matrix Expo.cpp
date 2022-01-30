#include "bits/stdc++.h"
using namespace std;
typedef long long int ll;
ll MOD=1e9+7;
struct Matrix
{
    vector< vector<ll> > mat; // the contents of matrix as a 2D-vector
    int n_rows, n_cols; // number of rows and columns

    Matrix(vector< vector<ll> > values): mat(values), n_rows(values.size()), n_cols(values[0].size()) {}
    static Matrix identity_matrix(int n)
    {
        // Return I_n - the identity matrix of size n.
        // This function is static, because it creates a new Matrix instance
        vector< vector<ll> > values(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++)values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const
    {
        int n = n_rows, m = other.n_cols;
        vector< vector<ll> > result(n_rows, vector<ll>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n_cols; k++) {
                    result[i][j] = (result[i][j]%MOD + (mat[i][k]%MOD * 1ll * other.mat[k][j]%MOD)%MOD) % MOD;
                }
            }
        return Matrix(result);
    }
    inline int at_position(int r, int c)const
    {
        assert(r<n_rows and c<n_cols and r >= 0 and c >= 0);
        return mat[r][c];
    }
    inline bool is_square() const
    {
        return n_rows == n_cols;
    }
    void Out()
    {
        for (int i = 0; i < n_rows; ++i)
        {
            for (int j = 0; j < n_cols; ++j)
            {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

Matrix fast_exponentiation(Matrix m, ll power)
{
    assert(m.is_square());
    Matrix result = Matrix::identity_matrix(m.n_rows);
    while (power) {
        if (power & 1ll)
            result = result * m;
        m = m * m;
        power >>= 1;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Matrix A({
                     {1,1,1,1},
                     {1,1,1,1},
                     {1,1,1,1},
    });
    A.Out();





    return 0;
}