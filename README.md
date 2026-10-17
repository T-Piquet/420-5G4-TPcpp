Alec Bergeron


## Fonctionnalités
### Interface et expérience Utilisateur
[x] Afficher le nom d'utilisateur plutôt que l’id dans l’affichage des livres.

### Gestion des Données
[x] Tri des résultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL).

### Journal d'activités
[x] Créez un fichier de journal de l’application. Ce fichier est conservé au fur et à mesure des sessions (créez le fichier s’il n’existe pas à la première exécution).


## Questions
### Question 1 : C++
**Expliquez en détails une fonctionnalité / notion dans le code que ne nous avons pas ou peu vu en cours. Montrez ici l’exemple sorti du code du projet.**

```c++
#include <sstream>
void Book::fromFileFormat(const string& line) {
    stringstream ss(line);
    string availability;

    getline(ss, title, '|');
    getline(ss, author, '|');
    getline(ss, isbn, '|');
    getline(ss, availability, '|');

    borrowerId = "";
    getline(ss, borrowerId);

    if (availability == "1")
    {
        isAvailable = true;
    } else {
        isAvailable = false;
    }
}
```

Nous n'avons pas vu en cours l'utilisation basique de la librairie sstream (stringstream) qui permet l'utilisation de strings comme source de données comme vue ci-haut. Dans cette exemple, nous initialisons un stringstream avec l'aide du paramètre line qui représente la ligne de départ d'où la lecture va commencer. La fonction getline utilise ce stringstream pour lire la ligne jusqu'au délimiteur, dans ce cas-ci le '|', représenter par son troisième paramètre et place ensuite le string obtenu dans la valeur donné comme deuxième paramètre.

### Question 2 : Options de développement possible

En prennant en compte la possibilité que la bibliothèque pourrait éventuellement être si grande qu'elle contiendrait des millions de livres, je crois que continuer de lire et
stocker toutes les données des utilisateurs et des livres par un fichier texte et un stringstream serait extrêmement inefficace ou simplement impossible. On pourrait donc utiliser une base de données comme MySQL pour stocker toutes informations sur les livres et utilisateurs ailleurs et d'une manière plus efficace qu'avec des strings. Pour faire la connexion entre la base de données serveur MySQL et l'applications C++ il sera donc essentiel d'utiliser la librairie C++ MySQL Connector/C++