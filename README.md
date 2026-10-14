# Jonathan Deschênes

## Fonctionnalité implémenté

- ### Interface et Expérience Utilisateur

    Lors de l'affichage des livres, j'ai implémenter un affichage du nom d'utilisateur a la place d'un id d'utilisateur.

- ### Gestion des Données

    Lors de l'affichage des livres, j'ai implémenter un tri des résultats par titre, auteur pour l'affichage á la place d'un tri par id qui reste inconsistent.

- ### Journal d'activités

    Implémentation d'un log manager pour chaque modification, suppression, emprunt et retour. Cela aide a garder des traces des donnés et empêcher la perte de donnée.

- ### Correction d'un bug

    Lors de la sauvegarde des données, si l'utilisateur ne spécifie pas de chemin de sauvegarde le logiciel échoue silencieusement. Cela est régler par une simple condition qui assure un chemin valide avant la sauvegarde.

## Réponse aux questions

- ### Question #1

    Voici une fonctionnalité de sauvegarde (.backup) gérer par un module de c++ nommé filesystem :

    ```
    #include <filesystem>

    if (fileExists(fileName)) {
        filesystem::copy_file(fileName, fileName + ".backup");
    }
    ```

    La méthode copy_file prend en parametre : un chemin vers le fichier source et un chemin cible pour la copie nouvellement créer. Cette méthode rend la copie de fichier facile et efficace sans manipuler ligne par ligne. Cette méthode retourne un booléen true or false si la copie a été créer, une gestion d'erreur est incluse si le chemin source et cible est introuvable : 

    - #### Gestion fichier source introuvable 
        ```
        !filesystem::is_regular_file(from)
        ```

    - #### Gestion chemin cible introuvable
        Par la suite d'un chemin cible spécifié, mais introuvable, il crée ce chemin.

    - #### Gestion chemin cible
        Par la suite d'un chemin cible équivalent aux chemin source, il utilise cette méthode pour gérer :
        ```
        filesystem::equivalent(from, to);
        ```

- ### Question #2

    Pour le futur de cette bibliotheque, il serait important d'implémenter une base de donnée MySQL a la place d'une structure de donnée avec des fichiers .txt. Cette implémentation futur peut faciliter l'ajout, la suppression et la modification de certaines données. 

    - #### Fonction a supprimer
        ```
        string toString(const Library& library) const;
        string toFileFormat() const;
        void fromFileFormat(const string& line);
        ```

        Avec l'implémentation d'une base de donné MySQL, l'étape de la conversion de donnée en fichier texte en objet lisible ne sera plus obligatoire avec une simple méthode get qui prend directement l'objet dans la base de donnée.

    - #### Vitesse d'éxecution plus rapide

        D'ailleurs, la vitesse d'éxecution améliora grandement avec une base de donnée pour la lecture et écriture, et une meilleure consistence des données assure aucune perte de donnée. 