export CC ?= gcc
export BUILD_DIR ?= ./build
export SRC_DIR ?= ./src
export TEST_DIR ?= ./test
export TEST_BUILD_DIR ?= ${BUILD_DIR}/test
export CMOCK_DIR ?= ./cmock
TEST_MAKEFILE = ${TEST_BUILD_DIR}/MakefileTestSupport
OBJ ?= ${BUILD_DIR}/obj
OBJ_DIR = ${OBJ}

default: all

all: setup test ${BUILD_DIR}/main run

setup:
	mkdir -p ${BUILD_DIR}
	mkdir -p ${OBJ}
	ruby ${CMOCK_DIR}/scripts/create_makefile.rb --silent

clean:
	rm -rf ${BUILD_DIR}

${BUILD_DIR}/main: ${SRC_DIR}/main.c ${OBJ_DIR}/example.o
	${CC} $< -o $@ ${OBJ_DIR}/example.o

${OBJ_DIR}/example.o: ./src/example.c
	${CC} -o $@ -c $< ${TEST_CFLAGS} -I ${SRC_DIR} ${INCLUDE_PATH}

run:
	./build/main || true

test: setup

-include ${TEST_MAKEFILE}

