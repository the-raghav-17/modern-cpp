#include <stdio.h>
#include <termios.h>
#include <unistd.h>


int main()
{
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);

    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | CS8);
    raw.c_iflag &= ~(IXON | ICRNL | BRKINT | INPCK | ISTRIP);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw); //set new terminal attributes

    raw.c_cc[VTIME] = 5;
    raw.c_cc[VMIN] = 0;


    char ch;
    while (1) {
        int nbytes = read(STDIN_FILENO, &ch, sizeof(ch));
        if (nbytes != 0) {
            printf("Key pressed\n");
            fflush(stdout);
        }
    }
}
