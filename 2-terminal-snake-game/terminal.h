#ifndef TERMINAL_H_
#define TERMINAL_H_


#include <termios.h>


namespace Terminal {
    struct Dimensions
    {
        int width, height;
    };

    class Controller
    {
    public:
        void set_raw_mode();
        void restore_orig_term() const;
        Dimensions get_term_dimensions();

    private:
        struct termios orig_termios {}; // term settings before setting raw mode
        struct termios curr_termios {}; // current term settings
        Dimensions dimensions {};
    };
};


#endif // TERMINAL_H_
