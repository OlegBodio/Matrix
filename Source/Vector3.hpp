#pragma once


template<class T>
struct Vector3
{
public:
	T m_x, m_y, m_z;
	Vector3(T _x = 0, T _y = 0, T _z = 0)
		: m_x(_x)
		, m_y(_y)
    , m_z(_z)
	{}

  template<class T2>
	Vector3(const Vector3& other)
		: m_x(other.m_x)
		, m_y(other.m_y)
    , m_z(other.m_z)
	{}

	template<class T2>
	Vector3& operator=(const Vector3<T2>& other)
	{
		m_x = other.m_x;
		m_y = other.m_y;
    m_z = other.m_z;
		return *this;
	}

  template<class T2>
	Vector3 operator*(float value)
	{
		return Vector3(m_x * value, m_y * value, m_z * value);
	}

  template<class T2>
	Vector3 operator/(float value)
	{
		return Vector3(m_x /= value, m_y /= value, m_z / value);
	}

  template<class T2>
	Vector3 operator+(float value)
	{
		return Vector3(m_x + value, m_y + value, m_z + value);
	}

  template<class T2>
	Vector3 operator-(float value)
	{
		return Vector3(m_x - value, m_y - value, m_z - value);
	}


	template<class T2>
	Vector3 operator+(Vector3<T2> other)
	{
		return Vector3(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
	}

	template<class T2>
	Vector3 operator-(Vector3<T2> other)
	{
		return Vector3(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z);
	}

	template<class T2>
	Vector3 operator*(Vector3<T2> other)
	{
		return Vector3(m_x * other.m_x, m_y * other.m_y, m_z * other.m_z);
	}

	template<class T2>
	Vector3 operator/(Vector3<T2> other)
	{
		return Vector3(m_x / other.m_x, m_y / other.m_y, m_z / other.m_z);
	}

	
	bool operator==(Vector3& other)
	{
		return (m_x == other.m_x) && (m_y == other.m_y) && (m_z == other.m_z);
	}

	bool operator!=(Vector3& other)
	{
		return (m_x != other.m_x) || (m_y != other.m_y) || (m_z != other.m_z);
	}

};