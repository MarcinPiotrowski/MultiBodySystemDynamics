#define _USE_MATH_DEFINES

#include <math.h>

// ----------------------------------------------------------------------------------------------------------------------------

class vecG2
{
public:
	union{
		struct{float x, y;};
		struct{float s, t;};
		struct{float r, g;};
	};
        vecG2() : x(0.0f), y(0.0f){}
        ~vecG2(){}
        vecG2(float num) : x(num), y(num){}
        vecG2(float x, float y) : x(x), y(y){}
        vecG2(const vecG2 &u) : x(u.x), y(u.y){}
        vecG2& operator = (const vecG2 &u){x = u.x; y = u.y; return *this;}
        vecG2 operator - (){return vecG2(-x, -y);}
	float* operator & (){return (float*)this;};
        vecG2& operator += (float num){x += num; y += num; return *this;}
        vecG2& operator += (const vecG2 &u){x += u.x; y += u.y; return *this;}
        vecG2& operator -= (float num){x -= num; y -= num; return *this;}
        vecG2& operator -= (const vecG2 &u){x -= u.x; y -= u.y; return *this;}
        vecG2& operator *= (float num){x *= num; y *= num; return *this;}
        vecG2& operator *= (const vecG2 &u){x *= u.x; y *= u.y; return *this;}
        vecG2& operator /= (float num){x /= num; y /= num; return *this;}
        vecG2& operator /= (const vecG2 &u){x /= u.x; y /= u.y; return *this;}
        friend vecG2 operator + (const vecG2 &u, float num){return vecG2(u.x + num, u.y + num);}
        friend vecG2 operator + (float num, const vecG2 &u){return vecG2(num + u.x, num + u.y);}
        friend vecG2 operator + (const vecG2 &u, const vecG2 &v){return vecG2(u.x + v.x, u.y + v.y);}
        friend vecG2 operator - (const vecG2 &u, float num){return vecG2(u.x - num, u.y - num);}
        friend vecG2 operator - (float num, const vecG2 &u){return vecG2(num - u.x, num - u.y);}
        friend vecG2 operator - (const vecG2 &u, const vecG2 &v){return vecG2(u.x - v.x, u.y - v.y);}
        friend vecG2 operator * (const vecG2 &u, float num){return vecG2(u.x * num, u.y * num);}
        friend vecG2 operator * (float num, const vecG2 &u){return vecG2(num * u.x, num * u.y);}
        friend vecG2 operator * (const vecG2 &u, const vecG2 &v){return vecG2(u.x * v.x, u.y * v.y);}
        friend vecG2 operator / (const vecG2 &u, float num){return vecG2(u.x / num, u.y / num);}
        friend vecG2 operator / (float num, const vecG2 &u){return vecG2(num / u.x, num / u.y);}
        friend vecG2 operator / (const vecG2 &u, const vecG2 &v){return vecG2(u.x / v.x, u.y / v.y);}
};

// ----------------------------------------------------------------------------------------------------------------------------

