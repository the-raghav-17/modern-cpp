#ifndef TERMINAL_H_
#define TERMINAL_H_


#include <termios.h>


// To modify terminal settings
class Terminal
{
public:
    void set_raw_mode();
    void restore_orig_term();

private:
    struct termios orig_termios {}; // term settings before setting raw mode
    struct termios curr_termios {}; // current term settings
};


#endif // TERMINAL_H_
