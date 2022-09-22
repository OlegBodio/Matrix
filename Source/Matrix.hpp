#include "Vector3.hpp"
#include <vector>
#include <iostream>
#include<cmath>

template<class T>
class Matrix
{
public:
	Matrix() = default;

	Matrix(unsigned _w = 3, unsigned _h = 3)
		: m_w(_w)
		, m_h(_h)
	{
		m_matrix = new T * [m_h];

		for (int i = 0; i < m_h; i++)
		{
			m_matrix[i] = new double[m_w];
		}
	}

	Matrix(const Matrix& other)
		: m_w(other.m_w)
		, m_h(other.m_h)
	{
		m_matrix = new T * [m_h];

		for (int i = 0; i < m_h; i++)
		{
			m_matrix[i] = new double[m_w];
		}

		for (int i = 0; i < m_h; ++i)
		{
			for (int j = 0; j < m_w; ++j)
			{
				m_matrix[i][j] = other.m_matrix[i][j];
			}
		}
	}

	void fillRandom()
	{
		for (int i = 0; i < m_h; ++i)
		{
			for (int j = 0; j < m_w; ++j)
			{
				m_matrix[i][j] = rand() % 10;
			}
		}
	}

	void fillFromExample()
	{
		int exampleArray[] = { 3, 1, 4, 1, -1, 2, 1, 1, 5 };
		int counter = 0;
		for (int i = 0; i < m_h; ++i)
		{
			for (int j = 0; j < m_w; ++j)
			{
				m_matrix[i][j] = exampleArray[counter];
				++counter;
			}
		}
	}

	void print() const
	{
		for (int i = 0; i < m_h; ++i)
		{
			for (int j = 0; j < m_w; ++j)
			{
				std::cout << m_matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	template <class T2>
	Matrix operator*(const Matrix<T2>& other) const
	{
		if (m_h == other.m_w)
		{
			Matrix<T> result(m_w, m_w);
			for (int i = 0; i < m_w; ++i)
			{
				auto currentLine = getLine(i);
				for (int j = 0; j < m_w; ++j)
				{
					result[i][j] = (calculateMultiplication(currentLine, other.getColumn(j)));
				}
			}
			return result;
		}
		return NULL;
	}

	template <class T2>
	Matrix operator*(const T2 num) const
	{
		Matrix<T> result(m_h, m_w);
		for (int i = 0; i < m_w; ++i)
		{
			for (int j = 0; j < m_h; ++j)
			{
				result[i][j] = m_matrix[i][j] * num;
			}
		}
		return result;
	}

	template <class T2>
	Matrix operator+(const Matrix<T2>& other) const
	{
		if (m_w == other.m_w && m_h == other.m_h)
		{
			Matrix<T> result(m_h, m_w);
			for (int i = 0; i < m_w; ++i)
			{
				for (int j = 0; j < m_h; ++j)
				{
					result[i][j] = m_matrix[i][j] + other[i][j];
				}
			}
			return result;
		}
		else
		{
			return NULL;
		}
	}

	~Matrix()
	{
		for (int i = 0; i < m_h; i++)
			delete[] m_matrix[i];
		delete[] m_matrix;
	}

	Matrix getAlgebraAddition() const
	{
		Matrix alMatrix(m_w, m_h);
		for (int i = 0; i < m_h; ++i)
		{
			for (int j = 0; j < m_w; ++j)
			{
				alMatrix[i][j] = pow((-1), ((i + 1) + (j + 1))) * getMatrixWithoutRowColumn(i, j).calcDet();
			}
		}
		return alMatrix;

	}

	Matrix getRotatedmatrix()
	{
		return getAlgebraAddition().getTranspoted() * (1 / calcDet());
	}
	
	

private:
	unsigned m_w, m_h;
	double** m_matrix;
	using RowType = std::vector<T>;
	using ColumnType = std::vector<RowType>;
	//ColumnType m_matrix;

	T* operator[](int index) 
	{
		if (index < m_h && index >= 0)
		{
			return m_matrix[index];
		}
		else
		{
			return nullptr;
		}
	}

	std::vector<T> getColumn(unsigned index) const
	{
		std::vector<T> column;
		for (int i = 0; i < m_h; ++i)
		{
			column.push_back(m_matrix[i][index]);
		}
		return column;
	}

	std::vector<T> getLine(unsigned index) const
	{
		std::vector<T> line;
		for (int i = 0; i < m_w; ++i)
		{
			line.push_back(m_matrix[index][i]);
		}
		return line;
	}

	template<class T2>
	auto calculateMultiplication(const std::vector<T>& thisLine, const std::vector<T2>& otherColumn) const
	{
		auto result = thisLine[0] * otherColumn[0];

		for (int i = 1; i < thisLine.size(); ++i)
		{
			result += thisLine[i] * otherColumn[i];
		}

		return result;
	}

	Matrix getMatrixWithoutRowColumn(int row, int col) const 
	{
		Matrix newMatrix(m_w - 1, m_h - 1);
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				newMatrix[i][j] = m_matrix[i][j];
			}
		}

		for (int i = 0; i < row; ++i)
		{
			for (int j = col + 1; j < m_w; ++j)
			{
				newMatrix[i][j - 1] = m_matrix[i][j];
			}
		}

		for (int i = row + 1; i < m_h; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				newMatrix[i - 1][j] = m_matrix[i][j];
			}
		}

		for (int i = row + 1; i < m_h; ++i)
		{
			for (int j = col + 1; j < m_w; ++j)
			{
				newMatrix[i - 1][j - 1] = m_matrix[i][j];
			}
		}

		return newMatrix;
	}

	T calcDet() const
	{

		if (m_w == m_h)
		{
			if (m_w == 2)
			{
				return m_matrix[0][0] * m_matrix[1][1] - m_matrix[0][1] * m_matrix[1][0];
			}
			auto copy = Matrix(*this);
			//приведение матрицы к верхнетреугольному виду
			for (int step = 0; step < m_w - 1; step++)
			{
				for (int row = step + 1; row < m_w; row++)
				{
					double coeff = -copy[row][step] / copy[step][step]; //метод Гаусса

					for (int col = step; col < m_w; col++)
					{
						copy[row][col] += copy[step][col] * coeff;
					}
				}
			}
			double Det = 1;
			for (int i = 0; i < m_w; i++)
				Det *= copy[i][i];
			return Det;

		}
	}

	Matrix getTranspoted() const
	{
		Matrix transpotedMatrix(m_w, m_h);
		for (int i = 0; i < m_h; ++i)
		{
			for (int j = 0; j < m_w; ++j)
			{
				transpotedMatrix[j][i] = m_matrix[i][j];
			}
		}
		return transpotedMatrix;
	}
};