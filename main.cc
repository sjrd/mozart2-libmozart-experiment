#include <iostream>

#include <mozartcore.hh>
#include <coreinterfaces.hh>

#include "interfaces.hh"

using namespace std;
using namespace mozart;

int main(int argc, char **argv) {
  // Create the virtual machine
  VirtualMachine virtualMachine(nullptr);
  VM vm = &virtualMachine;

  // Experiment
  UnstableNode unstable;
  unstable.make<SmallInt>(vm, 5);
  StableNode stable;
  stable.init(vm, unstable);
  cout << stable.type()->getName() << endl;
}
