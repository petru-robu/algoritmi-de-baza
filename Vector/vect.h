#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

class intVector
{

protected:

    int dim;
    int *arr;

    int depth=dim;

public:

    // Constuctori
    intVector()
    {
        dim=0;
    }
    intVector(intVector &a)
    {
        dim=a.dim;
        arr = new int[dim];
        for(int i=0; i<dim; i++)
        {
            arr[i]=a.arr[i];
        }
    }
    intVector(int n)
    {

        arr = new int[n];
        dim = n;
    }
    intVector(int v[], int n)
    {
        dim = n;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = v[i];
        }
    }
    ~intVector()
    {
        cout<<"~destructor chemat~"<<endl;
        delete[] arr;
        dim=0;
    }

    // Operatori
    friend istream &operator>>(istream &in, intVector &v)
    {
        cout << "Introduceti Tabloul : " << endl;
        for (int i = 0; i < v.dim; i++)
            in >> v.arr[i];
        return in;
    }
    friend ostream &operator<<(ostream &out, intVector &v)
    {
        for (int i = 0; i < v.dim; i++)
            out << v.arr[i] << ' ';
        out << endl;
        return out;
    }
    int& operator[](int i)
    {
        if (i >= dim)
        {
            cout << "nu exista acest index!";
        }
        else return arr[i];
    }
    intVector& operator=(intVector &a)
    {
        arr=a.arr;
        dim=a.dim;
        return *this;
    }
    bool operator==(intVector &v)
    {
        if(dim!=v.size()) return false;
        else for(int i=0; i<dim; i++)
                if(arr[i]!=v[i]) return false;
    }
    bool operator!=(intVector &v)
    {
        if(dim==v.size()) return false;
        else for(int i=0; i<dim; i++)
                if(arr[i]!=v[i]) return true;
        return false;
    }

    //Metode
    void display(ostream &out)
    {
        out << endl;
        for (int i = 0; i < dim; i++)
            out << '[' << i << ']' << ' ';
        out << endl;
        out << ' ';
        for (int i = 0; i < dim; i++)
            out << arr[i] << ' ' << ' ' << ' ';
        out << endl << endl;
    }
    int size()
    {
        return dim;
    }
    void del()
    {
        delete[] arr;
        dim=0;
    }
    int getArr(int z[])
    {
        for (int i = 0; i < dim; i++)
        {
            z[i] = arr[i];
        }
        return dim;
    }
    void putArr(int z[],int n)
    {
        delete[] arr;
        dim=n;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = z[i];
        }
    }
    void swapVec(intVector &v2)
    {
        int *tampPoint, tampSize;
        tampPoint = arr;
        tampSize=dim;
        arr=v2.arr;
        dim=v2.dim;
        v2.arr=tampPoint;
        v2.dim=tampSize;
    }
    int max()
    {
      int max;
      max=arr[0];
      for(int i=1;i<dim;i++)
        if(arr[i]>max) max=arr[i];
      return max;
    }

    // Sortari
    void bubbleSort()
    {
        for (int i = 0; i < dim - 1; i++)
            for (int j = 0; j < dim - 1 - i; j++)
                if (arr[j] > arr[j + 1])
                    swap(arr[j], arr[j + 1]);
    }
    void recursiveBubbleSort(int depth)
    {
        if (depth == 1)
            return;
        for (int i = 0; i < depth - 1; i++)
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);

        this->recursiveBubbleSort(depth-1);
    }
    void selectionSort()
    {
        int min_idx;
        for (int i = 0; i < dim - 1; i++)
        {
            min_idx = i;
            for (int j = i + 1; j < dim; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;
            swap(arr[min_idx], arr[i]);
        }
    }
    void insertionSort()
    {
        int i, key, j;
        for (i = 1; i < dim; i++)
        {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[
j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }
    void countingSort()
    {
      int *p = new int[this->max()+1];
      for(int i=0;i<this->max()+1;i++)
        p[i]=0;
      for(int i=0;i<this->max();i++)
        p[arr[i]]++;
      int *r = new int[dim];
      int k=0;
      for(int i=0;i<this->max()+1;i++)
        for(int j=0;j<p[i];j++) {r[k]=i;k++;}
      this->arr=r;
    }


};

class apVector: public intVector
{

public:
    //Constructori
    apVector()
    {
        dim=0;
    }
    apVector(int n)
    {
        arr = new int[n];
        dim=n;
        for(int i=0; i<dim; i++)
            arr[i]=0;
    }
    apVector(apVector &a)
    {
        arr = new int[a.dim];
        dim=a.dim;
        for(int i=0; i<dim; i++)
            arr[i]=a.arr[i];
    }
    apVector(intVector &vec)
    {
      dim=vec.max()+1;
      arr= new int[dim];
      for(int i=0;i<dim;i++) arr[i]=0;
      for(int i=0;i<dim-1;i++)
        arr[vec[i]]++;
    }

    //Metode
    void aparitie(int key)
    {
        arr[key]++;
    }
    void mapArr(intVector &vec)
    {
        this->del();
        dim=vec.max()+1;
        arr= new int[dim];
        for(int i=0;i<dim;i++) arr[i]=0;
        for(int i=0;i<dim-1;i++)
          arr[vec[i]]++;
    }
    void printMapped(ostream &out)
    {
      for(int i=0;i<dim;i++)
        for(int j=0;j<arr[i];j++) out<<i<<' ';
      cout<<endl;
    }

};
