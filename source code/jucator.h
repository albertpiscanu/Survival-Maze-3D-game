#pragma once

#include "utils/glm_utils.h"
#include "utils/math_utils.h"
#include <iostream>

using namespace std;


namespace implemented
{
    class Jucator_3D
    {
    public:
        Jucator_3D()
        {
            struct body corp;
            this->componente_jucator.push_back(corp);
            this->componente_jucator.push_back(corp);
            this->componente_jucator.push_back(corp);
            this->componente_jucator.push_back(corp);
            this->componente_jucator.push_back(corp);
            this->componente_jucator.push_back(corp);
            this->componente_jucator.push_back(corp);
            componente_jucator[0].centruX_initial = -0.2; 
            componente_jucator[0].centruY_initial = 0.25;
            componente_jucator[0].centruZ_initial = 0;
            componente_jucator[0].scaleX = 0.5;
            componente_jucator[0].scaleY = 1;
            componente_jucator[0].scaleZ = 0.5;
            componente_jucator[0].culoare = glm::vec3(1, 0, 0);
            componente_jucator[1].centruX_initial = 0.2;
            componente_jucator[1].centruY_initial = 0.25;
            componente_jucator[1].centruZ_initial = 0;
            componente_jucator[1].scaleX = 0.5;
            componente_jucator[1].scaleY = 1;
            componente_jucator[1].scaleZ = 0.5;
            componente_jucator[1].culoare = glm::vec3(1, 0, 0);
            componente_jucator[2].centruX_initial = 0;
            componente_jucator[2].centruY_initial = 0.9;
            componente_jucator[2].centruZ_initial = 0;
            componente_jucator[2].scaleX = 1;
            componente_jucator[2].scaleY = 1.5;
            componente_jucator[2].scaleZ = 0.5;
            componente_jucator[2].culoare = glm::vec3(0, 0, 1);
            componente_jucator[3].centruX_initial = 0;
            componente_jucator[3].centruY_initial = 1.45;
            componente_jucator[3].centruZ_initial = 0;
            componente_jucator[3].scaleX = 0.5;
            componente_jucator[3].scaleY = 0.5;
            componente_jucator[3].scaleZ = 0.5;
            componente_jucator[3].culoare = glm::vec3(0.721, 0.470, 0.098);
            componente_jucator[4].centruX_initial = -0.4;
            componente_jucator[4].centruY_initial = 1.2;
            componente_jucator[4].centruZ_initial = 0;
            componente_jucator[4].scaleX = 0.5;
            componente_jucator[4].scaleY = 0.7;
            componente_jucator[4].scaleZ = 0.5;
            componente_jucator[4].culoare = glm::vec3(0, 1, 1);
            componente_jucator[5].centruX_initial = 0.4;
            componente_jucator[5].centruY_initial = 1.2;
            componente_jucator[5].centruZ_initial = 0;
            componente_jucator[5].scaleX = 0.5;
            componente_jucator[5].scaleY = 0.7;
            componente_jucator[5].scaleZ = 0.5;
            componente_jucator[5].culoare = glm::vec3(0, 1, 1);
            componente_jucator[6].centruX_initial = 0.4;
            componente_jucator[6].centruY_initial = 1.2;
            componente_jucator[6].centruZ_initial = 0.9;
            componente_jucator[6].scaleX = 0.25;
            componente_jucator[6].scaleY = 0.25;
            componente_jucator[6].scaleZ = 0.25;
            componente_jucator[6].culoare = glm::vec3(1, 0, 0);
            for (int i = 0;i <= 5;i++) {
                componente_jucator[i].scaleX /= 2;
                componente_jucator[i].scaleY /= 2;
                componente_jucator[i].scaleZ /= 2;
            }
        }
        Jucator_3D(const float &translateX, const float &translateZ, const float &angle)
        {
            Set(translateX, translateZ, angle, 0);
        }

        ~Jucator_3D()
        { }
        
