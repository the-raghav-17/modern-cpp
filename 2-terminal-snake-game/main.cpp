#include "terminal.h"

#include <iostream>


int main()
{
    Terminal::Controller term{};
    term.set_raw_mode();

    Terminal::Dimensions dimensions =
        term.get_term_dimensions();

    std::cout << "(" << dimensions.height
        << ", " << dimensions.width << ")\n";

    term.restore_orig_term();
}
