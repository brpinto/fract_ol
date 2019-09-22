<h1 align="center">Fract_ol</h1>

Le projet fract_ol est un explorateur de fractales. Il permet d'en découvrir un peu plus sur la librairie graphique et l'optimisation. Il permet aussi d'appréhender la notion des nombres complexes.

## Installation

```sh
https://github.com/brpinto/fract_ol.git
make
```

## Usage

Cet explorateur supporte l'ensemble de Mandelbrot, et ses dérivés l'ensemble de Julia et le Burning Ship. 
  
```sh
./fractol [mandelbrot] [julia] [burning]
```
## Makefile

```sh
make clean
```
Supprime les dossiers obj contenant les fichiers .o nécessaires à la compilation

```sh
make fclean
```
Supprime le dossier obj ainsi que l'executable du projet

```sh
make re
```
Exécute les règles clean et fclean et recompile le projet (make)

## Controles

ESC : Fermer la fenêtre <br />
Scroll up / down : Permet de dézoomer / zoomer respectivement (suit la position de la souris) <br />
Z: Déplacer la fractale vers le haut <br />
Q: Déplacer la fractale vers la gauche <br />
S: Déplacer la fractale vers le bas <br />
D: Déplacer la fractale vers la droite <br />
R: Réinitialiser la fractale <br />
Flèches (haut / bas) : augmente / baisse la saturation des couleurs <br />
'+' (pavé numérique): Change les couleurs <br />
Clic gauche (ensemble de julia): modifie (premier clic) / fixe (deuxième clic) la forme de la fractale. <br />
1 / 2 / 3: Changement de fractale, respectivement : mandelbrot, julia, burning ship
