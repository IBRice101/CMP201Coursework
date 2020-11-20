# A program to generate a random genome sequence (containing G, A, T, C), and output to txt file in this directory

import random

nucleobases = 'ACGT'

num = int(input("How many nucleobases would you like to generate?"))

genome = ''.join((random.choice(nucleobases) for i in range(num)))

f = open("genome" + str(num) + ".txt", "w")
f.write(str(genome))
f.close()

print("genome" + str(num) + ".txt has been generated")
