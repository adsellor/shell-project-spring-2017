#include "../shell.h"

int main(int argc, char **argv, char **envp) {

  char c = '\0';

  while (c != EOF) {
    printf("[Iterate_Shell] ");
    get_command();
    switch(get_status()) {
      case 2 :
        execve("/bin/ls", argv, envp);
        break;
      default:
        break;
    }
  }
  return 0;
}
