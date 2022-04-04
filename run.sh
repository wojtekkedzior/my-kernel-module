#!/bin/bash

sudo rmmod lkm_example && make & sudo insmod lkm_example.ko && sudo dmesg