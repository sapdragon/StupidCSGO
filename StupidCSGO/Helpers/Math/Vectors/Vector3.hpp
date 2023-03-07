#pragma once
#include "../../../Core.hpp"
/*
Vector3_t is a class that represents a vector in 3D dimension, this class implements basic geometric operations, as well as arefmetic operations with it.
@SapDragon 26.11.2022
Refactoring: 02.03.2022
*/

struct Vector3_t
{
	/* Fields ( x, y, z dots )*/
	f32 m_flX, m_flY, m_flZ;

	/* Basic constructors for initializing, reinitializing vectors. */
	Vector3_t() { m_flX = m_flY = m_flZ = 0.0f; }
	Vector3_t(f32 flX, f32 flY, f32 flZ) { m_flX = flX; m_flY = flY; m_flZ = flZ; }
	Vector3_t(f32 flValue) { m_flX = m_flY = m_flZ = flValue; }
	
	/* Basic arithmetic operations with vectors. */
	Vector3_t operator+(const Vector3_t& vecOther) const { return Vector3_t(m_flX + vecOther.m_flX, m_flY + vecOther.m_flY, m_flZ + vecOther.m_flZ); }
	Vector3_t operator-(const Vector3_t& vecOther) const { return Vector3_t(m_flX - vecOther.m_flX, m_flY - vecOther.m_flY, m_flZ - vecOther.m_flZ); }
	Vector3_t operator*(const Vector3_t& vecOther) const { return Vector3_t(m_flX * vecOther.m_flX, m_flY * vecOther.m_flY, m_flZ * vecOther.m_flZ); }
	Vector3_t operator/(const Vector3_t& vecOther) const { return Vector3_t(m_flX / vecOther.m_flX, m_flY / vecOther.m_flY, m_flZ / vecOther.m_flZ); }

	Vector3_t& operator+=(const Vector3_t& vecOther) { m_flX += vecOther.m_flX; m_flY += vecOther.m_flY; m_flZ += vecOther.m_flZ; return *this; }
	Vector3_t& operator-=(const Vector3_t& vecOther) { m_flX -= vecOther.m_flX; m_flY -= vecOther.m_flY; m_flZ -= vecOther.m_flZ; return *this; }
	Vector3_t& operator*=(const Vector3_t& vecOther) { m_flX *= vecOther.m_flX; m_flY *= vecOther.m_flY; m_flZ *= vecOther.m_flZ; return *this; }
	Vector3_t& operator/=(const Vector3_t& vecOther) { m_flX /= vecOther.m_flX; m_flY /= vecOther.m_flY; m_flZ /= vecOther.m_flZ; return *this; }

	/* Basic arithmetic operations with vectors and scalars. */
	Vector3_t operator+(const f32 flScalar) const { return Vector3_t(m_flX + flScalar, m_flY + flScalar, m_flZ + flScalar); }
	Vector3_t operator-(const f32 flScalar) const { return Vector3_t(m_flX - flScalar, m_flY - flScalar, m_flZ - flScalar); }
	Vector3_t operator*(const f32 flScalar) const { return Vector3_t(m_flX * flScalar, m_flY * flScalar, m_flZ * flScalar); }
	Vector3_t operator/(const f32 flScalar) const { return Vector3_t(m_flX / flScalar, m_flY / flScalar, m_flZ / flScalar); }
	
	Vector3_t& operator+=(const f32 flScalar) { m_flX += flScalar; m_flY += flScalar; m_flZ += flScalar; return *this; }
	Vector3_t& operator-=(const f32 flScalar) { m_flX -= flScalar; m_flY -= flScalar; m_flZ -= flScalar; return *this; }
	Vector3_t& operator*=(const f32 flScalar) { m_flX *= flScalar; m_flY *= flScalar; m_flZ *= flScalar; return *this; }
	Vector3_t& operator/=(const f32 flScalar) { m_flX /= flScalar; m_flY /= flScalar; m_flZ /= flScalar; return *this; }
	
	/* Basic comparison operations with vectors. */
	bool operator==(const Vector3_t& vecOther) const { return (m_flX == vecOther.m_flX && m_flY == vecOther.m_flY && m_flZ == vecOther.m_flZ); }
	bool operator!=(const Vector3_t& vecOther) const { return (m_flX != vecOther.m_flX || m_flY != vecOther.m_flY || m_flZ != vecOther.m_flZ); }

