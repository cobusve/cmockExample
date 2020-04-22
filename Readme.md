# Cmock Example

This is a basic example of how to run CMock from a makefile. It compiles main.c and example.c both in the src folder, then it will mock out example.c and run the tests which are found in the test folder. After this it will run the application without the test framework.

# Getting Started

Make sure that you have changed to a folder where you want the project folder created (my WSL starts in System32!). I usually just do 
    
    cd ~

First clone this repo. As cmock is included as a submodule you can do this in one easy step as follows:

    git clone --recursive https://github.com/cobusve/cmockExample.git

On Linux or MacOS the project should work with what comes with your machine. If you are on Windows I recommend using WSL (Windows Subsystem for Linux). The project uses make and if you try and use another make on Windows and installing gcc and all that you will just be inviting pain.

## Windows Installation

On Windows run "wsl" from the search bar.

You probably need to install ruby, and if like me your wsl was out of date you will have to update apt doing the following. (you may need your wsl sudo password)

    sudo apt-get update
    sudo apt install ruby

That is it, you should be set to go

## Linux and MacOS installation

You probably have what you need already. Test if you have ruby installed though. You can use brew or apt to install if you do not have it. To check run

    ruby -v

Not found? Then try one of these

    apt install ruby

or

    brew install ruby


## Initial setup

Your git clone will contain a cmock folder which is pulling cmock from the official github location at https://github.com/ThrowTheSwitch/CMock. 

If you get ruby errors make sure that you have the bundles you need by changing into the cmock folder and running

    bundle install

## Building the example

The supplied Makefile has targets to clean, run the app, generate the mocks and run the tests.

The default will do all of the above and run the app at the end:

    make all

The "setup" target will generate the helper makefiles for generating and compiling the mocks all behind the scenes by using the cmock ruby script create_makefile.rb. This only needs to run once for the repo. 

As the generated MakefileTestSupport file is included into this makefile when found you need to run setup before you can build and run the tests. If you forget this step the Makefile will run setup for you instead and build and run the tests on the second time you run it. You can make sure everything is set up by running

    make setup

The "run" target will just run the application and not run any tests

    make run

The "test" target imports the generated Makefile from it's location at this path ./build/test/MakefileTestSupport. This target as set up here will use the Unity framework to execute all of the tests in the "test" folder.

The example is quite basic and can be built without the makefile as follows:

    gcc -o app main.c example.c

## Running the tests

You can just run the tests by using this make target.

    make test

Running the tests should result in something that resembles this:

    mkdir -p ./build
    mkdir -p ./build/obj
    ruby ./cmock/scripts/create_makefile.rb --silent

    --------------------------
    UNITY FAILED TEST SUMMARY
    --------------------------
    .\test\test_example.c:16:test_taskFunction_should_return_1:FAIL: Expression Evaluated To FALSE
    --------------------------
    OVERALL UNITY TEST SUMMARY
    --------------------------
    1 TOTAL TESTS 1 TOTAL FAILURES 0 IGNORED
