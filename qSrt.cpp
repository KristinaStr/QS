#include <iostream>
#include <sstream>
#include <utility>
#include <stdlib.h>

using namespace std;
void Qsort(int *mas,  int i,int j)
{
    int l=i;
    int r=j;
    int razdel=l;
    while(r>=l)
    {
        while((mas[l]<mas[razdel])&&(l<=j)) l++;
        while((mas[r]>mas[razdel])&&(r>=i)) r--;
        if(l<=r)
        {
            swap(mas[l],mas[r]);
            l++;
            r--;
        }
    }
    if(l<j)
        Qsort(mas,l,j);
    if (r>i)
        Qsort(mas,i,r);
}





bool read(int *mas, int k)
{
    string stroka;
    getline(cin, stroka);
    istringstream stream(stroka);
    for (int i = 0; i < k; i++)
    {
        if (!(stream >> mas[i]))
        {
            cout << "Error" << endl;

        }
    }
    if (stream>>k)
    {
        cout<<"Error";
        exit(0);
    }
    return true;
}


int main() {
    int k;
    cin>> k;
    if (k>=0)
    {



        cin.get();
        int *mas = new int[k];
        if (read(mas, k))
        {
            Qsort(mas,0,k-1);
            for (int i = 0; i < k; i++)
            {
                cout << mas[i] << " ";
            }
        }
    }
    else
    {
        cout<<"error";
    }

    return 0;

}
