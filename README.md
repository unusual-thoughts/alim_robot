Réalisation de la carte d'alimentation
======================================

La carte d'alimentation est chargée :
- délivrer l'alimentation des différents composants du robot
- informer de l'état de charge des batteries avec des leds

### Ancienne Carte

Un microcontrôleur Atmega328P utilisé pour évaluer la tension des batteries.

Les sources étaient trois batteries NiMh 12V de 2500mAh

Les régulateurs utilisés étaient DE-5W050 et DE-5WADJ

On peut utiliser des LM2596 a la place
Le plus simple serait de prendre des modules déja faits (très très peu chers)

### Budget Courant/tension

Elément            | U (V) | I (mA)             | P (W)
-------------------|-------|--------------------|------
Autres capteurs    | 3,3   | 5-50               | < .3
Raspberry          | 5     | 700 (1.5A max)     | < 7.5
Arduino/Teensy     | 5     | 10-20 (optimiste?) | ~.1
Capteurs           | 5     | 5-50               | < .5
Hokuyo             | 5     | 500 (800 init)     | < 4
Pont en H          | 5     | 5-10               | < .05
uArm               | 5     | < 5A               | < 25
Total 5V           | 5     | ~7A                | ~35
Servo Dynamixel    | 11.1  | 1.3A (x2)          | 28.86
Moteurs            | 24    | 800 (pic)          | < 38.4
Total (bat 1 et 2) | 24    | < 800              | < 38.4
Total (bat 3)      | 12    | < 5.42 A           | < 65

### Choix Régulateur(s)

Régulateur                                            | Courant  | Package | Commentaires
------------------------------------------------------|----------|---------|----------------------------------------------
[Module LM2596](http://www.ebay.com/itm/321476590827) | << 3A    | Module  | Peu fiable (!)
[LM2596](http://www.ti.com/product/lm2596)            | max 3A   | ~TO263  | Pas assez de courant
[LM2678](http://www.ti.com/product/lm2678)            | max 5A   | ~TO263  | Fort encombrement, courant insuffisant, gros inducteur et diode
[TPS54821](http://www.ti.com/product/tps54821)        | max 8A   | QFN     | très performant, pas cher, très faible encombrement, compliqué à souder
[LMZ12008](http://www.ti.com/product/LMZ12008/)       | max 8A   | PFM     | très encombrant, très simple d'utilisation, extremement cher (15 euros)
[LMZ31710](http://www.ti.com/product/LMZ31710)        | max 10A  | QFN     | compromis, peu de composants externes, pas d'inducteur (!)

### Choix batterie 12V

On garde les 2 NiMh pour le 24V
LiPo pour le 12V:
[5800mAh](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=35957) ou [8000mAh](http://www.hobbyking.com/hobbyking/store/__38300__ZIPPY_Flightmax_8000mAh_3S1P_30C_Lipo_Pack_EU_Warehouse_.html)


#### Démarche

- Stratégie d'alimentation
- Représentation du schématics sous Eagle
- Agencement et réalisation de la carte

- Choix de la connectique
- Choix des régulateurs
- Choix du micro, ATTiny 48/85
- Choix de batterie 18-650

#### Tâches
- Programmer un Atmega328P
- Utilisation d'Eagle (voir tutos de Jeremy Blum)