class vecG3
{
public:
	union{
		struct{float x, y, z;};
		struct{float s, t, p;};
		struct{float r, g, b;};
	};
        vecG3() : x(0.0f), y(0.0f), z(0.0f){}
        ~vecG3(){}
        vecG3(float num) : x(num), y(num), z(num){}
        vecG3(float x, float y, float z) : x(x), y(y), z(z){}
        vecG3(const vecG2 &u, float z) : x(u.x), y(u.y), z(z){}
        vecG3(const vecG3 &u) : x(u.x), y(u.y), z(u.z){}
        vecG3& operator = (const vecG3 &u){x = u.x; y = u.y; z = u.z; return *this;}
        vecG3 operator - (){return vecG3(-x, -y, -z);}
	float* operator & (){return (float*)this;}
        operator vecG2 (){return *(vecG2*)this;}
        vecG3& operator += (float num){x += num; y += num; z += num; return *this;}
        vecG3& operator += (const vecG3 &u){x += u.x; y += u.y; z += u.z; return *this;}
        vecG3& operator -= (float num){x -= num; y -= num; z -= num; return *this;}
        vecG3& operator -= (const vecG3 &u){x -= u.x; y -= u.y; z -= u.z; return *this;}
        vecG3& operator *= (float num){x *= num; y *= num; z *= num; return *this;}
        vecG3& operator *= (const vecG3 &u){x *= u.x; y *= u.y; z *= u.z; return *this;}
        vecG3& operator /= (float num){x /= num; y /= num; z /= num; return *this;}
        vecG3& operator /= (const vecG3 &u){x /= u.x; y /= u.y; z /= u.z; return *this;}
        friend vecG3 operator + (const vecG3 &u, float num){return vecG3(u.x + num, u.y + num, u.z + num);}
        friend vecG3 operator + (float num, const vecG3 &u){return vecG3(num + u.x, num + u.y, num + u.z);}
        friend vecG3 operator + (const vecG3 &u, const vecG3 &v){return vecG3(u.x + v.x, u.y + v.y, u.z + v.z);}
        friend vecG3 operator - (const vecG3 &u, float num){return vecG3(u.x - num, u.y - num, u.z - num);}
        friend vecG3 operator - (float num, const vecG3 &u){return vecG3(num - u.x, num - u.y, num - u.z);}
        friend vecG3 operator - (const vecG3 &u, const vecG3 &v){return vecG3(u.x - v.x, u.y - v.y, u.z - v.z);}
        friend vecG3 operator * (const vecG3 &u, float num){return vecG3(u.x * num, u.y * num, u.z * num);}
        friend vecG3 operator * (float num, const vecG3 &u){return vecG3(num * u.x, num * u.y, num * u.z);}
        friend vecG3 operator * (const vecG3 &u, const vecG3 &v){return vecG3(u.x * v.x, u.y * v.y, u.z * v.z);}
        friend vecG3 operator / (const vecG3 &u, float num){return vecG3(u.x / num, u.y / num, u.z / num);}
        friend vecG3 operator / (float num, const vecG3 &u){return vecG3(num / u.x, num / u.y, num / u.z);}
        friend vecG3 operator / (const vecG3 &u, const vecG3 &v){return vecG3(u.x / v.x, u.y / v.y, u.z / v.z);}
};

// ----------------------------------------------------------------------------------------------------------------------------

class vecG4
{
public:
	union{
		struct{float x, y, z, w;};
		struct{float s, t, p, q;};
		struct{float r, g, b, a;};
	};
        vecG4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f){}
        ~vecG4(){}
        vecG4(float num) : x(num), y(num), z(num), w(num){}
        vecG4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w){}
        vecG4(const vecG2 &u, float z, float w) : x(u.x), y(u.y), z(z), w(w){}
        vecG4(const vecG3 &u, float w) : x(u.x), y(u.y), z(u.z), w(w){}
        vecG4(const vecG4 &u) : x(u.x), y(u.y), z(u.z), w(u.w){}
        vecG4& operator = (const vecG4 &u){x = u.x; y = u.y; z = u.z; w = u.w; return *this;}
        vecG4 operator - (){return vecG4(-x, -y, -z, -w);}
	float* operator & (){return (float*)this;}
        operator vecG2 (){return *(vecG2*)this;}
        operator vecG3 (){return *(vecG3*)this;}
        vecG4& operator += (float num){x += num; y += num; z += num; w += num; return *this;}
        vecG4& operator += (const vecG4 &u){x += u.x; y += u.y; z += u.z; w += u.w; return *this;}
        vecG4& operator -= (float num){x -= num; y -= num; z -= num; w -= num; return *this;}
        vecG4& operator -= (const vecG4 &u){x -= u.x; y -= u.y; z -= u.z; w -= u.w; return *this;}
        vecG4& operator *= (float num){x *= num; y *= num; z *= num; w *= num; return *this;}
        vecG4& operator *= (const vecG4 &u){x *= u.x; y *= u.y; z *= u.z; w *= u.w; return *this;}
        vecG4& operator /= (float num){x /= num; y /= num; z /= num; w /= num; return *this;}
        vecG4& operator /= (const vecG4 &u){x /= u.x; y /= u.y; z /= u.z; w /= u.w; return *this;}
        friend vecG4 operator + (const vecG4 &u, float num){return vecG4(u.x + num, u.y + num, u.z + num, u.w + num);}
        friend vecG4 operator + (float num, const vecG4 &u){return vecG4(num + u.x, num + u.y, num + u.z, num + u.w);}
        friend vecG4 operator + (const vecG4 &u, const vecG4 &v){return vecG4(u.x + v.x, u.y + v.y, u.z + v.z, u.w + v.w);}
        friend vecG4 operator - (const vecG4 &u, float num){return vecG4(u.x - num, u.y - num, u.z - num, u.w - num);}
        friend vecG4 operator - (float num, const vecG4 &u){return vecG4(num - u.x, num - u.y, num - u.z, num - u.w);}
        friend vecG4 operator - (const vecG4 &u, const vecG4 &v){return vecG4(u.x - v.x, u.y - v.y, u.z - v.z, u.w - v.w);}
        friend vecG4 operator * (const vecG4 &u, float num){return vecG4(u.x * num, u.y * num, u.z * num, u.w * num);}
        friend vecG4 operator * (float num, const vecG4 &u){return vecG4(num * u.x, num * u.y, num * u.z, num * u.w);}
        friend vecG4 operator * (const vecG4 &u, const vecG4 &v){return vecG4(u.x * v.x, u.y * v.y, u.z * v.z, u.w * v.w);}
        friend vecG4 operator / (const vecG4 &u, float num){return vecG4(u.x / num, u.y / num, u.z / num, u.w / num);}
        friend vecG4 operator / (float num, const vecG4 &u){return vecG4(num / u.x, num / u.y, num / u.z, num / u.w);}
        friend vecG4 operator / (const vecG4 &u, const vecG4 &v){return vecG4(u.x / v.x, u.y / v.y, u.z / v.z, u.w / v.w);}
};

