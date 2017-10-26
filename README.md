## µOS++ complementary C++ library functions

These are some files that complement or extend the C++ library:

- `cxx.cpp` add explicit handlers for C++ API functions, to be sure no othe heavy implementations are pulled from the (huge) standard library.

## Developer info

This section is intended to developers who plan to include this library in their own projects.

### Easy install

The source files are available from [GitHub](https://github.com/micro-os-plus/cpp-libs-xpack):

```console
$ git clone https://github.com/micro-os-plus/cpp-libs-xpack.git cpp-libs-xpack.git
```

The library will shortly be available from the npm registry:

```console
$ npm install @micro-os-plus/cpp-libs
```

### Prerequisites

The source code require a modern C++ compiler, preferably GCC 5 or higher, but was also compiled with GCC 4.8. 

## License

The original content is released under the MIT License, with all rights reserved to Liviu Ionescu.
