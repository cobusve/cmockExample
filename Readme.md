# Cmock Example

This is a basic example of how to run CMock from a makefile. It compiles main.c and example.c both in the src folder, then it will mock out example.c and run the tests which are found in the test folder. After this it will run the application without the test framework.

# Getting Started

## Initial setup

Before you start you will need to install Ruby form here https://www.ruby-lang.org/en/downloads/. You will not need the Devkit version to use this makefile but you may install it if you are interested in Ruby development yourself.

Get Cmock and make sure you have the bundles you need:

    git clone --recursive https://github.com/throwtheswitch/cmock.git
    cd cmock
    bundle install # Ensures you have all RubyGems needed

## Building the example

The application can be built using the following command line:

    gcc -o app main.c example.c

The supplied makefile has targets to clean, run the app, generate the mocks and run the tests.

The default will do all of the above and run the app at the end:
    make all

The "setup" target will generate the helper makefiles for generating and compiling the mocks all behind the scenes by using the cmock ruby script create_makefile.rb. This only needs to run once every time you add new files to your project.
    make setup

The "run" target will just run the application
    make run

The "test" target imports the generated Makefile from it's location at this path ./build/test/MakefileTestSupport. This target as set up here will use the Unity framework to execute all of the tests in the "test" folder.

