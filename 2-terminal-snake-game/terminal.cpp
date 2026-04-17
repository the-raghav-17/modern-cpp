#include "terminal.h"

#include <unistd.h>


void Terminal::set_raw_mode()
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


void Terminal::restore_orig_term()
{
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}
