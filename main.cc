#include "tools/cpp/runfiles/runfiles.h"
#include <fstream>
#include <iostream>
#include <string>

using bazel::tools::cpp::runfiles::Runfiles;

int main(int argc, char **argv) {
  std::string error;
  std::unique_ptr<Runfiles> runfiles(Runfiles::Create(argv[0], &error));
  if (runfiles == nullptr) {
    std::cout << "Failure creating Runfiles: " << error;
    return 1;
  }
  std::string path = runfiles->Rlocation("bugs_macos_cliapp_runfiles/test.txt");

  std::string line;
  std::ifstream myfile(path);
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      std::cout << line << '\n';
    }
    myfile.close();
  } else {
    std::cout << "Unable to open file " << path;
    return 1;
  }
  return 0;
}