// ----------------------------------------------------------------------------------------------------------------------------

class matG44
{
public:
	float M[16];
        matG44();
        ~matG44();
        matG44(const matG44 &Matrix);
        matG44& operator = (const matG44 &Matrix);
	float& operator [] (int Index);
	float* operator & ();
        friend matG44 operator * (const matG44 &Matrix1, const matG44 &Matrix2);
        friend vecG2 operator * (const matG44 &Matrix, const vecG2 &Vector);
        friend vecG3 operator * (const matG44 &Matrix, const vecG3 &Vector);
        friend vecG4 operator * (const matG44 &Matrix, const vecG4 &Vector);
};

// ----------------------------------------------------------------------------------------------------------------------------

float dot(const vecG2 &u, const vecG2 &v);
float length(const vecG2 &u);
float length2(const vecG2 &u);
vecG2 normalize(const vecG2 &u);
vecG2 reflect(const vecG2 &i, const vecG2 &n);
vecG2 refract(const vecG2 &i, const vecG2 &n, float eta);
vecG2 rotate(const vecG2 &u, float angle);

// ----------------------------------------------------------------------------------------------------------------------------

vecG3 cross(const vecG3 &u, const vecG3 &v);
float dot(const vecG3 &u, const vecG3 &v);
float length(const vecG3 &u);
float length2(const vecG3 &u);
vecG3 mix(const vecG3 &u, const vecG3 &v, float a);
vecG3 normalize(const vecG3 &u);
vecG3 reflect(const vecG3 &i, const vecG3 &n);
vecG3 refract(const vecG3 &i, const vecG3 &n, float eta);
vecG3 rotate(const vecG3 &u, float angle, const vecG3 &v);

// ----------------------------------------------------------------------------------------------------------------------------

matG44 BiasMatrix();
matG44 BiasMatrixInverse();
matG44 ViewMatrix(const vecG3 &x, const vecG3 &y, const vecG3 &z, const vecG3 &position);
matG44 ViewMatrixInverse(matG44 &V);
matG44 OrthogonalProjectionMatrix(float left, float right, float bottom, float top, float n, float f);
matG44 PerspectiveProjectionMatrix(float fovy, float x, float y, float n, float f);
matG44 PerspectiveProjectionMatrixInverse(matG44 &PP);
matG44 RotationMatrix(float angle, const vecG3 &u);
matG44 ScaleMatrix(float x, float y, float z);
matG44 TranslationMatrix(float x, float y, float z);
