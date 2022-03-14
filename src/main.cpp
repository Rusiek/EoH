#include <bits/stdc++.h>
#include "ur.h"

namespace ur {
    constexpr uint32_t MAX_AGE = 20;
    constexpr uint32_t REP_AGE = 3;
    constexpr uint32_t MID_AGE = 10;
    constexpr uint32_t EYE_NUM = 3;
    constexpr uint32_t KID_PROB = 10;
    constexpr uint32_t KID_RANG = 100;

    constexpr char eye[EYE_NUM] = {'B', 'G', 'S'};

    char eye_gen(ultra_rabit&, ultra_rabit&);
    char rand_eye(uint16_t, uint16_t, uint16_t);
}

uint16_t run_num = 50;
uint32_t MAX_TIME = 100;
uint32_t test_data = 125;

void kill(std::deque<ultra_rabit> &que);
void make_kids(std::deque<ultra_rabit> &que);
void remove_ROTP(std::deque<ultra_rabit> &que);
void gen_raport(std::deque<ultra_rabit> &que);
void make_older(std::deque<ultra_rabit> &que);

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    srand(time(NULL));

    while (run_num) {
        std::cout << "RAPORT: " << run_num << '\n';
        std::deque<ultra_rabit> rabbit;

        if (run_num > 40)
            for (uint32_t i = 0; i < test_data; ++i) {
                ultra_rabit astro;
                if (rand() % 2)   astro.eye = 'B';
                rabbit.push_back(astro);
            }
        else if (run_num > 30)
            for (uint32_t i = 0; i < test_data; ++i) {
                ultra_rabit astro;
                if (rand() % 2)   astro.eye = 'G';
                rabbit.push_back(astro);
            }
        else if (run_num > 20)
            for (uint32_t i = 0; i < test_data; ++i) {
                ultra_rabit astro;
                if (rand() % 2)   astro.eye = 'S';
                rabbit.push_back(astro);
            }
        else
            for (uint32_t i = 0; i < test_data; ++i) {
                ultra_rabit astro;
                rabbit.push_back(astro);
            }
        
        uint32_t clock = 0;
        while (clock <= MAX_TIME) {
            kill(rabbit);
            make_kids(rabbit);
            remove_ROTP(rabbit);
            if (clock % 5 == 0) gen_raport(rabbit);
            make_older(rabbit);
            ++clock;
        }
        
        --run_num;
    }

    return 0;
}

void kill(std::deque<ultra_rabit> &que) {
    for (auto &i: que)
        if (!i.ROTP) {
            uint64_t poss = 1;
            uint64_t d_rng = 1;
            for (uint8_t j = 0; j < 5; ++j) {
                poss *= ur::MAX_AGE;
                d_rng *= i.age;
            }
            uint64_t magic_const = 1152;
            uint64_t rnd = (rand() * rand() * rand() * rand() / magic_const) % poss;
            if (rnd < d_rng) i.ROTP = true;
        }
}
void make_kids(std::deque<ultra_rabit> &que) {
    int mini = 0, maxi = 0;
    int starto =   0;
    int endo   =   que.size() - 1;
    int middo  =   (starto + endo) / 2;
    while (starto < endo) {
        if      (que[middo].age >= ur::REP_AGE)  endo    =   middo - 1;
        else if (que[middo].age <  ur::REP_AGE)  starto  =   middo + 1;
        middo = (starto + endo) / 2;
    }
    mini = middo;

    starto =   0;
    endo   =   que.size() - 1;
    middo  =   (starto + endo) / 2;

    while (starto < endo) {
        if      (que[middo].age >  ur::MID_AGE)  endo    =   middo - 1;
        else if (que[middo].age <= ur::MID_AGE)  starto  =   middo + 1;
        middo = (starto + endo) / 2;
    }
    maxi = middo;
    
    uint64_t range = maxi - mini + 1;
    if (range == 1) return;
    for (uint64_t i = 0; i < range; ++i) {
        uint32_t x, y;
        do {
            x = rand() % range + mini;
        }   while (que[x].ROTP);
        do {
            y = rand() % range + mini;
        }   while (que[y].ROTP);
        if (rand() % ur::KID_RANG < ur::KID_PROB && x != y) {
            ultra_rabit kid(que[x], que[y]);
            que.push_back(kid);
        }
    }

}
void remove_ROTP(std::deque<ultra_rabit> &que) {
    while (!que.empty()) {
        if (que.front().ROTP)
            que.pop_front();
        else break;
    }
}
void gen_raport(std::deque<ultra_rabit> &que) {
    uint64_t B = 0, G = 0, S = 0;
    for (auto &i: que) {
        if (!i.ROTP) {
            if (i.eye == 'B')   ++B;
            if (i.eye == 'G')   ++G;
            if (i.eye == 'S')   ++S;
        }
    }
    std::cout << B << " " << G << " " << S << "\n";
}
void make_older(std::deque<ultra_rabit> &que) {
    for (auto &i: que)
        ++i.age;
}
