#include "Vector.h"

#include <cmath>

using namespace std;

Vector::Vector(){
    x = 0;
    y = 0;
    z = 0;
}

Vector & Vector::operator=(const Vector & v){
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    return *this;
}

Vector & Vector::operator+=(const Vector & v){
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    return *this;
}

Vector::Vector(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector Vector::operator+(const Vector & v) {
    return Vector(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vector Vector::operator-(const Vector & v) {
    return Vector(this->x - v.x, this->y - v.y, this->z - v.z);
}

Vector Vector::operator-() {
    return Vector(- this->x, - this->y, - this->z);
}

Vector Vector::operator/(const Vector & v) {
    Vector result = Vector(this->x/v.x, this->y/v.y, this->z/v.z);
    return result;
}

Vector Vector::operator*(double num) {
    Vector result = Vector(this->x * num, this->y * num, this->z * num);
    return result;
}

double Vector::operator*(const Vector & v) {
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

Vector Vector::operator^(Vector v) {
    return this->cross(v);
}

bool Vector::similar(Vector & v, double eps){
    return (*this - (Vector(1,1,1)*eps) < v) && (v < *this + (Vector(1,1,1)*eps));
}

bool Vector::operator==(const Vector & v){
    return ((this->x == v.x) && (this->y == v.y) && (this->z == v.z));
}

bool Vector::operator!=(const Vector & v){
    return !(*this == v);
}

bool Vector::operator<(const Vector & v){
    return ((this->x < v.x) && (this->y < v.y) && (this->z < v.z));
}

bool Vector::operator<=(const Vector & v){
    return ((this->x <= v.x) && (this->y <= v.y) && (this->z <= v.z));
}

bool Vector::operator>=(const Vector & v){
    return ((this->x >= v.x) && (this->y >= v.y) && (this->z >= v.z));
}

bool Vector::operator>(const Vector & v){
    return ((this->x > v.x) && (this->y > v.y) && (this->z > v.z));
}

Vector Vector::cross(const Vector & v){
    return Vector((this->y * v.z) - (this->z * v.y),
                  (this->z * v.x) - (this->x * v.z),
                  (this->x * v.y) - (this->y * v.x));
}

Vector::~Vector(){
    //dtor
}

Vector Vector::Rejection(Vector & v){
    return *this - this->Projection(v);
}

Vector Vector::Projection(Vector & v){
    return v*(((*this) * v)/v.Square());
}

double Vector::Square(){
    return (*this)*(*this);
}

Vector Vector::UnitVector(){
    return (*this)*(1/sqrt(this->Square()));
}

double Vector::Norm(){
    return sqrt(this->Square());
}

ostream & operator<<(ostream & os, Vector & v) {
    return os << "(" << v.x << "," << v.y << "," << v.z << ")";
}

void Vector::clear(){
    this->x = this->y = this->z = 0;
}

void ManyVector::clear(){
    this->v1.clear();
    this->v2.clear();
    this->v3.clear();
    this->v4.clear();
    this->v5.clear();
    this->v6.clear();
}

void ManyVector::unzip(ManyVector * m){
}

void ManyVector::average(ManyVector & p1, ManyVector & p2, ManyVector & p3, ManyVector & p4, ManyVector & result) {
    result.v1 = (p1.v1 + p2.v1 + p3.v1 + p4.v1)*(1/4.0);
    result.v2 = (p1.v2 + p2.v2 + p3.v2 + p4.v2)*(1/4.0);
    result.v3 = (p1.v3 + p2.v3 + p3.v3 + p4.v3)*(1/4.0);
    result.v4 = (p1.v4 + p2.v4 + p3.v4 + p4.v4)*(1/4.0);
    result.v5 = (p1.v5 + p2.v5 + p3.v5 + p4.v5)*(1/4.0);
    result.v6 = (p1.v6 + p2.v6 + p3.v6 + p4.v6)*(1/4.0);
}
