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

The "setup" target will generate the helper makefiles for generating and compiling the mocks all behind the scenes by using the cmock ruby script create_makefile.rb. This only needs to run once for the repo. 

As the generated MakefileTestSupport file is included into this makefile when found you need to run setup before you can build and run the tests. If you forget this step the Makefile will run setup for you instead and build and run the tests on the second time you run it. You can make sure everything is set up by running

    make setup

The "run" target will just run the application and not run any tests

    make run

The "test" target imports the generated Makefile from it's location at this path ./build/test/MakefileTestSupport. This target as set up here will use the Unity framework to execute all of the tests in the "test" folder.

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
