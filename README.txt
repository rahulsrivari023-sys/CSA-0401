CSA04 – OPERATING SYSTEMS LAB PROGRAMS
======================================

This folder contains 40 individual C source files corresponding to experiments
1–40 in the uploaded CSA04 Operating Systems Lab Manual.

Compilation (Linux / Ubuntu / WSL):
    gcc 01_process_creation.c -o program
    ./program

For POSIX thread/semaphore programs, link pthread:
    gcc 11_multithreading.c -o program -pthread
    gcc 12_dining_philosophers.c -o program -pthread
    gcc 18_producer_consumer.c -o program -pthread
    gcc 19_mutex_synchronization.c -o program -pthread
    gcc 20_readers_writers.c -o program -pthread
    gcc 29_classical_sync_dining.c -o program -pthread
    gcc 30_pthread_create_join_equal_exit.c -o program -pthread

Notes:
- Programs using fork(), System V IPC, directory operations, fcntl(), stat(),
  and POSIX threads are intended for Linux/Unix-like systems (or WSL).
- Program 02 takes source and destination paths as command-line arguments:
      ./program input.txt output.txt
- Program 27 optionally accepts a directory path.
- Program 28 takes a search pattern and filename:
      ./program pattern file.txt
- Program 40 optionally accepts a file path.
- These are clean, runnable implementations of the 40 experiment topics.
  They may differ in formatting from the manual's sample output.
