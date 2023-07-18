#!/bin/bash

gcc `sdl2-config --libs --cflags` -o cube main.c spin.c rendering.c -lm
