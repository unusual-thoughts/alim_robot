Réalisation de la carte d'alimentation
======================================

La carte d'alimentation est chargée :
- délivrer l'alimentation des différents composants du robot
- informer de l'état de charge des batteries avec des leds

Un microcontrôleur Atmega328P sera utilisé pour évalué la tension des batteries.

Les sources sont trois batteries 12V de 2500mAh

Les régulateurs utilisés étaient DE-5W050 et DE-5WADJ

Entrées
Régulateur Dimension Engineering
Sortie
7-30V

5V 1A(max)

On peut utiliser des LM2596 a la place
Le plus simple serait de prendre des modules déja faits (très très peu chers)


Elément            | U (V) | I (mA)             | P (W)
-------------------|-------|--------------------|------
Autres capteurs    | 3,3   | 5-50               | < .3
Raspberry          | 5     | 700 (1.5A max)     | < 7.5
Arduino/Teensy     | 5     | 10-20 (optimiste?) | ~.1
Capteurs           | 5     | 5-50               | < .5
Hokuyo             | 5     | 500 (800 init)     | < 4
Pont en H          | 5     | 5-10               | < .05
uArm               | 5     | < 5A               | < 25
Total 5V           | 5     | ~7A                | ~35V
Servo Dynamixel    | 11.1  | 1.3A (x2)          | 28.86
Moteurs            | 24    | 800 (pic)          | < 38.4
Total (bat 1 et 2) | 24    | < 800              | < 38.4
Total (bat 3)      | 12    | < 5.42 A           | < 65

Démarche:

- Stratégie d'alimentation
- Représentation du schématics sous Eagle
- Agencement et réalisation de la carte

- Choix de la connectique
- Choix des régulateurs
- Choix du micro, ATTiny 48/85
- Choix de batterie 18-650

Tâche : 
Programmer un Atmega328P
Utilisation d'Eagle (voir tutos de Jeremy Blum)



Matériel : Régulateur 5,1 V


Etat des lieux des régulateurs présent sur les cartes :
Teensy
Arduino
Raspberry
