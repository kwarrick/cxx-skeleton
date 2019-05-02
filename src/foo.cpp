#include <getopt.h>

#include <iostream>

#include "foo/bar.hpp"

char *program_name;
static char const short_opts[] = "h"; // NOLINT: POSIX getopt
static struct option long_opts[] = {  // NOLINT
    {"help", no_argument, NULL, 'h'}, // NOLINT
    {NULL, 0, NULL, 0}};              // NOLINT

static void usage(std::ostream &out, int status) {
  out << "Usage: " << program_name << " [option(s)] [file]\n"
      << "Options:\n"
      << "   -h, --help                   display this help and exit\n";
  exit(status);
}

int main(int argc, char *argv[]) {
  // Parse command line options
  int optc;
  program_name = argv[0]; // NOLINT,NOLINTNEXTLINE: getopt
  while ((optc = getopt_long(argc, argv, short_opts, long_opts, NULL)) != -1) {
    switch (optc) {
    case 'h':
      usage(std::cerr, 0);
      break;
    }
  }

  bar();
  return 0;
}
