#########################################################################
# File Name:    stress_test_start.sh
# Author:       sunxiuyang
# mail:         sunxiuyang04@gmail.com
# Created Time: Wed Jan 30 20:05:15 2019
#########################################################################
#!/bin/bash
g++ stress-test/stress_test.cpp -o ./bin/stress  --std=c++11 -pthread  
./bin/stress
