#include "numeric.h"
#include <iostream>

using namespace std;

template <class T>
templatedemo<T>::templatedemo():_value(0)
{

}

template<class T>
templatedemo<T>::templatedemo(T value):_value(value)
{

}

template<class T>
templatedemo<T>::templatedemo(const templatedemo& num):_value(num._value)
{

}

template<class T>
templatedemo<T>::~templatedemo()
{

}

template<
