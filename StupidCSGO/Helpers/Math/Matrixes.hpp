#pragma once
#include "../../Core.hpp"
#include "Vectors/Vector3.hpp"
template < int N, int M > 
struct Matrix_t
{
	/* Basic array */
	f32 m_aMatrix[N][M] = {};

	/* Constructors */
	Matrix_t() { memset(m_aMatrix, 0, sizeof(m_aMatrix)); };
	Matrix_t(f32* pMatrix) { memcpy(m_aMatrix, pMatrix, sizeof(m_aMatrix)); };
	Matrix_t(const Matrix_t& Other) { memcpy(m_aMatrix, Other.m_aMatrix, sizeof(m_aMatrix)); };
	Matrix_t(const Vector3_t& vecForward, const Vector3_t& vecRight, const Vector3_t& vecUp, const Vector3_t& vecOrigin)
	{
		m_aMatrix[0][0] = vecRight.m_flX;
		m_aMatrix[0][1] = vecRight.m_flY;
		m_aMatrix[0][2] = vecRight.m_flZ;
		m_aMatrix[0][3] = vecOrigin.m_flX;

		m_aMatrix[1][0] = vecUp.m_flX;
		m_aMatrix[1][1] = vecUp.m_flY;
		m_aMatrix[1][2] = vecUp.m_flZ;
		m_aMatrix[1][3] = vecOrigin.m_flY;

		m_aMatrix[2][0] = vecForward.m_flX;
		m_aMatrix[2][1] = vecForward.m_flY;
		m_aMatrix[2][2] = vecForward.m_flZ;
		m_aMatrix[2][3] = vecOrigin.m_flZ;
	}
	
	/* Copy operators */
	Matrix_t& operator=(const Matrix_t& Other) { memcpy(m_aMatrix, Other.m_aMatrix, sizeof(m_aMatrix)); return *this; };
	Matrix_t& operator=(f32* pMatrix) { memcpy(m_aMatrix, pMatrix, sizeof(m_aMatrix)); return *this; };
	
	/* Array operators */
	f32* operator[](int i) { return m_aMatrix[i]; };
	
	/* Basic arithmetic operations with Matrixes. */
	Matrix_t operator*(const Matrix_t& Other) const
	{
		Matrix_t Result;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				Result[i][j] = 0.0f;
				for (int k = 0; k < N; k++)
				{
					Result[i][j] += m_aMatrix[i][k] * Other.m_aMatrix[k][j];
				}
			}
		}
		return Result;
	};

	Matrix_t operator+(const Matrix_t& Other) const
	{
		Matrix_t Result;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				Result[i][j] = m_aMatrix[i][j] + Other.m_aMatrix[i][j];
			}
		}
		return Result;
	};

	Matrix_t operator-(const Matrix_t& Other) const
	{
		Matrix_t Result;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				Result[i][j] = m_aMatrix[i][j] - Other.m_aMatrix[i][j];
			}
		}
		return Result;
	};

	Matrix_t operator *= (const Matrix_t& Other) { return *this = *this * Other; };
	Matrix_t operator += (const Matrix_t& Other) { return *this = *this + Other; };
	Matrix_t operator -= (const Matrix_t& Other) { return *this = *this - Other; };
	
	/* Basic arithmetic operations with vectors */
	Vector3_t operator*(const Vector3_t& vecAnother) const
	{
		Vector3_t Result;
		for (int i = 0; i < N; i++)
		{
			Result[i] = 0.0f;
			for (int j = 0; j < M; j++)
			{
				Result[i] += m_aMatrix[i][j] * vecAnother[j];
			}
		}
		return Result;
	};

	/* Set functions */
	void SetForward(const Vector3_t& vecForward)
	{
		m_aMatrix[0][0] = vecForward.m_flX;
		m_aMatrix[1][0] = vecForward.m_flY;
		m_aMatrix[2][0] = vecForward.m_flZ;
	}

	void SetUp(const Vector3_t& vecUp)
	{
			m_aMatrix[0][1] = vecUp.m_flX;
			m_aMatrix[1][1] = vecUp.m_flY;
			m_aMatrix[2][1] = vecUp.m_flZ;
	}

	void SetRight(const Vector3_t& vecRight)
	{
		m_aMatrix[0][2] = vecRight.m_flX;
		m_aMatrix[1][2] = vecRight.m_flY;
		m_aMatrix[2][2] = vecRight.m_flZ;
	}

	void SetOrigin(const Vector3_t& vecOrigin)
	{
		m_aMatrix[0][3] = vecOrigin.m_flX;
		m_aMatrix[1][3] = vecOrigin.m_flY;
		m_aMatrix[2][3] = vecOrigin.m_flZ;
	}

	/* Get functions */
	Vector3_t GetForward() const { return Vector3_t(m_aMatrix[0][0], m_aMatrix[1][0], m_aMatrix[2][0]); };
	Vector3_t GetUp() const { return Vector3_t(m_aMatrix[0][1], m_aMatrix[1][1], m_aMatrix[2][1]); };
	Vector3_t GetRight() const { return Vector3_t(m_aMatrix[0][2], m_aMatrix[1][2], m_aMatrix[2][2]); };
	Vector3_t GetOrigin() const { return Vector3_t(m_aMatrix[0][3], m_aMatrix[1][3], m_aMatrix[2][3]); };
	
	float* Base() { return &m_aMatrix[0][0]; };

	/* Another functions */
	void Clear( )
	{
		memset(m_aMatrix, 0, sizeof(m_aMatrix));
	}

	void Identity()
	{
		Clear();
		m_aMatrix[0][0] = 1.0f;
		m_aMatrix[1][1] = 1.0f;
		m_aMatrix[2][2] = 1.0f;
	}
};

typedef Matrix_t<3, 4> Matrix3x4_t;

