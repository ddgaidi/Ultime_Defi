#include <stdio.h>

// Création fonction ultimeDefi

void ultimeDefi(char *questions[], char *reponses[][4], int correctes[], int *points, int niveau) {
// Initialisation des variables scoreNiveau et pointsParQuestion à 0
    int scoreNiveau = 0;
    int pointsParQuestion = 0;

    printf("Relever l\'Ultime Défi !\n\n");

// Définir les points par question en fonction du niveau
    switch (niveau) {
        case 1:
            pointsParQuestion = 1;
            break;
        case 2:
            pointsParQuestion = 2;
            break;
        case 3:
            pointsParQuestion = 3;
            break;
    }

    printf("Bienvenue dans le niveau %d !\n\n", niveau);

// Boucle for pour les questions
    for (int i = 0; i < 10; i++) {
        // Afficher la question
        printf("%s\n", questions[i]);
        printf("a) %s\nb) %s\nc) %s\nd) %s\n", reponses[i][0], reponses[i][1], reponses[i][2], reponses[i][3]);

// Lire la réponse du joueur
        int reponseUtilisateur;
        printf("Votre réponse (1 - 4) : ");
        do {
            int resultat = scanf("%d", &reponseUtilisateur);

// Si l'entrée est invalide, on demande à l'utilisateur de recommencer la saisie
            while (resultat != 1 || reponseUtilisateur < 1 || reponseUtilisateur > 4) {
                printf("Réponse invalide. Veuillez entrer un nombre entre 1 et 4 : ");
                while (getchar() != '\n'); // Supprime la saisie de l'utilisateur
                    resultat = scanf("%d", &reponseUtilisateur); // Réessaye de lire la saisie
            }
            } while (reponseUtilisateur < 1 || reponseUtilisateur > 4);



// Vérifier la réponse
        int estCorrect = (reponseUtilisateur - 1 == correctes[i]);
        switch (estCorrect) {
            case 1:
                printf("VRAI ! Bonne réponse.\n\n");
                scoreNiveau += pointsParQuestion;
                break;
            case 0:
                printf("FAUX ! La bonne réponse était : %s\n\n", reponses[i][correctes[i]]);
                break;
        }
    }

// Ajout du score du niveau au score total
    *points += scoreNiveau;

// Résultat du niveau
    printf("Vous avez obtenu %d points pour le niveau %d.\n", scoreNiveau, niveau);
}

