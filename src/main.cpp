#include <iostream>

using namespace std;

template<typename T> class array
{
private:
    int size;
    T *data;
public:
    array(int _size,T *_data)
    {
        size = _size;
        data = new T[size];
        for(int i=0; i<size;i++)
        {
            data[i] = _data[i];
        }
    }

    void print()
    {
        cout<<size<<":";
        for(int i=0;i<size;i++)
        {
            cout<<data[i]<<'\t';
        }
        cout<<endl;
    }
};

// From min -> max
int adjust_array(int *data,int left,int right)
{
    int temp;
    temp = data[left];
    while(left<right)
    {
        while(left<right && data[right]>=temp)
        {
            right--;
        }
        if (left<right)
        {
            data[left] = data[right];
        }

        while(left<right && data[left]<=temp)
        {
            left++;
        }

        if (left<right)
        {
            data[right] = data[left];
        }
    }
    data[left] = temp;
    return left;
}

void quicksort(int *data,int left,int right)
{
    int middle;
    if(left < right)
    {
        middle = adjust_array(data,left,right);
        quicksort(data,left,middle-1);
        quicksort(data,middle+1,right);
    }
}

const int SIZE_OF_ARRAY = 10;
int main(int argc,char ** argv)
{
    int src_data[SIZE_OF_ARRAY]={7,8,9,6,1,2,5,4,3,0};
    quicksort(src_data,0,9);
    array<int> a(SIZE_OF_ARRAY,src_data);
    a.print();
    return 0;
}
