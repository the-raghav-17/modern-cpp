#ifndef TERMINAL_H_
#define TERMINAL_H_


#include "point.h"

#include <termios.h>


class Terminal
{
    public:
        void  set_raw_mode();
        void  restore_orig_term();

        Point get_term_dimensions() const;   // returns (height, width) of term. window

        void  hide_cursor() const;
        void  unhide_cursor() const;
        Point get_cursor_pos() const;

    private:
        struct termios orig_termios {}; // term settings before setting raw mode
        struct termios curr_termios {}; // current term settings
};


#endif // TERMINAL_H_
