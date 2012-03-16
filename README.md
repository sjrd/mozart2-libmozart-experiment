# Basic template for experimenting with the Mozart2 VM library

The [Mozart2 VM](https://github.com/mozart/mozart2) is designed as a library, which is called `libmozartvm`. This repository provides a minimal template to start hacking and experimenting with this library.

The first time, prepare your build environment with:

    experiment$ mkdir build
    experiment$ cd build
    build$ cmake -D MOZART_DIR /path/to/mozart2 ..

When that's done, you can write your experiment in `main.cc`. Then you can build it with:

    build$ make

You can run your experiment with:

    build$ ./libmozart-experiments
