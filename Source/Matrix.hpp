#include "Vector3.hpp"
#include <vector>
#include <iostream>

template<class T>
class Matrix
{
public:
	Matrix(unsigned _w = 3, unsigned _h = 3)
		: m_w(_w)
		, m_h(_h)
	{
		for (int i = 0; i < m_h; ++i)
		{
			m_matrix.push_back(std::vector<T>());
		}
	}

	Matrix(const Matrix& other)
		: m_w(other.m_w)
		, m_h(other.m_h)
		, m_matrix(other.m_matrix)
	{
	}

	void fillRandom()
	{
		for (int i = 0; i < m_h; ++i)
		{
			for (int j = 0; j < m_w; ++j)
			{
				m_matrix[i].push_back(rand() % 10);
			}
		}
	}

	void print() const
	{
		for (auto i : m_matrix)
		{
			for (auto j : i)
			{
				std::cout << j << " ";
			}
			std::cout << std::endl;
		}
	}

	template <class T2>
	Matrix operator*(const Matrix<T2>& other) const 
	{
		if (m_h == other.m_w)
		{
			Matrix<T> result(m_h, m_h);
			for (int i = 0; i < m_h; ++i)
			{
				auto currentLine = getLine(i);
				for (int j = 0; j < other.m_w; ++j)
				{
					result[i]->push_back(calculateMultiplication(currentLine, other.getColumn(j)));
				}
			}
			return result;
		}
		return NULL;
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


private:
	unsigned m_w, m_h;
	using RowType = std::vector<T>;
	using ColumnType = std::vector<RowType>;
	ColumnType m_matrix;

	RowType* operator[](int index) const 
	{
		if (index < m_h && index >= 0)
		{
			auto vec = m_matrix[index];
			return &vec;
		}
		else
		{
			return nullptr;
		}
	}

	
};