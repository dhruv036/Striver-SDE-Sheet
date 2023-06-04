#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > setZeroes(vector<vector<int> > &matrix) {
  int nrows = matrix.size();
  int ncols = matrix[0].size();

  int col = 1;
  for (int i = 0; i < nrows; i++) {
    for (int j = 0; j < ncols; j++) {
      if (matrix[i][j] == 0) {

        matrix[i][0] = 0;
        if (j == 0) {
          col = 0;
        } else {
          matrix[0][j] = 0;
        }
      }
    }
  }

  for (int i = 1; i < nrows; i++) {
    for (int j = 1; j < ncols; j++) {
      if (matrix[i][j] != 0) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
  }
  if (matrix[0][0] == 0) {
    for (int i = 0; i < ncols; i++) {
      matrix[0][i] = 0;
    }
  }
  if (col == 0) {
    for (int i = 0; i < nrows; i++) {
      matrix[i][0] = 0;
    }
  }
  return matrix;
};

int main() {
  vector<vector<int> > matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  int n = matrix.size();
  int m = matrix[0].size();
  vector<vector<int> > ans = setZeroes(matrix);

  cout << "The Final matrix is: \n";
  for (auto it : ans) {
    for (auto ele : it) {
      cout << ele << " ";
    }
    cout << endl;
  }
  return 0;
}
