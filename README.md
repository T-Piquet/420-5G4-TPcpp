# TP01
## Isaac Cloutier

## FONCTIONNALITÉS
#### Fonctionnalité 1: Afficher le nom d’utilisateur plutôt que l’id dans l’affichage des livres
J'ai simplement ajouter quelques lignes dans la fonction displayAllBooks de library pour vérifier
si le livre était disponible et pour afficher le nom de l'utilisateur en utilisant la fonction
findUserByID et getName. 

C'est là que j'ai eu beaucoup de misère, car sans que je le sache, borrowerID de book se faisait importer avec un
caractère invisible à la fin du string, brisant complètement findUserByID.

#### Fonctionnalité 2: Tri des résultats par titre, auteur pour l’affichage (utilisation de la fonction de tri de la STL)
Trois lignes toutes simples dans la fonction displayAllBooks, comme dans l'exemple dans les notes de cours, ainsi
que quelques autres lignes dans main pour lire l'input utilisateur afin de sélectionner le type de filtre souhaité.

La partie la plus difficile de l'implmentation de cette fonctionnalité à été de comprendre quel était le type à utiliser
dans la fonction lambda (Book, Book*, unique_ptr, etc.)

#### Fonctionnalité 3: Journal d'activité
Vivement inspiré des fonctions pour sauvegarder/importer les utilisateurs et les livres, les seules différences étant l'ajout
de ios::app pour écrire dans le fichier journal, puisque le contenu de celui-ci n'est jamais importé de sorte à pouvoir
l'utiliser pour sauvegarder le contenu déjà existant (j'aurais pu, mais c'était plus compliqué pour rien).

Pas de difficultés particulière pour celui-ci, malgré que j'ai eu quelques problèmes à utiliser le répertoire data.

### QUESTIONS
#### Question 1
L'écriture dans les fichiers est certainement quelque chose que nous n'avons jamais vu. Voici un extrait du code pour écrire
dans le journal: 
```
bool FileManager::writeToJournal(string entry) {
    ofstream file(journalFileName, ios::app);

    if (journalFileName != "") {
        if (!file.is_open()) {
            cout << "Erreur : Impossible d'ouvrir " << journalFileName << " en écriture.\n";
            return false;
        }


        file << entry + "\n";

        
        file.close();
        return true;
    }
    
}
```
Cette méthode permet d'ouvrir un stream output pour écrire dans le fichier journalFileName avec ofstream file(). Il utilise
ios::app pour ne pas tout effacer le fichier avant d'écrire dedans. Ensuite, il vérifie si le fichier journalFileName
existe (n'est pas nommé ""). Si c'est le cas, il écrit l'entry fournie en paramètre dans le file avec file << entry. Si
le stream n'a pas réussi à être ouvert, il y a une erreur et la méthode retourne false pour la signaler. Pour finir, on
ferme le stream et on retourne true pour signaler le succès de la méthode.

#### Question 2
Pour le futur de la bibliothèque, je crois qu'il serait plus optimal d'intégrer une base de donnée SQL. En effet, la bibliothèque d'Alexandrie est l'une des plus grande bibliothèque ayant jamais existé, et un jour, elle ne pourra plus se contenter de ses fichiers texte pour contenir toutes les informations sur les livres et les utilisateurs. Une base de donnée est plus optimale pour contenir de larges quantités d'informations de façon structuré. Pour utiliser cette technologie avec le c++, il faut utiliser les libraires mysql_connection.h
mysql_driver.h. Celle-ci fournissent des fonctions pour établir une connexion, créer des tables, insérer des données et effectuer des requêtes. Voici un exemple:
```
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>

using namespace std;
int main()
{
    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://localhost:3306",
                              "root", "");

        con->setSchema("test"); // your database name

        sql::Statement* stmt;
        stmt = con->createStatement();

        // SQL query to create a table
        string createTableSQL
            = "CREATE TABLE IF NOT EXISTS GFGCourses ("
              "id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,"
              "courses VARCHAR(255) NOT NULL"
              ")";

        stmt->execute(createTableSQL);

        string insertDataSQL
            = "INSERT INTO GFGCourses (courses) VALUES "
              "('DSA'),('C++'),('JAVA'),('PYTHON')";

        stmt->execute(insertDataSQL);

        // SQL query to retrieve data from the table
        string selectDataSQL = "SELECT * FROM GFGCourses";

        sql::ResultSet* res
            = stmt->executeQuery(selectDataSQL);

        // Loop through the result set and display data
        int count = 0;
        while (res->next()) {
            cout << " Course " << ++count << ": "
                 << res->getString("courses") << endl;
        }

        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }

    return 0;
}
```
Source: https://www.geeksforgeeks.org/sql/how-to-setup-mysql-database-in-visual-studio-2022-for-a-cpp-application/