import speech_recognition as sr

def reconnaissance_vocale():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        print("Parlez quelque chose:")
        audio = recognizer.listen(source)
    try:
        # Utilisez Google Speech Recognition
        texte = recognizer.recognize_google(audio, language='fr-FR')
        print("Vous avez dit:", texte)

        if texte.lower() == "quitter":
            with open("dep_joueur.c", "w") as fichier:
                fichier.write("quitter")  # Écrire le mot "quitter" dans le fichier dep_joueur.c
            return True  # Indiquer que l'utilisateur a demandé à quitter

    except sr.UnknownValueError:
        print("Google Speech Recognition n'a pas pu comprendre l'audio")
    except sr.RequestError as e:
        print("Impossible d'obtenir les résultats de Google Speech Recognition; {0}".format(e))

    return False  # Indiquer que l'utilisateur n'a pas demandé à quitter

# Exécuter la fonction une fois lors de l'import
reconnaissance_vocale()
