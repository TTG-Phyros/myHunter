# MyHunter

**MyHunter** est un jeu de type police/voleur où le joueur incarne un policier dont l'objectif est de neutraliser des voleurs tout en évitant les civils innocents. La mécanique principale repose sur un système de tir avec des contraintes de timing et de pénalités pour chaque erreur commise.

## 🎮 Gameplay

Le jeu présente trois types de personnages différents :

- **Voleur** : Ce sont les cibles que le joueur doit neutraliser. Chaque voleur éliminé rapporte **10 points**.
- **Homme civil** : Personnage civil innocent que le joueur doit éviter. Tirer sur un civil coûte **100 points**.
- **Femme civil** : Autre personnage civil que le joueur doit également éviter. Tirer sur elle entraîne également une pénalité de **100 points**.

Le joueur doit donc être rapide et précis pour accumuler le plus de points possible en touchant uniquement les voleurs. 

### ⚠️ Difficulté :

- Le joueur ne peut tirer que toutes les **deux secondes**, ce qui ajoute une difficulté supplémentaire. Il est donc crucial de bien choisir ses cibles pour éviter de perdre des points en abattant des civils par erreur.

## 🕹️ Contrôles

- **Clic gauche** : Tirer
- **Touches directionnelles** : Déplacer le policier (ajuster en fonction des mécanismes réels de ton jeu si nécessaire)

## 📈 Système de Score

- **+10 points** pour chaque voleur neutralisé.
- **-100 points** pour chaque civil touché (homme ou femme).
  
L'objectif est de maximiser votre score tout en évitant les erreurs.

## 🚧 Fonctionnalités à venir

- [ ] Ajout de nouveaux types de voleurs avec des comportements différents.
- [ ] Équilibrage de la difficulté en fonction du score.
- [ ] Mode multi-joueur.
- [ ] Plus de niveaux et de décors.
  
## 🖼️ Captures d'écran

![Main Menu](https://github.com/TTG-Phyros/repositoriesPhotos/blob/main/MyHunter/My_Hunter_Menu.png)
![In Game](https://github.com/TTG-Phyros/repositoriesPhotos/blob/main/MyHunter/My_Hunter_In_Game.png)
![Game Over](https://github.com/TTG-Phyros/repositoriesPhotos/blob/main/MyHunter/My_Hunter_Game_Over.png)

## 🚀 Installation
### Prérequis

    [MakeFile, SFML, GCC]

## Instructions

### Clone le dépôt :

    git clone https://github.com/ton-compte/MyHunter.git

### Accède au dossier du projet :

    cd MyHunter

### Compile le projet :

    make

### Lance le jeu :

    ./my_hunter

### Pour Nettoyer les fichiers :

    make fclean