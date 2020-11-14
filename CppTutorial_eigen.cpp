//Eigen is an open source linear algebra library implemneted in C++. 
#include <iostream>
#include <Eigen/Dense> // include Eigen library header files

using namespace std;
using namespace Eigen;

namespace ex_matrix {
	//There are many ways to define and declare matrices
	void ex1()
	{
		//1. Explicit declaration - define a 3x3 matrix of float with zero initialization. float can be changed to double, int, or any other standard variable type
		Matrix <float, 3, 3> matrixA;
		matrixA.setZero();
		cout << "Explicit declaration: " << endl;
		cout << matrixA << endl;

		//2. Typedef declaration - OpenGL type declaration - "3f" stands for "3x3" matrix of "float", Matrix3d- for 3x3 matrix of double, Matrix3i - for 3x3 matrix of integers
		Matrix3f matrixB;
		matrixB.setZero();
		cout << "Typedef declaration: " << endl;
		cout << matrixB << endl;

		//3. Dynamic declaration during compile time. Though fixed-size declaration is much efficient than variable size.
		//However, for large scale problem we do not know the size during compilation
		//Explicit declaration: creates a matrix of size 0
		Matrix < float, Dynamic, Dynamic > matrixC;
		cout << "Dynamic declaration 1" << endl;
		cout << matrixC << endl;
		//Typedef declaration : "X" for unknown size and "f" for float
		MatrixXf matrixD;
		cout << "Dynamic declaration 2" << endl;
		cout << matrixD << endl;

		//4. constructor : allocate memeory bu do not initialize
		MatrixXd matrixE(3, 3);
		cout << "Constructor" << endl;
		cout << matrixE << endl;

		//Assigning matrix entries
		MatrixXd matrix1(2, 2);
		matrix1(0, 0) = 1;
		matrix1(0, 1) = 2;
		matrix1(1, 0) = 3;
		matrix1(1, 1) = 4;
		cout << "Assignment" << endl << matrix1 << endl;

		//Matrix entries are filled with numbers using comma separated entries
		Matrix3f matrix2;
		matrix2 << 1, 2, 3,
			4, 5, 6,
			7, 8, 9;
		cout << "Assignment" << endl << matrix2 << endl;

		//Define a dynamic matrix, resise it to a 3x3 matrix and set the values to zeros
		Matrix3f matrix3;
		matrix3.resize(3, 3);
		matrix3.setZero(3, 3);
		cout << "Assignment" << endl << matrix3 << endl;

		//Define when rows and columns are given
		int rows = 3, cols = 3;
		MatrixXf matrix4;

		//Assigned zeros - one way
		matrix4 = MatrixXf::Zero(rows, cols);
		cout << "Assignment 0" << endl << matrix4 << endl;
		//Assigned zeros - another way
		matrix4.setZero(rows, cols);
		cout << "Assignment 0" << endl << matrix4 << endl;

		//assigned ones - one way
		matrix4 = MatrixXf::Ones(rows, cols);
		cout << "Assignment 1" << endl << matrix4 << endl;
		//assigned ones - another way
		matrix4.setOnes(rows, cols);
		cout << "Assignment 1" << endl << matrix4 << endl;

		//Assigned with constant
		float value = 1.1;
		matrix4 = MatrixXf::Constant(rows, cols, value);
		cout << "Assignment constant" << endl << matrix4 << endl;
		matrix4.setConstant(rows, cols, value);
		cout << "Assignment constant" << endl << matrix4 << endl;

		//Identity matrix
		matrix4 = MatrixXf::Identity(rows, cols);
		cout << "Assignment Identity" << endl << matrix4 << endl;
		matrix4.setIdentity(rows, cols);
		cout << "Assignment Identity" << endl << matrix4 << endl;

		//Assigned Random number
		matrix4 = MatrixXf::Random(rows, cols);
		cout << "Assignment Random" << endl << matrix4 << endl;
		matrix4.setRandom(rows, cols);
		cout << "Assignment Random" << endl << matrix4 << endl;
	}

	void ex2()
	{
		MatrixXd matrixA(3, 3);
		matrixA << 1, 2, 3,
			4, 5, 6,
			7, 8, 9;
		//Accessing matrix blocks
		//Access first two rows and two columns and store in another matrix. Start with 0 row and 0 column
		MatrixXd matrixApartition = matrixA.block(0, 0, 2, 2);
		cout << "Partition" << endl << matrixApartition << endl;
		
		//Access first two rows and two columns and store in another matrix. start with 1 row and 1 column
		MatrixXd matrixApartition2 = matrixA.block(1, 1, 2, 2);
		cout << "Partition" << endl << matrixApartition2 << endl;

		//Accessing rows and columns of a matrix
		cout << "Row 1 : " << matrixA.row(0) << endl;
		cout << "Column 1 : " << matrixA.col(0) << endl;

		//Accessing an element
		cout << "1st element : " << matrixA(0, 0) << endl;

		//Create a diagonal matrix out of a vector
		Matrix <int, 3, 1> v1;
		v1 << 1, 2, 3;
		MatrixXi diaMatrix;
		diaMatrix = v1.asDiagonal();
		cout << endl << "Diagonal Matrix: " << endl << diaMatrix << endl;
	}

	//Matrix operations
	void ex3()
	{
		//matrix addition, subtraction and multiplication
		MatrixXd A(2, 2);
		MatrixXd B(2, 2);

		A << 1, 2,
			3, 4;
		B << 5, 6,
			7, 8;

		MatrixXd C = A + B;
		cout << endl << "Sum : \n" << C << endl;
		cout << endl << "Subtract : \n" << A - B << endl;
		cout << endl << "Multiplication : \n" << A * B << endl;

		// Transpose
		MatrixXd D;
		D = A.transpose();
		cout << endl << "Transpose : \n" << D << endl;

		// Transpose in an expression
		MatrixXd D1;
		D1 = A.transpose() + B;
		cout << endl << "Transpose + B : \n" << D1 << endl;
		//We should be careful when we perform transpose in place
		//D = D.transpose() // not a valid statement, leads unexpected results
		//correct and safe way performing operation in place
		D.transposeInPlace();
		cout << endl << "Transpose : \n" << D << endl;

		//Matrix inverse
		MatrixXd E;
		E = D.inverse();
		cout << endl << "Inverse : \n" << E << endl;
	}

	//SVD - Singular Value Decomposition
	void ex4()
	{
		Eigen::MatrixXf m = Eigen::MatrixXf::Random(3, 2);
		cout << "Here is the matrix m:" << endl << m << endl;
		Eigen::JacobiSVD<Eigen::MatrixXf> svd(m, Eigen::ComputeThinU | Eigen::ComputeThinV);
		cout << "Its singular values are:" << endl << svd.singularValues() << endl;
		cout << "Its left singular vectors are the columns of the thin U matrix:" << endl << svd.matrixU() << endl;
		cout << "Its right singular vectors are the columns of the thin V matrix:" << endl << svd.matrixV() << endl;
		Eigen::Vector3f rhs(1, 0, 0);
		cout << "Now consider this rhs vector:" << endl << rhs << endl;
		cout << "A least-squares solution of m*x = rhs is:" << endl << svd.solve(rhs) << endl;
	}
	

}

int main()
{
	//ex_matrix::ex1();
	//ex_matrix::ex2();
	//ex_matrix::ex3();
	ex_matrix::ex4();

	return 0;
}
