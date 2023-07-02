#ifndef MatRixMath_h
#define MatRixMath_h

#include <Arduino.h>

class MatRixMath {
public:
  MatRixMath(int rows, int cols);
  ~MatRixMath();

  void setValue(int row, int col, float value);
  float getValue(int row, int col);

  void add(MatRixMath& other);
  void subtract(MatRixMath& other);
  void multiply(MatRixMath& other);
  void multiply(float scalar);
  void transpose();

  void print();

private:
  int rows_;
  int cols_;
  float** matrix_;

  void allocateMemory();
  void deallocateMemory();
};

#endif

