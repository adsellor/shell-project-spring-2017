#include "../shell.h"

int main(int argc, char **argv) {

	char c = '\0';

  while (c != EOF) {
  	printf("[Iterate_Shell] ");
    get_command();
  }
  return 0;
}
