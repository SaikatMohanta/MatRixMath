#include "MatRixMath.h"

MatRixMath::MatRixMath(int rows, int cols) : rows_(rows), cols_(cols) {
  allocateMemory();
}

MatRixMath::~MatRixMath() {
  deallocateMemory();
}

void MatRixMath::allocateMemory() {
  matrix_ = new float*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new float[cols_];
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0.0;
    }
  }
}

void MatRixMath::deallocateMemory() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

void MatRixMath::setValue(int row, int col, float value) {
  if (row >= 0 && row < rows_ && col >= 0 && col < cols_) {
    matrix_[row][col] = value;
  }
}

float MatRixMath::getValue(int row, int col) {
  if (row >= 0 && row < rows_ && col >= 0 && col < cols_) {
    return matrix_[row][col];
  }
  return 0.0;
}

void MatRixMath::add(MatRixMath& other) {
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] += other.getValue(i, j);
      }
    }
  }
}

void MatRixMath::subtract(MatRixMath& other) {
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] -= other.getValue(i, j);
      }
    }
  }
}

void MatRixMath::multiply(MatRixMath& other) {
  if (cols_ == other.rows_) {
    float** result = new float*[rows_];
    for (int i = 0; i < rows_; i++) {
      result[i] = new float[other.cols_];
      for (int j = 0; j < other.cols_; j++) {
        result[i][j] = 0.0;
        for (int k = 0; k < cols_; k++) {
          result[i][j] += matrix_[i][k] * other.getValue(k, j);
        }
      }
    }
    deallocateMemory();
    matrix_ = result;
    cols_ = other.cols_;
  }
}

void MatRixMath::multiply(float scalar) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= scalar;
    }
  }
}

void MatRixMath::transpose() {
  float** result = new float*[cols_];
  for (int i = 0; i < cols_; i++) {
    result[i] = new float[rows_];
    for (int j = 0; j < rows_; j++) {
      result[i][j] = matrix_[j][i];
    }
  }
  deallocateMemory();
  matrix_ = result;
  int temp = rows_;
  rows_ = cols_;
  cols_ = temp;
}

void MatRixMath::print() {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      Serial.print(matrix_[i][j]);
      Serial.print("\t");
    }
    Serial.println();
  }
}

