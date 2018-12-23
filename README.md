# Infosuicide

----
## Comment l'assembler?
La première chose à faire est d'installer [libcsv](https://sourceforge.net/projects/libcsv/) en mettant le dossier extrait dans le dossier du projet puis de se rendre dans le  dossier libcsv depuis un terminal et lancer la commande

    ./configure && make && make check && make install

Vous pouvez ensuite utiliser make pour assembler le projet.

Une fois fait il vous faut un fichier csv compatible [comme celui ci.](https://www.kaggle.com/szamil/who-suicide-statistics) Le fichier doit etre dans le repertoire racine du projet.





----
## Comment l'utiliser?
La commande générale

    ./infosuicide file.csv

Si vous utilisez le fichier csv fourni :


    ./infosuicide who_suicide_statistics.csv


# Enjoy
*Aurélien Demont* - *Arnaud Legeas*
