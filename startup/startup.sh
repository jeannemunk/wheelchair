#!/bin/bash

sleep 20;

echo "Sending emails..."
python /root/startup/mailer.py

echo "Opening test program"
/root/Test/MainTest/a.out
