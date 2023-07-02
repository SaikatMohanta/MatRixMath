#include "MatRixMath.h"

MatRixMath matrixA(3, 3);
MatRixMath matrixB(3, 3);

void setup() {
  Serial.begin(9600);

  // Set values for matrixA
  matrixA.setValue(0, 0, 1);
  matrixA.setValue(0, 1, 2);
  matrixA.setValue(0, 2, 3);
  matrixA.setValue(1, 0, 4);
  matrixA.setValue(1, 1, 5);
  matrixA.setValue(1, 2, 6);
  matrixA.setValue(2, 0, 7);
  matrixA.setValue(2, 1, 8);
  matrixA.setValue(2, 2, 9);

  // Set values for matrixB
  matrixB.setValue(0, 0, 9);
  matrixB.setValue(0, 1, 8);
  matrixB.setValue(0, 2, 7);
  matrixB.setValue(1, 0, 6);
  matrixB.setValue(1, 1, 5);
  matrixB.setValue(1, 2, 4);
  matrixB.setValue(2, 0, 3);
  matrixB.setValue(2, 1, 2);
  matrixB.setValue(2, 2, 1);

  // Print matrixA and matrixB
  matrixA.print();
  Serial.println();
  matrixB.print();
  Serial.println();

  // Perform matrix operations
  matrixA.add(matrixB);
  matrixA.print();
  Serial.println();

  matrixA.subtract(matrixB);
  matrixA.print();
  Serial.println();

  matrixA.multiply(matrixB);
  matrixA.print();
  Serial.println();

  matrixA.multiply(2.0);
  matrixA.print();
  Serial.println();

  matrixA.transpose();
  matrixA.print();
  Serial.println();
}

void loop() {
  // Nothing to do here
}

