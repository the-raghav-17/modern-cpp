/*
 * l-value references
 */


int main()
{
    int x { 100 };    // x -> l-value,  100 -> r-value

    int &ref { x };   // ref is a reference to non-const l-values
    
    // int &ref2 { 100 };   // error: can't assign r-values to 
                            // non-const l-value references

    const int &ref3 { 100 }; // ok

    const int y { 123 };
    
    // int &ref4 { y }; // error: can't assign const l-values to non-const
                        // l-value references

    const int &ref5 { y }; // ok

    /*
     * non-const l-value reference can only refer to non-const l-values
     
     * const l-value reference can refer to:
       1. non-const l-values
       2. const l-values
       3. r-values

    */
}
