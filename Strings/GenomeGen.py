# A program to generate a random genome sequence (containing G, A, T, C), and output to txt file in this directory

import random
from random import seed
from random import randint

nucleobases = 'ACGT'

rand = bool(input("Would you like the number of nucleobases to be random?"))

seed(1)

if rand:
    maximum = int(input("What would you like the max value to be?"))
    num = randint(0, maximum)
else:
    num = int(input("How many nucleobases would you like to generate?"))

genome = ''.join((random.choice(nucleobases) for i in range(num)))

f = open("Genomes/Genome" + str(num) + ".txt", "w")
f.write(str(genome))
f.close()

print("Genome" + str(num) + ".txt has been generated")
