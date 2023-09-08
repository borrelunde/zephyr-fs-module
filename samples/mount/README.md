# Zephyr File System Module Sample | Mount

## Overview

Mounts a file system using the module.

## Requirements

This sample uses the logger. Use a board that supports logging and connect to the serial port that prints the log messages. It should be the standard USB port.

## Building and Running

To build, replace `<board_name>` with the actual name of the board.

```
west build -p -b <board_name> samples\mount
```

For example, to build for the nRF52840 Development Kit.

```
west build -p -b nrf52840dk_nrf52840 samples\mount
```

Then flash the application to the board.

```
west flash
```

## Output

This is the expected output from the sample.

```
(Nothing here yet.)
```