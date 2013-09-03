#!/bin/sh
#sudo picocom /dev/ttyUSB0 |
while [ 1 ]; do
  if read line; then
  echo -n "$line $(date +%Y-%m-%d-%H-%M-%S.%N) \n\r" | tee -a ./$(date +%F)_$1.log
  fi
done

