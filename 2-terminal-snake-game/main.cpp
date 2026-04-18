#include "terminal.h"

#include <iostream>


int main()
{
    Terminal term{};
    term.set_raw_mode();
    term.hide_cursor();

    auto dimensions = term.get_term_dimensions();

    Point pos = {100, 10};
    term.set_cursor_pos(pos);

    std::cout << "(" << dimensions.x
        << ", " << dimensions.y << ")\n";

    term.unhide_cursor();
    term.restore_orig_term();
}
