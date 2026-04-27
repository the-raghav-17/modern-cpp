#ifndef TERMINAL_H_
#define TERMINAL_H_


#include "point.h"

#include <termios.h>
#include <string>


class Terminal
{
    public:
        void  set_raw_mode();
        void  set_read(int vtime, int vmin);
        void  restore_orig_term();

        Point get_term_dimensions() const;   // returns (height, width) of term. window

        void  hide_cursor() const;
        void  unhide_cursor() const;
        Point get_cursor_pos() const;
        void  set_cursor_pos(const Point pos) const;

        void clear_screen() const;
        void print(const std::string str, const Point pos) const;

    private:
        struct termios m_orig_termios {}; // term settings before setting raw mode
        struct termios m_curr_termios {}; // current term settings
};


#endif // TERMINAL_H_
