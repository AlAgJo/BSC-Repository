#Vull automatitzar la meva persiana!
""" la intenció és connectar l'interruptor amb el meu raspberry pi
la idea principal és fer que quan detecti una certa llum a fora o 
quan sigui una hora determinada que engegui la persiana"""

""" ara bé tinc dos problemes. un és que no sé com connectar el raspberry
pi a la persiana. l'altre és que no sé com programar-ho"""

#anem a focalitzar-nos en com programar-ho:
############################################################################

#importem les llibreries de rasp pi
import RPi.GPIO as GPIO
import time

# configurem el mode dels pins
GPIO.setmode(GPIO.BCM)  # (aquí és algo de q utilitza la numeración BCM (Broadcom))

# Definim el pin GPIO com sortida
PERSIANA_PIN = 18
GPIO.setup(PERSIANA_PIN, GPIO.OUT)

#definim la funció

def moure( x, y):

    if x == 0:
        GPIO.output(PERSIANA_PIN, GPIO.HIGH)
    elif x == 1:
        GPIO.output(PERSIANA_PIN, GPIO.OUT)
    else:
        print("Problema en la definició de la variable")
