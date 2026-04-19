#include "terminal.h"
#include "point.h"

#include <string>
#include <unistd.h>
#include <sys/ioctl.h>


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
    curr_termios = orig_termios;
}


Point Terminal::get_term_dimensions() const
{
    struct winsize ws;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);

    Point dimensions = {ws.ws_row, ws.ws_col};
    return dimensions;
}


void Terminal::hide_cursor() const
{
    char buf[] = "\x1b[?25l";
    write(STDOUT_FILENO, buf, sizeof(buf));
}


void Terminal::unhide_cursor() const
{
    char buf[] = "\x1b[?25h";
    write(STDOUT_FILENO, buf, sizeof(buf));
}


void Terminal::set_cursor_pos(Point pos) const
{
    std::string cmd { "\x1b[" };
    std::string x_pos { std::to_string(pos.x) };
    std::string y_pos { std::to_string(pos.y) };

    // \x1b[<y>;<x>H     -- reposition cursor
    cmd += y_pos + ";" + x_pos + "H";

    write(STDOUT_FILENO, cmd.c_str(), cmd.size());
}


void Terminal::clear_screen() const
{
    char buf[] = "\x1b[2J";
    write(STDOUT_FILENO, buf, sizeof(buf));
}


void Terminal::print(const std::string str, const Point pos) const
{
    set_cursor_pos(pos);
    write(STDOUT_FILENO, str.c_str(), str.size());
}
