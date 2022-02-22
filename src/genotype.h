#ifndef GENOTYPE_H
#define GENOTYPE_H
#define size_t unsigned long long

constexpr size_t gen_len = 2;

struct Genotype {
    char eye_allels[gen_len];
    char hair_allels[gen_len];
    char tounge_roll_allels[gen_len];

    Genotype();
    Genotype(const Genotype&, const Genotype&);
    ~Genotype();
    Genotype& operator=(const Genotype&);
};


#endif