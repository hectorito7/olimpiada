'''Preparación dos sensores e actuadores do Proxecto'''

from machine import ADC, Pin
import time

# Configuración
pinCaudal = 26

# Sensor
caudal = ADC(Pin(pinCaudal))
caudal.atten(ADC.ATTN_11DB)      # Hasta 3.3V
caudal.width(ADC.WIDTH_12BIT)   # 12 bits (0–4095)


# bucle infinito
while True:
    valorCaudal = caudal.read()
    print("Nivel de caudal:", valorCaudal)
    time.sleep(1)