int main() {
    int points = 0;
    int niveau = 1;

// Questions niveau facile
    char *questionsFacile[] = {
        "Question 1 : Quelle est la capitale de la France ?",
        "Question 2 : Quel est le plus grand océan du monde ?",
        "Question 3 : Combien de continents y a-t-il sur Terre ?",
        "Question 4 : Quel animal est surnommé \"le roi de la jungle\" ?",
        "Question 5 : Quelle planète est la plus proche du Soleil ?",
        "Question 6 : Qui a peint la Joconde ?",
        "Question 7 : Quelle est la langue officielle du Brésil ?",
        "Question 8 : Combien y a-t-il de minutes dans une heure ?",
        "Question 9 : Quelle est la couleur du sang humain ?",
        "Question 10 : Comment s'appelle le président des États-Unis élu en 2020 ?"
    };

// Réponses niveau facile
    char *reponsesFacile[][4] = {
        {"Londres", "Madrid", "Paris", "Rome"},
        {"Atlantique", "Indien", "Arctique", "Pacifique"},
        {"7", "5", "8", "6"},
        {"L'éléphant", "Le tigre", "L'ours", "Le lion"},
        {"Vénus", "Mars", "Mercure", "Terre"},
        {"Pablo Picasso", "Léonard de Vinci", "Vincent van Gogh", "Claude Monet"},
        {"Espagnol", "Italien", "Portugais" , "Anglais"},
        {"60", "50", "70", "80"},
        {"Bleu", "Vert", "Violet", "Rouge"},
        {"Donald Trump", "Barack Obama", "Joe Biden", "George Bush"}
    };

// Réponses correctes niveau facile
    int correctesFacile[] = {2, 3, 0, 3, 2, 1, 2, 0, 3, 2};

// Questions niveau intermédiairee
    char *questionsNormal[] = {
        "Question 1 : Quel pays est surnommé le \"pays du soleil levant\" ?",
        "Question 2 : Quel scientifique a proposé la théorie de la relativité ?",
        "Question 3 : Quel est le plus long fleuve du monde ?",
        "Question 4 : Qui a écrit Les Misérables ?",
        "Question 5 : Quelle est la capitale de l\'Australie ?",
        "Question 6 : Quelle invention est attribuée à Johannes Gutenberg ?",
        "Question 7 : Quel est l'élément chimique représenté par le symbole \"O\" ?",
        "Question 8 : Dans quelle ville italienne se trouve le Colisée ?",
        "Question 9 : Quel est l'artiste célèbre pour la sculpture Le Penseur ?",
        "Question 10 : En quelle année l'homme a-t-il marché sur la Lune pour la première fois ?"
    };

// Réponses niveau intermédiaire
    char *reponsesNormal[][4] = {
        {"Chine", "Japon", "Corée du Sud", "Thaïlande"},
        {"Isaac Newton", "Galileo Galilée", "Stephen Hawking", "Albert Einstein"},
        {"Nil", "Amazone", "Yangtsé", "Mississipi"},
        {"Victor Hugo", "Gustave Flaubert", "Émile Zola", "Honoré de Balzac"},
        {"Sydney", "Melbourne", "Canberra", "Brisbane"},
        {"La boussole", "L'imprimerie", "La machine à vapeur", "L'ampoule électrique"},
        {"Or", "Osmium", "Oxygène", "Ozone"},
        {"Florence", "Naples", "Venise", "Rome"},
        {"Auguste Rodin", "Michel-Ange", "Donatello", "Bernini"},
        {"1965", "1969", "1972", "1980"}
    };

// Réponses correctes niveau intermédiaire
    int correctesNormal[] = {1, 3, 1, 0, 2, 1, 2, 3, 0, 1};

// Questions niveau difficile
    char *questionsDifficile[] = {
        "Question 1 : Quel est le plus ancien texte littéraire connu ?",
        "Question 2 : Qui a découvert la pénicilline en 1928 ?",
        "Question 3 : Quelle est la plus grande île du monde (hors continent) ?",
        "Question 4 : Quelle est la seule œuvre symphonique composée par Gustav Holst ?",
        "Question 5 : Quel pays possède le plus de fuseaux horaires au monde ?",
        "Question 6 : Quel est l\'acide contenu dans les piqûres d’orties ?",
        "Question 7 : Dans quelle ville se trouve la plus grande cathédrale gothique du monde ?",
        "Question 8 : Quelle est la distance exacte d’un marathon ?",
        "Question 9 : Quel explorateur a été le premier à atteindre le pôle Sud ?",
        "Question 10 : Qui a écrit À la recherche du temps perdu ?"
    };

// Réponses niveau difficile
    char *reponsesDifficile[][4] = {
        {"L'Iliade d'Homère", "L'Épopée de Gilgamesh", "Les Métamorphoses d'Ovide", "Le Mahabharata"},
        {"Alexander Fleming", "Louis Pasteur", "Marie Curie", "Robert Koch"},
        {"Madagascar", "Bornéo", "Nouvelle-Guinée", "Groenland"},
        {"Les Planètes", "La Symphonie inachevée", "La Symphonie alpestre", "La Pastorale"},
        {"Russie", "États-Unis", "France", "Chine"},
        {"Acide sulfurique", "Acide méthanoïque", "Acide citrique", "Acide acétique"},
        {"Cologne", "Milan", "Reims", "Séville"},
        {"40,00 km", "41,85 km", "42,195 km", "43,26 km"},
        {"Ernest Shackleton", "Robert Falcon Scott", "Roald Amundsen", "James Cook"},
        {"Marcel Proust", "André Gide", "Paul Valéry", "Albert Camus"}
    };

// Réponses correctes niveau difficile
    int correctesDifficile[] = {1, 0, 3, 0, 2, 1, 3, 2, 2, 0};

// Déroulement des niveaux
    ultimeDefi(questionsFacile, reponsesFacile, correctesFacile, &points, 1);

// Si score >= 6, passage au niveau 2
    switch (points >= 6) {
        case 1:
            ultimeDefi(questionsNormal, reponsesNormal, correctesNormal, &points, 2);
            break;
    }
// Si score >= 16, passage au niveau 3
    switch (points >= 16) {
        case 1:
            ultimeDefi(questionsDifficile, reponsesDifficile, correctesDifficile, &points, 3);
            break;
    }

    printf("GAME OVER !\nScore : %d points.\n", points);
    return 0;
}
