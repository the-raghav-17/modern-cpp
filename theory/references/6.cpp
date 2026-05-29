void fun(int& x)
{
    x++;
}

int main()
{
    fun(100);

    const int y { 123 };
    fun(y);

    // only correct way of passing by reference
    int z { 456 };
    fun(z);
}
