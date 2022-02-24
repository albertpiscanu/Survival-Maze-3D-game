#pragma once

#include "utils/glm_utils.h"
#include "utils/math_utils.h"
#include <iostream>

namespace implemented
{
    class Lista_de_proiectile_3D
    {
    public:
        Lista_de_proiectile_3D()
        {  
            this->numar_proiectile = 0;
        }
        

        ~Lista_de_proiectile_3D()
        { }
        
        void Add(const glm::mat3& model, const glm::vec3& pos, const glm::vec3& target)
        {
            struct proiectil x;
            x.activ = 1;
            x.modelMatrix = model;
            x.pos_proiectil = pos;
            x.target_proiectil = target;
            x.t = 0;
            x.T = RandomFloat(1, 3);
            this->proiectile.push_back(x);
            this->numar_proiectile++;
        }
        float RandomFloat(float a, float b)
        {
            float random = ((float)rand()) / (float)RAND_MAX;
            float diff = b - a;
            float r = random * diff;
            return a + r;
        }
        float distance(float x, float y, float a, float b) {
            return sqrt(pow(x - a, 2) + pow(y - b, 2));
        }
       
        void Calculeaza_pozitie_proiectile(const float& deltaTimeSeconds) {
            for (int j = 0; j < this->numar_proiectile; j++) {
                if (this->proiectile[j].activ == 1) {
                    this->proiectile[j].pos_proiectil = this->proiectile[j].pos_proiectil * (this->proiectile[j].T - this->proiectile[j].t) / this->proiectile[j].T 
                        + this->proiectile[j].target_proiectil * this->proiectile[j].t / this->proiectile[j].T;
                    this->proiectile[j].t += deltaTimeSeconds;
                    this->proiectile[j].modelMatrix[3][0] = this->proiectile[j].pos_proiectil[0];
                    this->proiectile[j].modelMatrix[3][1] = this->proiectile[j].pos_proiectil[1];
                    this->proiectile[j].modelMatrix[3][2] = this->proiectile[j].pos_proiectil[2];
                    if (this->proiectile[j].t >= this->proiectile[j].T 
                        || sqrt(pow(this->proiectile[j].pos_proiectil[0] - this->proiectile[j].target_proiectil[0], 2.0) + pow(this->proiectile[j].pos_proiectil[1] - this->proiectile[j].target_proiectil[1], 2.0)
                            + pow(this->proiectile[j].pos_proiectil[2] - this->proiectile[j].target_proiectil[2], 2.0)) < 0.1)
                    {
                        this->proiectile[j].activ = 0;
                    }
                }
            }
        }
        void coliziune_proiectil_labirint(std::vector<glm::vec3> labirint, float inaltime_labirint) {
            while (labirint.size()) {
                glm::vec3 cub = labirint.back();
                labirint.pop_back();
                for (int j = 0; j < this->numar_proiectile; j++)
                    if (this->proiectile[j].activ == 1 && 
                        abs(cub[0] - this->proiectile[j].modelMatrix[3][0]) < 3 && abs(cub[2] - this->proiectile[j].modelMatrix[3][2]) < 3 
                        && this->proiectile[j].modelMatrix[3][1] - inaltime_labirint < 0.25) {
                        if (sqrt(pow(this->proiectile[j].pos_proiectil[0] - cub[0], 2.0) + pow(this->proiectile[j].pos_proiectil[2] - cub[2], 2.0)) <= 0.75)
                            this->proiectile[j].activ = 0;
                    }
            }
        }
       
        
       
       
    public:
        struct proiectil
        {
            float activ;
            glm::vec3 pos_proiectil;
            glm::mat4 modelMatrix;
            float t;
            float T;
            glm::vec3 target_proiectil;

        };
   



    public:
        std::vector<proiectil> proiectile;
        float numar_proiectile;
       

    };
}   // namespace implemented
