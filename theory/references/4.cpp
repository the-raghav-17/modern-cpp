int main()
{
    // trying to modify a const lvalue using a 
    // const lvalue reference is an error

    const int x{ 5 };
    const int& ref { x };

    ref = 100;
}
