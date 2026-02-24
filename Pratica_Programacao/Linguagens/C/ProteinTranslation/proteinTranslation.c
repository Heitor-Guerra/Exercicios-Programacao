#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define MAX_AMINO_ACIDS 10

typedef enum {
  Methionine,
  Phenylalanine,
  Leucine,
  Serine,
  Tyrosine,
  Cysteine,
  Tryptophan,
} amino_acid_t;

typedef struct {
  bool valid;
  size_t count;
  amino_acid_t amino_acids[MAX_AMINO_ACIDS];
} protein_t;

const char listCodon[17][4] = {
    "AUG", "UUU", "UUC", "UUA", "UUG", "UCU", "UCC", "UCA", "UCG",
    "UAU", "UAC", "UGU", "UGC", "UGG", "UAA", "UAG", "UGA",
};

int searchCodon(char *codon) {
  for (int i = 0; i < 17; i++) {
    if (strcmp(codon, listCodon[i]) == 0) {
      return i;
    }
  }
  return -1;
}

protein_t protein(const char *const rna) {
  protein_t protein;
  protein.valid = true;
  protein.count = 0;

  char codon[4];
  for (size_t i = 0; *(rna + i); i += 3) {
    if (i > strlen(rna)) {
      protein.valid = false;
      return protein;
    }

    sscanf(rna + i, "%3s", codon);
    int index = searchCodon(codon);

    if (index == -1) {
      protein.valid = false;
      return protein;
    } else if (index == 0) {
      protein.amino_acids[protein.count] = Methionine;
    } else if (index >= 1 && index <= 2) {
      protein.amino_acids[protein.count] = Phenylalanine;
    } else if (index >= 3 && index <= 4) {
      protein.amino_acids[protein.count] = Leucine;
    } else if (index >= 5 && index <= 8) {
      protein.amino_acids[protein.count] = Serine;
    } else if (index >= 9 && index <= 10) {
      protein.amino_acids[protein.count] = Tyrosine;
    } else if (index >= 11 && index <= 12) {
      protein.amino_acids[protein.count] = Cysteine;
    } else if (index == 13) {
      protein.amino_acids[protein.count] = Tryptophan;
    } else {
      return protein;
    }

    protein.count++;
  }
  return protein;
}
