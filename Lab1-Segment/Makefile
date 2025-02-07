.PHONY: all build cmake clean

BUILD_DIR := build
BUILD_TYPE ?= Debug
TARGET := Lab1-Segment

all: build

${BUILD_DIR}/Makefile:
	cmake \
		-B${BUILD_DIR} \
		-DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON

cmake: ${BUILD_DIR}/Makefile

build: cmake
	${MAKE} -C ${BUILD_DIR} --no-print-directory

st-flash: build
	st-flash --reset write $(BUILD_DIR)/$(TARGET).bin 0x8000000

clean:
	rm -rf ${BUILD_DIR}