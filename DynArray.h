#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_ 1

template <class T>
class DynArray
{
public:
    DynArray();
    DynArray(int);
    ~DynArray();

    bool append(T item);
    bool truncate();    //make _nData = _arraySize
    void clear()
    {
        _nData = 0;
    }
    int length() const 
    {
        return _nData;
    }
    bool empty() const
    {
        return _nData == 0;
    }
    const T& operator[](int i) const
    {
        return _pData[i];
    }
    T& operator[](int i)
    {
        return _pData[i];
    }

public:
    T* _pData;
    int _nData;
    int _arraySize;
};

template <class T> DynArray<T> :: DynArray()
{
    _nData = 0;
    _arraySize = 4;
    _pData = new T[_arraySize];
}

template <class T> DynArray<T> :: DynArray(int num)
{
    _nData = 0;
    _arraySize = num;
    _pData = new T[_arraySize];
}

template <class T> DynArray<T> :: ~DynArray()
{
    _nData = 0;
    _arraySize = 0;
    if (_pData != NULL)
    {
        delete [] _pData;
    }
}

template <class T> bool DynArray<T> :: append(T item)
{
    if (_nData == _arraySize)
    {
        int nNewSize = _arraySize * 2;
        T* pNewBlock = new T[_arraySize];
        if (pNewBlock == NULL)
        {
            return false;
        }
        for (int i = 0; i < _nData; i++)
        {
            pNewBlock[i] = _pData[i];
        }
        _arraySize = nNewSize;
        delete [] _pData;
        _pData = pNewBlock;
    }
    _pData[_nData++] = item;
    return true;
}

template <class T> bool DynArray<T> :: truncate()
{
    if (_nData == _arraySize)
    {
        return true;
    }
    _arraySize = _nData;
    T* pTempData= new T[_nData];
    for (int i = 0; i < _nData; i++)
    {
        pTempData[i] = _pData[i];
    }
    delete [] _pData;
    _pData = pTempData;
    return true; 
}

#endif