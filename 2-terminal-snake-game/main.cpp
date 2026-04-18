#include "terminal.h"

#include <iostream>


int main()
{
    Terminal term{};
    term.set_raw_mode();
    term.hide_cursor();

    auto dimensions = term.get_term_dimensions();

    std::cout << "(" << dimensions.x
        << ", " << dimensions.y << ")\n";

    term.unhide_cursor();
    term.restore_orig_term();
}
