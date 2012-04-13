#include <iostream>

#include <mozart.hh>

#include "customlib.hh"

using namespace std;
using namespace mozart;

int main(int argc, char **argv) {
  // Create the virtual machine
  VirtualMachine virtualMachine(nullptr);
  VM vm = &virtualMachine;

  // Experiment
  UnstableNode unstable = UnstableNode::build<SmallInt>(vm, 5);
  RichNode value = unstable;
  cout << value.type()->getName() << endl;
  if (value.is<SmallInt>())
    cout << value.as<SmallInt>().value() << endl;
}
