// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size)
  {
    if (sz == 0)
      throw out_of_range("Vector size should be greater than zero");
    if (sz > MAX_VECTOR_SIZE)
        throw out_of_range("Vector size is too large");
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию

  }

  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    //assert(arr != nullptr && "TDynamicVector requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }

  TDynamicVector(const TDynamicVector& v)
  {
     // assert(v.pMem != nullptr && "TDynamicVector ctor requires non-nullptr arg");
      sz = v.sz;
      pMem = new T[sz];
      std::copy(v.pMem, v.pMem + sz, pMem);
  }

  TDynamicVector(TDynamicVector&& v) noexcept
  {
      if (this != &v) {
          pMem = v.pMem;
          sz = v.sz;
          v.pMem = nullptr;
          v.sz = 0;
      }
  }

  ~TDynamicVector()
  {
      delete []pMem;
  }

  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v)
          return *this;
      if (sz != v.sz) {
          T* p = new T[v.sz];
          delete[]pMem;
          sz = v.sz;
          pMem = p;
      }
      std::copy(v.pMem, v.pMem + sz, pMem);
      return *this;
  }

  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      swap(*this, v);
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      if (ind >= sz || ind<0)
          throw -1;
      return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      if (ind >= sz || ind < 0)
          throw - 1;
      return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if (ind >= sz || ind < 0)
          throw - 1;
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind >= sz || ind < 0)
          throw - 1;
      return const pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz)
          return 0;
      for (size_t i = 0; i < sz; i++)
          if (pMem[i] != v.pMem[i])
              return 0;
      return 1;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz)
          return 1;
      for (size_t i = 0; i < sz; i++)
          if (pMem[i] != v.pMem[i])
              return 1;
      return 0;
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++)
          tmp.pMem[i]= pMem[i] + val;
      return tmp;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++)
          tmp.pMem[i] = pMem[i] - val;
      return tmp;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++)
         tmp.pMem[i] = pMem[i] * val;
      return tmp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw - 1;
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++)
         tmp.pMem[i] = pMem[i] + v.pMem[i];
      return tmp;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (sz != v.sz)
          throw - 1;
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++)
          tmp.pMem[i] = pMem[i] - v.pMem[i];
      return tmp;
  }
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
  {
      if (sz != v.sz)
          throw - 1;
      T result = 0;
      for (size_t i = 0; i < sz; i++)
          result += pMem[i] * v.pMem[i];
      return result;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }
  
  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : public TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public: //using TDynamicVector<TDynamicVector<T>>::size;

  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
      if (sz == 0)
          throw out_of_range("Matrix size is 0");
      if (sz > MAX_MATRIX_SIZE)
          throw out_of_range("Matrix size is too large");
      for (size_t i = 0; i < sz; i++)
          pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  // сравнение
  bool operator==(const TDynamicMatrix& m) const //noexcept
  {
      if (m.sz != sz)
          return 0;
      for (int i = 0; i < m.sz; i++) {
          if (m.pMem[i] != pMem[i])
              return 0;
      }
      return 1;
  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      TDynamicMatrix tmp(sz);
      for (int i = 0; i < sz; i++)
          tmp.pMem[i] = pMem[i] * val;
          return tmp;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      TDynamicVector<T> tmp(sz);
      for (int i = 0; i < sz; i++)
          tmp[i] = pMem[i] * v;
      return tmp;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (m.sz != sz)
          throw - 1;
      TDynamicMatrix tmp(sz);
      for (int i = 0; i < sz; i++)
          tmp.pMem[i] = pMem[i] + m.pMem[i];
          return tmp;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      TDynamicMatrix tmp(sz);
      for (int i = 0; i < sz; i++)
          tmp.pMem[i] = pMem[i] - m.pMem[i];
      return tmp;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      TDynamicMatrix tmp(sz);
      for (int i = 0; i < sz; i++)
          for (int j = 0; j < sz; j++)
              for (int k = 0; k < sz; k++)
          tmp.pMem[i][j] += pMem[i][k] * m.pMem[k][j];
      return tmp;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
          istr >> v.pMem[i]; // требуется оператор>> для типа T
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
          ostr << v.pMem[i] << '\n'; // требуется оператор<< для типа T
      return ostr;
  }
};

#endif