        void Set(const float& translateX, const float& translateZ, const float &angle, int shoot)
        {
            if (shoot == 1) {
                componente_jucator[5].centruX_initial = 0.4;
                componente_jucator[5].centruY_initial = 1.2;
                componente_jucator[5].centruZ_initial = 0.4;
                componente_jucator[5].scaleX = 0.25 ;
                componente_jucator[5].scaleY = 0.25;
                componente_jucator[5].scaleZ = 0.75;
            }
            else {
                componente_jucator[5].centruX_initial = 0.4;
                componente_jucator[5].centruY_initial = 1.2;
                componente_jucator[5].centruZ_initial = 0;
                componente_jucator[5].scaleX = 0.25;
                componente_jucator[5].scaleY = 0.35;
                componente_jucator[5].scaleZ = 0.25;
            }
            this->angle = -angle;
            this->translate_x = translateX;
            this->translate_z = translateZ;
            for (int i = 0; i < 7;i++) {
                glm::mat4 modelMatrix = glm::mat4(1);
                this->componente_jucator[i].modelMatrix = modelMatrix * glm::translate(modelMatrix, glm::vec3(translateX, 0, translateZ)) *
                    glm::rotate(modelMatrix, angle, glm::vec3(0, 1, 0)) *
                    glm::translate(modelMatrix, glm::vec3(componente_jucator[i].centruX_initial, componente_jucator[i].centruY_initial, componente_jucator[i].centruZ_initial))*
                    glm::scale(modelMatrix, glm::vec3(componente_jucator[i].scaleX, componente_jucator[i].scaleY, componente_jucator[i].scaleZ));
               
               
        }
            
            
        }
   
