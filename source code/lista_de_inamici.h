#pragma once

#include "utils/glm_utils.h"
#include "utils/math_utils.h"
#include <iostream>


namespace implemented
{
    class Lista_de_inamici_Veemon
    {
    public:
        Lista_de_inamici_Veemon()
        {  
            this->numar_inamici = 0;
            this->inamici_invinsi = 0;
        }
        

        ~Lista_de_inamici_Veemon()
        { }
        
        void Add(const float &pozitie_x, const float &pozitie_z)
        {
            struct inamic x;
            x.pozitie_initiala_x = pozitie_x;
            x.pozitie_initiala_z = pozitie_z;
            x.pozitie_initiala_y = 0.5;
            x.pozitie_actuala_x = pozitie_x;
            x.pozitie_actuala_z = pozitie_z;
            x.activ = 1;
            x.ti = 0;
            x.tj = 0;
            x.v = RandomFloat(1.2, 2);
            x.modelMatrix = glm::mat4(1);
            x.culoare = glm::vec3(RandomFloat(0, 1), RandomFloat(0, 1), RandomFloat(0, 1));
            x.efect_shader = 0;
            this->inamici.push_back(x);
            this->numar_inamici++;
    
        }
        float RandomFloat(float a, float b)
        {
            float random = ((float)rand()) / (float)RAND_MAX;
            float diff = b - a;
            float r = random * diff;
            return a + r;
        }

        void Calculeaza_pozitie_actuala(const float &deltaTimeSeconds) {
            for (int i = 0; i < this->numar_inamici; i++) {
                if (inamici[i].efect_shader > 0) {
                    this->inamici[i].efect_shader -= deltaTimeSeconds;
                    if (this->inamici[i].efect_shader < 0)
                        this->inamici[i].efect_shader = 0;
                }
                if (inamici[i].activ == 1) {
                    int angle_inamic = 0;
                    if (inamici[i].ti == 0 && inamici[i].tj < 2)
                        this->inamici[i].tj += inamici[i].v * deltaTimeSeconds;
                    else if (inamici[i].ti < 2 && inamici[i].tj == 2)
                        this->inamici[i].ti += inamici[i].v * deltaTimeSeconds;
                    else if (inamici[i].ti == 2 && inamici[i].tj > 0)
                        this->inamici[i].tj += -inamici[i].v * deltaTimeSeconds;
                    else if (inamici[i].ti > 0 && inamici[i].tj == 0)
                        this->inamici[i].ti += -inamici[i].v * deltaTimeSeconds;

                    if (inamici[i].ti < 0) inamici[i].ti = 0;
                    if (inamici[i].tj < 0) inamici[i].tj = 0;
                    if (inamici[i].ti > 2) inamici[i].ti = 2;
                    if (inamici[i].tj > 2) inamici[i].tj = 2;
                    if (inamici[i].ti < 2 && inamici[i].tj == 2)
                    {
                        angle_inamic = 90;
                    }
                    else if (inamici[i].ti == 2 && inamici[i].tj > 0) {
                        angle_inamic = 180;
                    }
                    else if (inamici[i].ti == 0 && inamici[i].tj < 2) {
                        angle_inamic = 0;
                    }
                    else if (inamici[i].ti > 0 && inamici[i].tj == 0) {
                        angle_inamic = 270;
                    }
                    this->inamici[i].pozitie_actuala_x = inamici[i].pozitie_initiala_x + inamici[i].ti;
                    this->inamici[i].pozitie_actuala_z = inamici[i].pozitie_initiala_z + inamici[i].tj;
                    this->inamici[i].modelMatrix = glm::translate(glm::mat4(1), glm::vec3(inamici[i].pozitie_actuala_x + 0.5, 0, 
                        inamici[i].pozitie_actuala_z + 0.5))
                        * glm::rotate(glm::mat4(1), RADIANS(angle_inamic), glm::vec3(0, 1, 0))
                        * glm::scale(glm::mat4(1), glm::vec3(0.03, 0.03, 0.03));
                }
            }
        }
        int coliziune_inamici_proiectil(const float& proiectil_x, const float& proiectil_y, const float& proiectil_z) {
           
            for (int j = 0; j < numar_inamici; j++) {
                if (inamici[j].activ == 1) {
                    if (sqrt(pow(inamici[j].pozitie_actuala_x + 0.5 - proiectil_x, 2) + pow(inamici[j].pozitie_initiala_y + 0.5 - proiectil_y, 2) + pow(inamici[j].pozitie_actuala_z + 0.5 - proiectil_z, 2)) < 0.5)
                    {
                        this->inamici[j].activ = 0;
                        this->inamici[j].efect_shader = 2;
                        return 1;
                    }
                }
            }


            return 0;
            
        }


        float coliziune_inamic_jucator(const float &jucator_x, const float& jucator_z, const float& viata) {
            float health = viata;
            for (int j = 0; j < numar_inamici; j++) {
                if (inamici[j].activ == 1) {
                    if (sqrt(pow(inamici[j].pozitie_actuala_x + 0.5 - jucator_x, 2) + pow(inamici[j].pozitie_actuala_z + 0.5 - jucator_z, 2)) < 0.5)
                    {
                        health -= 0.1;
                        break;
                    }
                    }
                }
            return health;
            
        }
       
    public:
        
        struct inamic
        {
            float pozitie_initiala_x;
            float pozitie_initiala_z;
            float pozitie_initiala_y;
            float pozitie_actuala_x;
            float pozitie_actuala_z;
            float ti, tj, v;
            int activ;
            float efect_shader;
            glm::vec3 culoare;
            glm::mat4 modelMatrix;

        };

    public:
        std::vector<inamic> inamici;
        float numar_inamici;
        float inamici_invinsi;
       

    };
}   // namespace implemented
