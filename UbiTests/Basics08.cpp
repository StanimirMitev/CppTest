/*  C++ Basics 8
    
    1.	Write a specialization for type int for the 'add' template function.
    2.	Give an example of partial template specialization for class 'Fu' . For example if both array1 and array2 store pointers make them twice as big.
*/

template <typename T> T add(T a, T b)
{
    return a + b;
}

template <typename T, typename U, int n> class Fu
{
public:
    T array1[n];
    U array2[n];

    void f() { cout << "Fu<T,U,n>"; }
};

void main(int argc, char* argv[])
{

}