	/* Another overloads*/
	f32& operator[](u32 iIndex) { return reinterpret_cast<float*>(this)[iIndex]; }
	f32 operator[](u32 iIndex) const { return ((float*)this)[iIndex]; }

	Vector3_t& operator=(const Vector3_t& vecOther) { m_flX = vecOther.m_flX; m_flY = vecOther.m_flY; m_flZ = vecOther.m_flZ; return *this; }
	Vector3_t operator-() const { return Vector3_t(-m_flX, -m_flY, -m_flZ); }
	


	/* Basic geometric operations with vectors. */
	f32 Dot(const Vector3_t& vecOther) const 
	{ 
		return (m_flX * vecOther.m_flX + m_flY * vecOther.m_flY + m_flZ * vecOther.m_flZ); 
	}

	Vector3_t Cross(const Vector3_t& vecOther) const
	{
		return Vector3_t(m_flY * vecOther.m_flZ - m_flZ * vecOther.m_flY, m_flZ * vecOther.m_flX - m_flX * vecOther.m_flZ, m_flX * vecOther.m_flY - m_flY * vecOther.m_flX);
	}
	
	f32 Length() const
	{
		return sqrt(m_flX * m_flX + m_flY * m_flY + m_flZ * m_flZ);
	}

	f32 LengthSqr() const
	{
		return (m_flX * m_flX + m_flY * m_flY + m_flZ * m_flZ);
	}
	
	Vector3_t Normalized() const
	{
		f32 flLength = Length();
		return Vector3_t(m_flX / flLength, m_flY / flLength, m_flZ / flLength);
	}


	Vector3_t Normalize()
	{
		f32 flLength = Length();
		m_flX /= flLength;
		m_flY /= flLength;
		m_flZ /= flLength;
		return *this;
	}

	f32 DistTo(const Vector3_t& vecOther) const
	{
		return (*this - vecOther).Length();
	}

	f32 DistToSqr(const Vector3_t& vecOther) const
	{
		return (*this - vecOther).LengthSqr();
	}
	
	/* Validity methods */
	
	bool IsValid() const
	{
		return !isinf(m_flX) && !isinf(m_flY) && !isinf(m_flZ);
	}

	bool IsZero() const
	{
		return (m_flX == 0.0f && m_flY == 0.0f && m_flZ == 0.0f);
	}

	/* Vector3_t specific methods. */
	
	void Init(f32 flX, f32 flY, f32 flZ)
	{
		m_flX = flX;
		m_flY = flY;
		m_flZ = flZ;
	}

	void Clear( )
	{
		m_flX = m_flY = m_flZ = 0.0f;
	}
	
	Vector3_t& SetMin(const Vector3_t& vecOther)
	{
		m_flX = fmin(m_flX, vecOther.m_flX);
		m_flY = fmin(m_flY, vecOther.m_flY);
		m_flZ = fmin(m_flZ, vecOther.m_flZ);
		return *this;
	}

	Vector3_t& SetMax(const Vector3_t& vecOther)
	{
		m_flX = fmax(m_flX, vecOther.m_flX);
		m_flY = fmax(m_flY, vecOther.m_flY);
		m_flZ = fmax(m_flZ, vecOther.m_flZ);
		return *this;
	}
};

struct __declspec(align(16))  Vector3_tAligned : public Vector3_t
{
	/* Constructors */
	Vector3_tAligned() {}
	Vector3_tAligned(f32 flX, f32 flY, f32 flZ)
	{
		Init(flX, flY, flZ);
	}

	explicit Vector3_tAligned(const Vector3_t& vecOther)
	{
		Init(vecOther.m_flX, vecOther.m_flY, vecOther.m_flZ);
	}

	/* Copy overloads */
	Vector3_tAligned& operator=(const Vector3_t& vecOther)
	{
		Init(vecOther.m_flX, vecOther.m_flY, vecOther.m_flZ);
		return *this;
	}

	Vector3_tAligned& operator=(const Vector3_tAligned& vecOther)
	{
		Init(vecOther.m_flX, vecOther.m_flY, vecOther.m_flZ);
		return *this;
	}
};