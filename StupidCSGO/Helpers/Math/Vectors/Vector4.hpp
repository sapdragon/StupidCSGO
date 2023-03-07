#pragma once
#include "../../../Core.hpp"
/*
Vector4 is a class that represents a 4d vector, this class implements basic geometric operations, as m_flWell as arefmetic operations m_flWith it.
@SapDragon 26.11.2022
Refactoring: 02.03.2022
*/

struct Vector4_t
{
	/* Fields ( x,y,z,w dots ) */
	f32 m_flX, m_flY, m_flZ, m_flW;

	/* Basic constructors for initializing, reinitializing vectors. */
	Vector4_t() : m_flX(0), m_flY(0), m_flZ(0), m_flW(0) {};
	Vector4_t(f32 x, f32 y, f32 z, f32 w) : m_flX(x), m_flY(y), m_flZ(z), m_flW(w) {};
	Vector4_t(const Vector4_t& vecOther) : m_flX(vecOther.m_flX), m_flY(vecOther.m_flY), m_flZ(vecOther.m_flZ), m_flW(vecOther.m_flW) {};
	
	/* Basic arithmetic operations with vectors. */
	Vector4_t operator+(const Vector4_t& vecOther) const { return Vector4_t(m_flX + vecOther.m_flX, m_flY + vecOther.m_flY, m_flZ + vecOther.m_flZ, m_flW + vecOther.m_flW); };
	Vector4_t operator-(const Vector4_t& vecOther) const { return Vector4_t(m_flX - vecOther.m_flX, m_flY - vecOther.m_flY, m_flZ - vecOther.m_flZ, m_flW - vecOther.m_flW); };
	Vector4_t operator*(const Vector4_t& vecOther) const { return Vector4_t(m_flX * vecOther.m_flX, m_flY * vecOther.m_flY, m_flZ * vecOther.m_flZ, m_flW * vecOther.m_flW); };
	Vector4_t operator/(const Vector4_t& vecOther) const { return Vector4_t(m_flX / vecOther.m_flX, m_flY / vecOther.m_flY, m_flZ / vecOther.m_flZ, m_flW / vecOther.m_flW); };
	
	Vector4_t operator+=(const Vector4_t& vecOther) { m_flX += vecOther.m_flX; m_flY += vecOther.m_flY; m_flZ += vecOther.m_flZ; m_flW += vecOther.m_flW; return *this; };
	Vector4_t operator-=(const Vector4_t& vecOther) { m_flX -= vecOther.m_flX; m_flY -= vecOther.m_flY; m_flZ -= vecOther.m_flZ; m_flW -= vecOther.m_flW; return *this; };
	Vector4_t operator*=(const Vector4_t& vecOther) { m_flX *= vecOther.m_flX; m_flY *= vecOther.m_flY; m_flZ *= vecOther.m_flZ; m_flW *= vecOther.m_flW; return *this; };
	Vector4_t operator/=(const Vector4_t& vecOther) { m_flX /= vecOther.m_flX; m_flY /= vecOther.m_flY; m_flZ /= vecOther.m_flZ; m_flW /= vecOther.m_flW; return *this; };
	
	/* Basic arithmetic operations with scalars. */
	Vector4_t operator+(f32 flScalar) const { return Vector4_t(m_flX + flScalar, m_flY + flScalar, m_flZ + flScalar, m_flW + flScalar); };
	Vector4_t operator-(f32 flScalar) const { return Vector4_t(m_flX - flScalar, m_flY - flScalar, m_flZ - flScalar, m_flW - flScalar); };
	Vector4_t operator*(f32 flScalar) const { return Vector4_t(m_flX * flScalar, m_flY * flScalar, m_flZ * flScalar, m_flW * flScalar); };
	Vector4_t operator/(f32 flScalar) const { return Vector4_t(m_flX / flScalar, m_flY / flScalar, m_flZ / flScalar, m_flW / flScalar); };
	
	Vector4_t operator+=(f32 flScalar) { m_flX += flScalar; m_flY += flScalar; m_flZ += flScalar; m_flW += flScalar; return *this; };
	Vector4_t operator-=(f32 flScalar) { m_flX -= flScalar; m_flY -= flScalar; m_flZ -= flScalar; m_flW -= flScalar; return *this; };
	Vector4_t operator*=(f32 flScalar) { m_flX *= flScalar; m_flY *= flScalar; m_flZ *= flScalar; m_flW *= flScalar; return *this; };
	Vector4_t operator/=(f32 flScalar) { m_flX /= flScalar; m_flY /= flScalar; m_flZ /= flScalar; m_flW /= flScalar; return *this; };
	
	/* Basic geometric operations with vectors. */
	f32 Dot(const Vector4_t& vecOther) const { 
		return (m_flX * vecOther.m_flX + m_flY * vecOther.m_flY + m_flZ * vecOther.m_flZ + m_flW * vecOther.m_flW);
	};

	f32 Length() const
	{
		return sqrt(m_flX * m_flX + m_flY * m_flY + m_flZ * m_flZ + m_flW * m_flW);
	}

	f32 LengthSqr() const
	{
		return (m_flX * m_flX + m_flY * m_flY + m_flZ * m_flZ + m_flW * m_flW);
	}

	Vector4_t Normalized() const
	{
		f32 flLength = Length();
		return Vector4_t(m_flX / flLength, m_flY / flLength, m_flZ / flLength, m_flW / flLength);
	}
	
	Vector4_t Normalize()
	{
		f32 flLength = Length();
		m_flX /= flLength;
		m_flY /= flLength;
		m_flZ /= flLength;
		m_flW /= flLength;
		return *this;
	}

	f32 DistTo(const Vector4_t& vecOther) const
	{
		return (*this - vecOther).Length();
	}

	f32 DistToSqr(const Vector4_t& vecOther) const
	{
		return (*this - vecOther).LengthSqr();
	}
	
	/* Validity methods */
	bool IsValid() const
	{
		return !isfinite(m_flX) && !isfinite(m_flY) && !isfinite(m_flZ) && !isfinite(m_flW);
	}
	
	bool IsZero() const
	{
		return m_flX == 0.0f && m_flY == 0.0f && m_flZ == 0.0f && m_flW == 0.0f;
	}

	/* Vector4_t specific methods. */

	void Clear()
	{
		m_flX = m_flY = m_flZ = m_flW = 0.0f;
	}

	Vector4_t& SetMin(const Vector4_t& vecOther)
	{
		m_flX = fmin(m_flX, vecOther.m_flX);
		m_flY = fmin(m_flY, vecOther.m_flY);
		m_flZ = fmin(m_flZ, vecOther.m_flZ);
		m_flW = fmin(m_flW, vecOther.m_flW);

		return *this;
	}
	
	Vector4_t SetMax(const Vector4_t& vecOther)
	{
		m_flX = fmax(m_flX, vecOther.m_flX);
		m_flY = fmax(m_flY, vecOther.m_flY);
		m_flZ = fmax(m_flZ, vecOther.m_flZ);
		m_flW = fmax(m_flW, vecOther.m_flW);

		return *this;
	}
	
	
};