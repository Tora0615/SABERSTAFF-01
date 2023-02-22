# -*- coding: utf-8 -*-
"""
Created on Wed Jan 11 01:00:01 2023

@author: Arthur
"""

import serial #need to install pyserial
import time
from playsound import playsound  ## pip install playsound==1.2.2

mp3file = "Beautiful Now.mp3"
delayTime = 29.8

COM_PORT = 'COM3'  # 請自行修改序列埠名稱
BAUD_RATES = 9600
ser = serial.Serial(COM_PORT, BAUD_RATES)
time.sleep(1) #open serial will let arduino reboot, need to wait it.  every arduino's reboot time is different...



# try many times guarantee it can send seccessfully
a = time.time()
for i in range(50):
    ser.write(b'reset!\n')
ser.close()
#print(time.time()-a)


print("默默倒數"+ str(delayTime) +"秒 開始")
time.sleep(delayTime)
    
print("開始撥放")    
playsound(mp3file)


'''
while True:
    ser.write(b'reset!\n')
    time.sleep(10)
'''