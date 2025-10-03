# claush - Un mini shell en C

Auteur: Jonasson Claubert Joachin
DATE: 27 September 2025

**claush** est un projet éducatif écrit en C qui reproduit un shell Unix minimaliste.  
Il n’a pas vocation à remplacer Bash, Zsh ou Fish, mais sert uniquement pour **apprendre les bases des systèmes Unix et de la programmation système en C**.  
---

## Fonctionnalités actuelles
- Affichage d’un prompt personnalisé :  

- Commandes internes :
- `cd` (changer de répertoire, support de `..` et chemins relatifs)
- `exit` (quitter le shell)
- `pwd` (afficher le répertoire courant)
- `echo` (afficher un texte ou une variable d’environnement, ex : `echo Bonjour $USER`)
- Exécution de **commandes externes** via `fork()` et `exec()` (ex : `ls`, `uname`, `mkdir`…)

---

## Exemple d’utilisation
```bash
[mayko@claush: /home] -> cd mayko
[mayko@claush: /home/mayko] -> ls
Documents  Downloads  shell.c
[mayko@claush: /home/mayko] -> echo Bonjour le monde
Bonjour le monde
[mayko@claush: /home/mayko] -> echo Bonjour $USER
Bonjour mayko
[mayko@claush: /home/mayko] -> uname
Linux
[mayko@claush: /home/mayko] -> exit

-----------------------------------------------------------------------------------------

**claush** - A mini shell in C **

Author: Jonasson Claubert Joachin
DATE: 27 September 2025

claush is an educational project written in C that reproduces a minimalist Unix-like shell.
It is not intended to replace Bash, Zsh, or Fish, but serves only to learn the basics of Unix systems and system programming in C.

Current Features
-----------------

Display of a custom prompt

Built-in commands:

cd (change directory, supports .. and relative paths)

exit (quit the shell)

pwd (print current working directory)

echo (print text or environment variables, e.g. echo Hello $USER)

Execution of external commands via fork() and exec() (e.g. ls, uname, mkdir …)

[mayko@claush: /home] -> cd mayko
[mayko@claush: /home/mayko] -> ls
Documents  Downloads  shell.c
[mayko@claush: /home/mayko] -> echo Hello world
Hello world
[mayko@claush: /home/mayko] -> echo Hello $USER
Hello mayko
[mayko@claush: /home/mayko] -> uname
Linux
[mayko@claush: /home/mayko] -> exit