        float distance(float x, float y, float a, float b) {
            return sqrt(pow(x - a, 2) + pow(y - b, 2));
        }
        glm::vec2 FootCoordinate(float a, float b, float c, float x1, float y1) {
            glm::vec2 coord = glm::vec2(0);
            float p = -1 * (a * x1 + b * y1 + c) / (a * a + b * b);
            float x = p * a + x1;
            float y = p * b + y1;
            coord[0] = x;
            coord[1] = y;
            return coord;

        }
        glm::vec3 CheckFootMinMax(float a, float b, float c, glm::mat4x3 varfuri_jos, glm::mat4x3 varfuri_sus, glm::mat4x3 varfuri_jos_cub_labirint, 
            glm::mat4x3 varfuri_sus_cub_labirint,float indice){
            float amin = 500;
            float amax = -500;
            float bmin = 500;
            float bmax = -500;
            float miny0 = varfuri_jos[0][indice];
            float maxy0 = varfuri_jos[0][indice];
            float miny1 = varfuri_jos_cub_labirint[0][indice];
            float maxy1 = varfuri_jos_cub_labirint[0][indice];
            if (varfuri_jos[1][indice] < miny0)
                miny0 = varfuri_jos[1][indice];
            if (varfuri_jos[2][indice] < miny0)
                miny0 = varfuri_jos[2][indice];
            if (varfuri_jos[3][indice] < miny0)
                miny0 = varfuri_jos[3][indice];
            if (varfuri_jos[1][indice] > maxy0)
                maxy0 = varfuri_jos[1][indice];
            if (varfuri_jos[2][indice] > maxy0)
                maxy0 = varfuri_jos[2][indice];
            if (varfuri_jos[3][indice] > maxy0)
                maxy0 = varfuri_jos[3][indice];

            if (varfuri_sus[1][indice] < miny0)
                miny0 = varfuri_sus[1][indice];
            if (varfuri_sus[2][indice] < miny0)
                miny0 = varfuri_sus[2][indice];
            if (varfuri_sus[3][indice] < miny0)
                miny0 = varfuri_sus[3][indice];
            if (varfuri_sus[1][indice] > maxy0)
                maxy0 = varfuri_sus[1][indice];
            if (varfuri_sus[2][indice] > maxy0)
                maxy0 = varfuri_sus[2][indice];
            if (varfuri_sus[3][indice] > maxy0)
                maxy0 = varfuri_sus[3][indice];

            if (varfuri_jos_cub_labirint[1][indice] < miny1)
                miny1 = varfuri_jos_cub_labirint[1][indice];
            if (varfuri_jos_cub_labirint[2][indice] < miny1)
                miny1 = varfuri_jos_cub_labirint[2][indice];
            if (varfuri_jos_cub_labirint[3][indice] < miny1)
                miny1 = varfuri_jos_cub_labirint[3][indice];
            if (varfuri_jos_cub_labirint[1][indice] > maxy1)
                maxy1 = varfuri_jos_cub_labirint[1][indice];
            if (varfuri_jos_cub_labirint[2][indice] > maxy1)
                maxy1 = varfuri_jos_cub_labirint[2][indice];
            if (varfuri_jos_cub_labirint[3][indice] > maxy1)
                maxy1 = varfuri_jos_cub_labirint[3][indice];

            if (varfuri_sus_cub_labirint[1][indice] < miny1)
                miny1 = varfuri_sus_cub_labirint[1][indice];
            if (varfuri_sus_cub_labirint[2][indice] < miny1)
                miny1 = varfuri_sus_cub_labirint[2][indice];
            if (varfuri_sus_cub_labirint[3][indice] < miny1)
                miny1 = varfuri_sus_cub_labirint[3][indice];
            if (varfuri_sus_cub_labirint[1][indice] > maxy1)
                maxy1 = varfuri_sus_cub_labirint[1][indice];
            if (varfuri_sus_cub_labirint[2][indice] > maxy1)
                maxy1 = varfuri_sus_cub_labirint[2][indice];
            if (varfuri_sus_cub_labirint[3][indice] > maxy1)
                maxy1 = varfuri_sus_cub_labirint[3][indice];


            glm::vec2 coord;
            coord = FootCoordinate(a, b, c, varfuri_jos[0][0], varfuri_jos[0][indice]);
            if (coord[0] < amin)
                amin = coord[0];
            if (coord[0] > amax)
                amax = coord[0];
            coord = FootCoordinate(a, b, c, varfuri_jos[1][0], varfuri_jos[1][indice]);
            if (coord[0] < amin)
                amin = coord[0];
            if (coord[0] > amax)
                amax = coord[0];
            coord = FootCoordinate(a, b, c, varfuri_jos[2][0], varfuri_jos[2][indice]);
            if (coord[0] < amin)
                amin = coord[0];
            if (coord[0] > amax)
                amax = coord[0];
            coord = FootCoordinate(a, b, c, varfuri_jos[3][0], varfuri_jos[3][indice]);
            if (coord[0] < amin)
                amin = coord[0];
            if (coord[0] > amax)
                amax = coord[0];
            coord = FootCoordinate(a, b, c, varfuri_sus[0][0], varfuri_sus[0][indice]);
            if (coord[0] < amin)
                amin = coord[0];
            if (coord[0] > amax)
                amax = coord[0];
            coord = FootCoordinate(a, b, c, varfuri_sus[1][0], varfuri_sus[1][indice]);
            if (coord[0] < amin)
                amin = coord[0];
            if (coord[0] > amax)
                amax = coord[0];
            coord = FootCoordinate(a, b, c, varfuri_sus[2][0], varfuri_sus[2][indice]);
            if (coord[0] < amin)
                amin = coord[0];
            if (coord[0] > amax)
                amax = coord[0];
            coord = FootCoordinate(a, b, c, varfuri_sus[3][0], varfuri_sus[3][indice]);
            if (coord[0] < amin)
                amin = coord[0];
            if (coord[0] > amax)
                amax = coord[0];



            coord = FootCoordinate(a, b, c, varfuri_jos_cub_labirint[0][0], varfuri_jos_cub_labirint[0][indice]);
            if (coord[0] < bmin)
                bmin = coord[0];
            if (coord[0] > bmax)
                bmax = coord[0];
            coord = FootCoordinate(a, b, c, varfuri_jos_cub_labirint[1][0], varfuri_jos_cub_labirint[1][indice]);
            if (coord[0] < bmin)
                bmin = coord[0];
            if (coord[0] > bmax)
                bmax = coord[0];
            coord = FootCoordinate(a, b, c, varfuri_jos_cub_labirint[2][0], varfuri_jos_cub_labirint[2][indice]);
            if (coord[0] < bmin)
                bmin = coord[0];
            if (coord[0] > bmax)
                bmax = coord[0];
            coord = FootCoordinate(a, b, c, varfuri_jos_cub_labirint[3][0], varfuri_jos_cub_labirint[3][indice]);
            if (coord[0] < bmin)
                bmin = coord[0];
            if (coord[0] > bmax)
                bmax = coord[0];
            coord = FootCoordinate(a, b, c, varfuri_sus_cub_labirint[0][0], varfuri_sus_cub_labirint[0][indice]);
            if (coord[0] < bmin)
                bmin = coord[0];
            if (coord[0] > bmax)
                bmax = coord[0];
            coord = FootCoordinate(a, b, c, varfuri_sus_cub_labirint[1][0], varfuri_sus_cub_labirint[1][indice]);
            if (coord[0] < bmin)
                bmin = coord[0];
            if (coord[0] > bmax)
                bmax = coord[0];
            coord = FootCoordinate(a, b, c, varfuri_sus_cub_labirint[2][0], varfuri_sus_cub_labirint[2][indice]);
            if (coord[0] < bmin)
                bmin = coord[0];
            if (coord[0] > bmax)
                bmax = coord[0];
            coord = FootCoordinate(a, b, c, varfuri_sus_cub_labirint[3][0], varfuri_sus_cub_labirint[3][indice]);
            if (coord[0] < bmin)
                bmin = coord[0];
            if (coord[0] > bmax)
                bmax = coord[0];
            glm::vec3 depasire_labirint = glm::vec3(0);
            if (amin <= bmin)
            {
                if (amax < bmin)
                    return glm::vec3(0);
                else depasire_labirint[0] =   -bmin + amax;
            }
            else
            {
                if (amin > bmax)
                    return glm::vec3(0);
                else depasire_labirint[0] =  -bmax + amin;

            }


            if (miny0 <= miny1) {
                if (maxy0 < miny1)
                    return glm::vec3(0);
                else depasire_labirint[indice] =  miny1 - maxy0;
            }
            else
            {
                if (miny0 > maxy1)
                    return glm::vec3(0);
                else depasire_labirint[indice] =   -miny0 + maxy1;
            }


            return depasire_labirint;
        }
        glm::vec3 coliziune_cub_cub(glm::vec3 cub_labirint, float inaltime_labirint, int index_corp) {
            
            
            
            glm::vec3 center = glm::vec3(this->componente_jucator[index_corp].centruX_initial, this->componente_jucator[index_corp].centruY_initial, this->componente_jucator[index_corp].centruZ_initial);
            glm::mat4x3 varfuri_jos;
            glm::mat4x3 varfuri_sus;
            float x0 = center[0] + this->componente_jucator[index_corp].scaleX / 2;
            float y0 = center[1] - this->componente_jucator[index_corp].scaleY / 2;
            float z0 = center[2] - this->componente_jucator[index_corp].scaleZ / 2;
            float sizex0 = -this->componente_jucator[index_corp].scaleX;
            float sizey0 = this->componente_jucator[index_corp].scaleY;
            float sizez0 = this->componente_jucator[index_corp].scaleZ;
            varfuri_jos[0][0] = -z0 * sin(this->angle) + x0 * cos(this->angle) + translate_x;
            varfuri_jos[0][1] = y0;
            varfuri_jos[0][2] = z0 * cos(this->angle) + x0 * sin(this->angle) + translate_z;
            varfuri_jos[1][0] = -z0 * sin(this->angle) + (x0 + sizex0) * cos(this->angle) + translate_x;
            varfuri_jos[1][1] = y0;
            varfuri_jos[1][2] = z0 * cos(this->angle) + (x0 + sizex0) * sin(this->angle) + translate_z;
            varfuri_jos[2][0] = -(z0 + sizez0) * sin(this->angle) + x0 * cos(this->angle) + translate_x;
            varfuri_jos[2][1] = y0;
            varfuri_jos[2][2] = (z0 + sizez0) * cos(this->angle) + x0 * sin(this->angle) + translate_z;
            varfuri_jos[3][0] = -(z0 + sizez0) * sin(this->angle) + (x0 + sizex0) * cos(this->angle) + translate_x;
            varfuri_jos[3][1] = y0;
            varfuri_jos[3][2] = (z0 + sizez0) * cos(this->angle) + (x0 + sizex0) * sin(this->angle) + translate_z;
            for (int k = 0;k < 4; k++) {
                varfuri_sus[k][0] = varfuri_jos[k][0];
                varfuri_sus[k][1] = varfuri_jos[k][1] + sizey0;
                varfuri_sus[k][2] = varfuri_jos[k][2];
            }

            glm::mat4x3 varfuri_jos_cub_labirint;
            glm::mat4x3 varfuri_sus_cub_labirint;
            varfuri_jos_cub_labirint[0][0] = cub_labirint[0] + 0.5;
            varfuri_jos_cub_labirint[0][1] = cub_labirint[1] - inaltime_labirint/2;
            varfuri_jos_cub_labirint[0][2] = cub_labirint[2] - 0.5;
            varfuri_jos_cub_labirint[1][0] = cub_labirint[0] - 0.5;
            varfuri_jos_cub_labirint[1][1] = cub_labirint[1] - inaltime_labirint / 2;
            varfuri_jos_cub_labirint[1][2] = cub_labirint[2] - 0.5;
            varfuri_jos_cub_labirint[2][0] = cub_labirint[0] + 0.5;
            varfuri_jos_cub_labirint[2][1] = cub_labirint[1] - inaltime_labirint / 2;
            varfuri_jos_cub_labirint[2][2] = cub_labirint[2] + 0.5;
            varfuri_jos_cub_labirint[3][0] = cub_labirint[0] - 0.5;
            varfuri_jos_cub_labirint[3][1] = cub_labirint[1] - inaltime_labirint / 2;
            varfuri_jos_cub_labirint[3][2] = cub_labirint[2] + 0.5;
            for (int k = 0;k < 4; k++) {
                varfuri_sus_cub_labirint[k][0] = varfuri_jos_cub_labirint[k][0];
                varfuri_sus_cub_labirint[k][1] = varfuri_jos_cub_labirint[k][1] + inaltime_labirint;
                varfuri_sus_cub_labirint[k][2] = varfuri_jos_cub_labirint[k][2];
            }
            

            glm::vec3 depasire_labirint = glm::vec3(0);

            glm::vec3 depasire = glm::vec3(0);
            depasire = CheckFootMinMax(varfuri_jos[1][2] - varfuri_jos[0][2], varfuri_jos[0][0] - varfuri_jos[1][0],
                -(varfuri_jos[1][2] - varfuri_jos[0][2]) * varfuri_jos[0][0] - (varfuri_jos[0][0] - varfuri_jos[1][0]) * varfuri_jos[0][2],
                varfuri_jos, varfuri_sus, varfuri_jos_cub_labirint, varfuri_sus_cub_labirint, 2);
            if (depasire == glm::vec3(0))
                return depasire;
            if (abs(depasire[0]) > abs(depasire_labirint[0]))
                depasire_labirint[0] = depasire[0];
            if (abs(depasire[1]) > abs(depasire_labirint[1]))
                depasire_labirint[1] = depasire[1];
            if (abs(depasire[2]) > abs(depasire_labirint[2]))
                depasire_labirint[2] = depasire[2];

            depasire = CheckFootMinMax(varfuri_jos[3][2] - varfuri_jos[1][2], varfuri_jos[1][0] - varfuri_jos[3][0],
                    -(varfuri_jos[3][2] - varfuri_jos[1][2]) * varfuri_jos[1][0] - (varfuri_jos[1][0] - varfuri_jos[3][0]) * varfuri_jos[1][2],
                    varfuri_jos, varfuri_sus, varfuri_jos_cub_labirint, varfuri_sus_cub_labirint,2);
            if (depasire == glm::vec3(0))
                return depasire;
            if (abs(depasire[0]) > abs(depasire_labirint[0]))
                depasire_labirint[0] = depasire[0];
            if (abs(depasire[1]) > abs(depasire_labirint[1]))
                depasire_labirint[1] = depasire[1];
            if (abs(depasire[2]) > abs(depasire_labirint[2]))
                depasire_labirint[2] = depasire[2];

            depasire = CheckFootMinMax(varfuri_sus[1][1] - varfuri_jos[1][1], varfuri_jos[1][0] - varfuri_sus[1][0],
                -(varfuri_sus[1][1] - varfuri_jos[1][1]) * varfuri_jos[1][0] - (varfuri_jos[1][0] - varfuri_sus[1][0]) * varfuri_jos[1][1],
                varfuri_jos, varfuri_sus, varfuri_jos_cub_labirint, varfuri_sus_cub_labirint, 1);
            if (depasire == glm::vec3(0))
                return depasire;
            if (abs(depasire[0]) > abs(depasire_labirint[0]))
                depasire_labirint[0] = depasire[0];
            if (abs(depasire[1]) > abs(depasire_labirint[1]))
                depasire_labirint[1] = depasire[1];
            if (abs(depasire[2]) > abs(depasire_labirint[2]))
                depasire_labirint[2] = depasire[2];

            depasire = CheckFootMinMax(varfuri_jos_cub_labirint[1][2] - varfuri_jos_cub_labirint[0][2], varfuri_jos_cub_labirint[0][0]
                - varfuri_jos_cub_labirint[1][0], -(varfuri_jos_cub_labirint[1][2] - varfuri_jos_cub_labirint[0][2]) * varfuri_jos_cub_labirint[0][0]
                - (varfuri_jos_cub_labirint[0][0] - varfuri_jos_cub_labirint[1][0]) * varfuri_jos_cub_labirint[0][2],
                varfuri_jos, varfuri_sus, varfuri_jos_cub_labirint, varfuri_sus_cub_labirint, 2);
            if (depasire == glm::vec3(0))
                return depasire;
            if (abs(depasire[0]) > abs(depasire_labirint[0]))
                depasire_labirint[0] = depasire[0];
            if (abs(depasire[1]) > abs(depasire_labirint[1]))
                depasire_labirint[1] = depasire[1];
            if (abs(depasire[2])> abs(depasire_labirint[2]))
                depasire_labirint[2] = depasire[2];


            depasire = CheckFootMinMax(varfuri_jos_cub_labirint[3][2] - varfuri_jos_cub_labirint[1][2], varfuri_jos_cub_labirint[1][0]
                - varfuri_jos_cub_labirint[3][0], -(varfuri_jos_cub_labirint[3][2] - varfuri_jos_cub_labirint[1][2]) * varfuri_jos_cub_labirint[1][0]
                - (varfuri_jos_cub_labirint[1][0] - varfuri_jos_cub_labirint[3][0]) * varfuri_jos_cub_labirint[1][2],
                varfuri_jos, varfuri_sus, varfuri_jos_cub_labirint, varfuri_sus_cub_labirint, 2);
            if (depasire == glm::vec3(0))
                return depasire;
            if (abs(depasire[0]) > abs(depasire_labirint[0]))
                depasire_labirint[0] = depasire[0];
            if (abs(depasire[1]) > abs(depasire_labirint[1]))
                depasire_labirint[1] = depasire[1];
            if (abs(depasire[2]) > abs(depasire_labirint[2]))
                depasire_labirint[2] = depasire[2];
                   

            depasire = CheckFootMinMax(varfuri_sus_cub_labirint[1][1] - varfuri_jos_cub_labirint[1][1], varfuri_jos_cub_labirint[1][0]
                - varfuri_sus_cub_labirint[1][0], -(varfuri_sus_cub_labirint[1][1] - varfuri_jos_cub_labirint[1][1]) * varfuri_jos_cub_labirint[1][0]
                - (varfuri_jos_cub_labirint[1][0] - varfuri_sus_cub_labirint[1][0]) * varfuri_jos_cub_labirint[1][1],
                varfuri_jos, varfuri_sus, varfuri_jos_cub_labirint, varfuri_sus_cub_labirint, 1);
            if (depasire == glm::vec3(0))
                return depasire;
            if (abs(depasire[0]) > abs(depasire_labirint[0]))
                depasire_labirint[0] = depasire[0];
            if (abs(depasire[1]) > abs(depasire_labirint[1]))
                depasire_labirint[1] = depasire[1];
            if (abs(depasire[2]) > abs(depasire_labirint[2]))
                depasire_labirint[2] = depasire[2];

            return depasire_labirint;

            
            

        }
        glm::vec3 coliziune_jucator_labirint(std::vector<glm::vec3> labirint, float inaltime_labirint) {
            while (labirint.size()) {
                glm::vec3 cub = labirint.back();
                labirint.pop_back();
                glm::vec3 depasire_labirint = glm::vec3(0);
                if (abs(cub[0] - this->componente_jucator[0].modelMatrix[3][0]) < 3 && abs(cub[2] - this->componente_jucator[0].modelMatrix[3][2]) < 3) {
                    for (int i = 0; i < 6;i++) {
                        glm::vec3 depasire = glm::vec3(0);
                        depasire = coliziune_cub_cub(cub, inaltime_labirint, i);
                        if (abs(depasire[0]) > abs(depasire_labirint[0]))
                            depasire_labirint[0] = depasire[0];
                        if (abs(depasire[1]) > abs(depasire_labirint[1]))
                            depasire_labirint[1] = depasire[1];
                        if (abs(depasire[2]) > abs(depasire_labirint[2]))
                            depasire_labirint[2] = depasire[2];

                    }
                }
                if (depasire_labirint[0] != 0 || depasire_labirint[2] != 0)
                    return depasire_labirint;
            }
            return glm::vec3(0);
            
            }
        
    public:
        struct body
        {
            float centruX_initial;
            float centruY_initial;
            float centruZ_initial;
            float centruX_actual;
            float centruY_actual;
            float centruZ_actual;
            float scaleX;
            float scaleY;
            float scaleZ;
            glm::vec3 culoare;
            glm::mat4 modelMatrix;
        };




    public:
        std::vector<body> componente_jucator;
        float angle;
        float translate_x;
        float translate_z;
        
       

    };
}   // namespace implemented
