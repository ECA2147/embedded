import sys 
sys.path.append('/home/pi/Adafruit-Raspberry-Pi-Python-Codelegacy/Adafruit_CircuitPython_MCP230xx-main') # LIBRARY 
import time 
import board 
import busio 
from digitalio import Direction, Pull 
from adafruit_mcp230xx.mcp23017 import MCP23017 
i2c = busio.I2C(board.SCL, board.SDA) 
mcp = MCP23017(i2c) 
mcp = MCP23017(i2c, address=0x20) # MCP23017 I2C Address 
# Make a list of all the port A pins 
PortA = [ ] 
for pin in range(0, 8): 
PortA.append(mcp.get_pin(pin)) 
# Make a list of all the port B pins 
PortB = [ ] 
for pin in range(8, 16): 
PortB.append(mcp.get_pin(pin)) 
#Clearing all the Port Pins 
for pin in range(0,8): 
PortA[pin].value=False 
for pin in range(0,8): 
PortB[pin].value=False 
PortB[3].direction = Direction.OUTPUT # BUZZER CONNECTED PIN AS OUTPUT 
try: 
      while True: 
PortB[3].value = True 
print("BUZZER ON") 
time.sleep(5) # 1 minute time delay 
PortB[3].value = False 
print("BUZZER OFF") 
time.sleep(2) 
except KeyboardInterrupt: # CLEAR THE PINS press Cntrl+C
for pin in range(0,8): 
PortA[pin].value=False 
for pin in range(0,8): 
PortB[pin].value=False
