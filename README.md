# MatRixMath
A basic Arduino library to manipulate Matrices

The custom 'MatRixMath' library is designed to provide basic matrix operations for Arduino IDE. Let's go through the key parts of the library and explain their functionality:

1. `MatRixMath` Class:
   - The `MatRixMath` class is the main class of the library.
   - It represents a matrix and provides various operations that can be performed on matrices.
   - The constructor takes the number of rows and columns as arguments and initializes the matrix with zeros.
   - The destructor deallocates the memory used by the matrix.

2. Member Variables:
   - `rows_` and `cols_`: These variables store the dimensions (rows and columns) of the matrix.
   - `matrix_`: This is a 2D array that represents the matrix data.

3. Member Functions:
   - `allocateMemory()` and `deallocateMemory()`: These functions handle the dynamic allocation and deallocation of memory for the matrix data.
   - `setValue(int row, int col, float value)`: This function sets the value of an element at a given row and column in the matrix.
   - `getValue(int row, int col)`: This function retrieves the value of an element at a given row and column in the matrix.
   - `add(MatRixMath& other)`: This function performs matrix addition with another matrix. It adds each corresponding element of the matrices together.
   - `subtract(MatRixMath& other)`: This function performs matrix subtraction with another matrix. It subtracts each corresponding element of the matrices.
   - `multiply(MatRixMath& other)`: This function performs matrix multiplication with another matrix. It multiplies the matrices according to matrix multiplication rules.
   - `multiply(float scalar)`: This function performs scalar multiplication on the matrix. It multiplies each element of the matrix by the given scalar value.
   - `transpose()`: This function transposes the matrix, swapping the rows and columns.
   - `print()`: This function prints the matrix values to the Serial monitor.

The library allows you to create matrix objects, set values, perform basic operations like addition, subtraction, multiplication (both matrix and scalar), transpose the matrix, and print the matrix values. It provides a simple interface to work with matrices in Arduino sketches.

You can include this library in your Arduino sketch, create matrix objects, and perform matrix operations according to your requirements.
