#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int main() {
  struct termios old_termios, new_termios;

  // Save the current terminal settings
  tcgetattr(0, &old_termios);

  // Set the terminal in raw mode
  new_termios = old_termios;
  new_termios.c_lflag &= ~ICANON;
  new_termios.c_lflag &= ~ECHO;
  tcsetattr(0, TCSANOW, &new_termios);

  // Send the Control-N character
  char ctrl_n = 0x0E;
  write(0, &ctrl_n, 1);

  // Restore the original terminal settings
  tcsetattr(0, TCSANOW, &old_termios);

  return 0;
}