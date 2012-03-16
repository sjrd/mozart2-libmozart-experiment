# Basic template for experimenting with the Mozart2 VM library

The [Mozart2 VM](https://github.com/mozart/mozart2) is designed as a library, which is called `libmozartvm`. This repository provides a minimal template to start hacking and experimenting with this library.

First, you should edit the path to mozart2 in the `CMakeLists.txt` file.

```cmake
# Configure paths
set(MOZART_DIR "/path/to/mozart2")
```

Write your experiment in `main.cc`. Then build it with:

    experiment$ mkdir build
    experiment$ cd build
    build$ cmake .. && make

You can run your experiment with:

    build$ ./libmozart-experiments
