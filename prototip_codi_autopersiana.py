#Vull automatitzar la meva persiana!
""" la intenció és connectar l'interruptor amb el meu raspberry pi
la idea principal és fer que quan detecti una certa llum a fora o 
quan sigui una hora determinada que engegui la persiana"""

""" ara bé tinc dos problemes. un és que no sé com connectar el raspberry
pi a la persiana. l'altre és que no sé com programar-ho"""

#vaig a focalitzar-me en com programar-ho:
############################################################################

#importo les llibreries de rasp pi
import RPi.GPIO as GPIO
import time

#importo les llibreries del temps
from datetime import datetime, time
import time as t

# configuro el mode dels pins
GPIO.setmode(GPIO.BCM)  # (aquí és algo de q utilitza la numeración BCM (Broadcom))

# Defineixo el pin GPIO com sortida i entrada
PIN_DETECTA = 17
GPIO.setup(PIN_DETECTA, GPIO.IN)
PIN_PERSIANA = 18
GPIO.setup(PIN_PERSIANA, GPIO.OUT)

"""El motor de la persiana ja sap el marge que ha d'estar funcionant per obrir i tancar la persiana
tenint en compte el temps que triga en obrir i tancar la persiana puc saber el temps en que el GPIO
he d'enviar el senyal"""
#Defineixo la variable dl temps que triga a obrir o tancar. La defineixo amb un segon de més per assegurar-me
temps = 6

#defineixo la funció per obrir la persiana
def moure(x):

    try:
        if x == 0:
            #GPIO.output(PERSIANA_PIN, GPIO.HIGH)
            time.sleep(temps)
            print("Obrint persiana")
        elif x == 1:
            #GPIO.output(PERSIANA_PIN, GPIO.OUT)
            print("Tancant persiana")
        else:
            print("Problema en la definició de la variable")
    finally:
        GPIO.cleanup()
        print("pins netejats")

#defineixo la funció que detecta si és de dia
def detecta()
    
    try:
        estat_input = GPIO.input(INPUT_PIN)
        if estat_input == GPIO.HIGH
            print("És de dia")
            return 1
        elif estat_input == GPIO.LOW
            print("És de nit")
            return 0
        time.sleep(0.1)
    finally:
        GPIO.cleanup()
        print("pins netejats")

#defineixo la funció que dona ordres a una hora determinada
def horari(hora, minut)
    
    desperta = time(hora, minut) #menys mal que python és fàcil

    while True
        ara = datetime.now().time
        if ara >= desperta:
            break
        t.sleep(60) #espera i torna
    return 0

#obrir la persiana depenent de la situació
print("Holaa! Quan et vols despertar demà?")
print("A una hora determinada --> 0")
print("Quan surti el sol --> 1")
#agafo imput del usuari
user = input()
if(user == 1):
    #obrir la persiana quan detecta el sol
    moure(detecta())

elif(user == 0):
    print("Guai, diga'm l'hora i els minuts")
    print("Hora:")
    hora = input()
    print("Minut:")
    minut = input()
    #obrir la persiana a una hora determinada
    moure(horari(hora, minut))

else:
    print("Escolleix una de les opcions: 0 o 1")
