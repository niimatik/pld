#!/usr/bin/python3
from collections import Counter

eleves_poudlard = ["Harry Potter", "Hermione Granger", "Ron Weasley", "Drago Malfoy", 
                  "Neville Londubat", "Luna Lovegood", "Ginny Weasley", "Cho Chang"]
maisons = {
    "Harry Potter": "Gryffondor",
    "Hermione Granger": "Gryffondor",
    "Ron Weasley": "Gryffondor",
    "Draco Malfoy": "Serpentard",
    "Luna Lovegood": "Serdaigle",
    "Cho Chang": "Serdaigle",
    "Cedric Diggory": "Poufsouffle",
    "Neville Londubat": "Gryffondor"
}
taille_maison = {
    "Gryffondor": 0,
    "Serdaigle": 0,
    "Poufsouffle": 0,
    "Serpentard": 0
}
sorts = [
    ("Wingardium Leviosa", "Fait léviter des objets", 2),
    ("Expelliarmus", "Désarme l'adversaire", 3),
    ("Expecto Patronum", "Repousse les Détraqueurs", 5),
    ("Accio", "Attire un objet vers le lanceur", 2),
    ("Avada Kedavra", "Sort mortel impardonnable", 5)
]
personnages = {
    "Albus Dumbledore": (115, "Directeur", ["Métamorphose", "Sortilèges", "Duel"]),
    "Severus Rogue": (38, "Professeur", ["Potions", "Occlumancie", "Sortilèges"]),
    "Minerva McGonagall": (70, "Professeur", ["Métamorphose", "Duel"]),
    "Rubeus Hagrid": (65, "Garde-chasse", ["Créatures magiques"])
}
competence = {
    "Métamorphose": 0,
    "Sortilèges": 0,
    "Duel": 0,
    "Potions": 0,
    "Occlumancie": 0,
    "Créatures magiques": 0
}
champions = [
    {"nom": "Harry Potter", "école": "Poudlard", "scores": [8, 7, 9]},
    {"nom": "Cedric Diggory", "école": "Poudlard", "scores": [7, 8, 6]},
    {"nom": "Viktor Krum", "école": "Durmstrang", "scores": [9, 6, 8]},
    {"nom": "Fleur Delacour", "école": "Beauxbâtons", "scores": [6, 9, 7]}
]
sorts_facile = []
professeur = []
eleves_poudlard.append('Cedric Diggory')
eleves_poudlard.remove('Drago Malfoy')
print("{}".format(eleves_poudlard[0:3]))
print()
eleves_poudlard.sort()
print(eleves_poudlard)
print()
maisons["Ginny Weasley"] = "Gryffondor"
print(maisons)
print()
for k, v in maisons.items():
    if v in taille_maison:
        taille_maison[v] += 1
print(taille_maison)
for i in maisons:
    if maisons[i] == 'Gryffondor':
        print(i, end=' ')
print('\n')
for i in range(0, len(sorts)):
    print(sorts[i][0], end=' ')
print('\n')
for i in range(0, len(sorts)):
    if sorts[i][2] <= 2:
        sorts_facile.append(sorts[i][0])
print(sorts_facile)
print()
sorts.sort(key=lambda x: x[2])
print(sorts)
print()
personnages["Albus Dumbledore"][2].append("Transplanage")
print(personnages["Albus Dumbledore"])
print()
for k in personnages:
    professeur.append(k)
print(professeur)
print()
for i in competence:
    for j in personnages:
        for k in personnages[j][2]:
            if k == i:
                competence[i] += 1
print(competence)
print()
champion = []
point = 0
for i in range(len(champions)):
    total = champions[i].get("scores")
    for j in total:
        point += j
    total = []
    champion.append(point)
    point = 0
champion.sort(reverse=True)
print("Harry Potter est le vainqueur de la coupe de feu avec {:d}".format(champion[0]))
