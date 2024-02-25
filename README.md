# Torres-de-hanoi
El juego de las Torre de Hanoi consiste en una torre con varios discos de diferentes tamaños colocados en un poste, donde los discos están desordenados. El objetivo del juego es mover todos los discos de la torre de origen a otro poste, utilizando un tercer poste como auxiliar, siguiendo ciertas reglas:

Solo se puede mover un disco a la vez.
Nunca se puede colocar un disco más grande sobre uno más pequeño.
El problema de la Torre de Hanoi se puede resolver de manera recursiva, donde se aplican los siguientes pasos:
[![Screenshot-2024-02-25-142131.png](https://i.postimg.cc/BnbFVb3z/Screenshot-2024-02-25-142131.png)](https://postimg.cc/Jswty1G3)

Mover n-1 discos de la torre de origen al poste auxiliar, utilizando el poste destino como auxiliar.
Mover el disco restante de la torre de origen al poste destino.
Mover los n-1 discos del poste auxiliar al poste destino, utilizando la torre de origen como auxiliar.

[![Screenshot-2024-02-25-142056.png](https://i.postimg.cc/7hXCB8WD/Screenshot-2024-02-25-142056.png)](https://postimg.cc/2Lb86JYX)