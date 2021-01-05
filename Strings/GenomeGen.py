# A program to generate a random genome sequence (containing G, A, T, C), and output to txt file in this directory

import random
from random import seed
from random import randint

nucleobases = 'ACGT'

rand = bool(input("Would you like the number of nucleobases to be random (1/0)?: "))

seed(8)

if rand == 1:
    maximum = int(input("What would you like the max value to be?: "))
    charNum = randint(0, maximum)
else:
    charNum = int(input("How many nucleobases would you like to generate?: "))

genome = ''.join((random.choice(nucleobases) for i in range(charNum)))

f = open("Genomes/Genome" + str(charNum) + ".txt", "w")
f.write(str(genome))
f.close()

print("Genome" + str(charNum) + ".txt has been generated")
