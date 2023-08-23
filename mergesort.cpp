#include "mergesort.h"

mergesort::mergesort(uint (&_arr)[ARR_LEN]) : arr(_arr) {}

void mergesort::sort(int l, int r)
{
    if (l >= r)
        return;
    int m = (l + r - 1) / 2;
    sort(l, m);
    sort(m + 1, r);
    merge(l, m, r);
}

void mergesort::merge(int l, int m, int r)
{
    int nl = m - l + 1;
    int nr = r - m;

    // создаем временные массивы
    int left[nl], right[nr];

    // копируем данные во временные массивы
    for (int i = 0; i < nl; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < nr; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0;
    int k = l; // начало левой части

    while (i < nl && j < nr)
    {
        // записываем минимальные элементы обратно во входной массив
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    // записываем оставшиеся элементы левой части
    while (i < nl)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    // записываем оставшиеся элементы правой части
    while (j < nr)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}