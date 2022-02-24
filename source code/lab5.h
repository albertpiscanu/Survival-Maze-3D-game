#pragma once

#include "components/simple_scene.h"
#include "components/transform.h"
#include "lab_m1/lab5/lab_camera.h"
#include "lab_m1/lab5/jucator.h"
#include "lab_m1/lab5/maze.h"
#include "lab_m1/lab5/lista_de_inamici.h"
#include "lab_m1/lab5/lista_de_proiectile.h"


namespace m1
{
    class Lab5 : public gfxc::SimpleScene
    {
     public:
        Lab5();
        ~Lab5();

        void Init() override;

     private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;
        void Deseneaza_decor();
        void RenderMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix) override;
        void RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, const glm::vec3& color, const float &efect_shader);
        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

     protected:
        implemented::Camera *camera;
        implemented::Camera *camera_copie;
        implemented::maze* maze;
        implemented::Jucator_3D* corp_jucator;
        implemented::Jucator_3D* corp_jucator2;
        implemented::Lista_de_inamici_Veemon* lista_inamici;
        implemented::Lista_de_proiectile_3D* lista_proiectile;
        glm::mat4 projectionMatrix;
        bool renderCameraTarget = true;
        std::vector<glm::vec2> walls;
        // TODO(student): If you need any other class variables, define them here.
        glm::ivec2 res = window->GetResolution();
        int fov = 60;
        float left = -res[0] * 0.005f;
        float bottom = -res[1] * 0.005f;
        float near = -100;
        float t = 0, t_proiectil = 0, T = 1.5,miscare = 0, v= 0.01,ti = 0,tj=0,T_proiectil = 1.5;
        glm::vec3 position1 = glm::vec3(0, 2, 5);
        glm::vec3 forward1 = glm::vec3(0, 0, -1);
        glm::vec3 up1 = glm::vec3(0, 1, 0);
        glm::vec3 right1 = glm::vec3(1, 0, 0);
        float mouseAngle=0;
        glm::vec3 movement=glm::vec3(0);
        float angle = 0;
        std::vector<glm::vec3> cuburi_labirint;
        std::vector<glm::vec3> cuburi_labirint_global;
        std::vector<glm::mat4> model_matrix_cuburi_labirint;
        float pozitii_actuale_inamici[100][100];
        float pozitii_cuburi[100][100];
        glm::vec3 lightPosition;
        glm::vec3 lightDirection;
        unsigned int materialShininess;
        float materialKd;
        float materialKs;
        float angle_inamic = 0;
        int spotlight = 0;
        float cutoff_angle = RADIANS(20);
        float offseti = 0, offsetj = 0;
        int pozitie_i, pozitie_j;
        float pozitie_in_patrat_i, pozitie_in_patrat_j;
        int jucator_i, jucator_j;
        int proiectil_i, proiectil_j;
        int brat_activat = 0;
        int lanseaza_proiectil = 0;
        int proiectil_activ = 0;
        glm::vec3 tranzitie_first_person;
        glm::vec3 tranzitie_third_person;
        glm::vec3 pos_proiectil;
        glm::mat4 modelMatrix_proiectil;
        glm::vec3 target_proiectil;
        float third_person = 1;
        float first_person = 0;
        float lungime_labirint;
        float labirint_inaltime = 2;
        float inaltime_camera = 2.5;
        float distanceToTarget_first_person = -0.2;
        float distanceToTarget_third_person = 4;
        float time = 180;
        float health = 4;
        float cooldown = 0;
        std::vector<glm::vec3> nori;
        std::vector<glm::mat4x3> pomi;
        std::vector<glm::mat4x3> pasari;
        std::vector<glm::vec3> trofee;

    
    };
}   // namespace m1
