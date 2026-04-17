#include "terminal.h"

#include <unistd.h>
#include <sys/ioctl.h>


void Terminal::Controller::set_raw_mode()
{
    // Store current terminal settings first
    tcgetattr(STDIN_FILENO, &orig_termios);
    curr_termios = orig_termios;

    // Disable terminal settings
    curr_termios.c_lflag &= ~(ECHO | ICANON /*| ISIG*/ | IEXTEN | CS8);
    curr_termios.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
    curr_termios.c_oflag &= ~(OPOST);
    curr_termios.c_cflag |= (CS8);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &curr_termios); //set new terminal attributes
}


void Terminal::Controller::restore_orig_term() const
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}


Terminal::Dimensions Terminal::Controller::get_term_dimensions()
{
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

    dimensions.height = ws.ws_row;
    dimensions.width  = ws.ws_col;

    return dimensions;
}
