# F´ Separated Project Example
An example where the project has been separated from the F´ standard distribution. This allows for
cleaner separation of F´ code and the code of projects built using F´.

**Note:** this may not be a complete example, or kept up with the `Ref` application in fprime, but
it is here to demonstrait the basic functioning of seperated builds.

## Initialization

Initialization of this package can be done by running the following git command to pull in the
standard F´ code. This is done using git submodules.


```
git submodule update --init --recursive
```

## Needed Changes

So far, the following necessary tweaks are required to enable the building of this package. These
will likely be incorporated directly into the F´ build system, but for now they must be provided
as additional statements int the project's make file.

### Include FPRIME_PROJECT_ROOT

The project directory must be included as a possible compilation include director (`-I` directory).
This easily could be included in an improved version of the build system for future release of F´.
```
include_directories("${FPRIME_PROJECT_ROOT}")
```

### Set FPRIME_CURRENT_BUILD_ROOT

The variable FPRIME_CURRENT_BUILD_ROOT must be set. This also can be pulled into the build system
for future releasse.

```
set(FPRIME_CURRENT_BUILD_ROOT "${CMAKE_CURRENT_LIST_DIR}/..")
message(STATUS "F prime BUILD_ROOT currently set to: ${FPRIME_CURRENT_BUILD_ROOT}")
```

### Reference

The standard `Ref` example has been renamed `Reference` here such that its names and paths do not
collide with `Ref` included in the standard package.

## Building and Running this Reference Application

In order to build the Reference application, or any other F´ application, we first need to generate a build directory.  F´ uses CMake under the hood,
which requires a directory to work in. To generate a build directory, we will use the `fprime-util` (a wrapper for CMake to streamline standard 
F´ processses). This can be done with the following commands:

```
cd ./Refence
fprime-util generate
```

Now that the build directory has been generated, the user need not run `fprime-util generate` again unless the build directory has been removed.

The next step is to build the Reference application's code. This is done for the current system that the user is running on. This is handled by CMake
and will produce a binary that can be run on the user's system. This is accomplished by using the `build` subcommand of `fprime-util`. Since we
will run the code next, we will also run the install command to ensure we may easily find the binaries.

```
fprime-util build
```

## Running the F´ Ground System and Code

F´ ships with a browser-based test ground system. This system is designed to help developers of F´ projects quickly test and work with F´ code
without much overhead. This ground system can be run with the following commands. Please note: the Reference application's binary will also be run
automatically.  This allows for quick testing on Linux and Mac OSX. Please ensure that the binary has been built and installed as described above.

```
cd ./Reference
fprime-gds -d .
```

The user may nopw explore the "Commanding", "Event", and "Channels" tabs to see the F´ code in action.  The "Logs" tab has logs for the running
application should an error arise.  See: Logs -> Reference.log to see standard output of the Reference app.


