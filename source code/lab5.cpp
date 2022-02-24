#include "lab_m1/lab5/lab5.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Lab5::Lab5()
{
}


Lab5::~Lab5()
{
}
float RandomFloat(float a, float b)
{
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}


void Lab5::Init()
{
    renderCameraTarget = false;
    camera = new implemented::Camera();
    camera_copie = new implemented::Camera();
    camera->Set(glm::vec3(0, 1.5, -3), glm::vec3(0, 1, 0), glm::vec3(0, 1, 0));
    camera->distanceToTarget = distanceToTarget_third_person;

    {
        Mesh* mesh = new Mesh("box");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("lego");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "lego.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("sphere");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "sphere.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("sun");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "vegetation"), "sun.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("pom");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "pom.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("casa");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "casa.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("casa7");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "casa7.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("casa9");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "casa9.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("casa11");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "casa11.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("casa13");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "casa13.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("pom1");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "pom1.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("pom2");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "pom2.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("pom5");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "pom5.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("pom6");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "pom6.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("pasare1");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "pasare1.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("pasare2");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "pasare2.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("pasare3");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "pasare3.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("pasare5");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "pasare5.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("trofeu3");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "trofeu3.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("elefant");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "elefant.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("girafa");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "girafa.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("dragon");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "dragon.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }

    {
        Mesh* mesh = new Mesh("avion");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "avion.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("nor");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "nor.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("saturn");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "characters"), "saturn.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    {
        Mesh* mesh = new Mesh("grass_2");
        mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "vegetation"), "grass_2.obj");
        meshes[mesh->GetMeshID()] = mesh;
    }
    
        projectionMatrix = glm::perspective(RADIANS(fov), window->props.aspectRatio, 0.01f, 200.0f);
        {
            Shader* shader = new Shader("LabShader");
            shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "VertexShader.glsl"), GL_VERTEX_SHADER);
            shader->AddShader(PATH_JOIN(window->props.selfDir, SOURCE_PATH::M1, "lab5", "shaders", "FragmentShader.glsl"), GL_FRAGMENT_SHADER);
            shader->CreateAndLink();
            shaders[shader->GetName()] = shader;
        }
        {
            lightPosition = glm::vec3(20, 20, 20);
            materialShininess = 3000;
            materialKd = 5;
            materialKs = 3;
        }
        maze = new implemented::maze();
        lungime_labirint = 20;
        walls = maze->generateMaze(lungime_labirint, lungime_labirint);
        corp_jucator = new implemented::Jucator_3D();
        corp_jucator2 = new implemented::Jucator_3D();
        lista_inamici = new implemented::Lista_de_inamici_Veemon();
        lista_proiectile = new implemented::Lista_de_proiectile_3D();
        
        for (int i = 0; i < 30;i++)
            nori.push_back(glm::vec3(RandomFloat(-5, 100), RandomFloat(3, 30), RandomFloat(-5, 100)));
        for (int i = 0; i <= 30;i++)
            pomi.push_back(glm::mat4x3(glm::vec3(RandomFloat(80, 110), -1.8, RandomFloat(-5, 95)), glm::vec3(RandomFloat(80, 110), -1.8, RandomFloat(-5, 95)), glm::vec3(RandomFloat(80, 110), -1.8, RandomFloat(-5, 95)), glm::vec3(RandomFloat(80, 110), -1.8, RandomFloat(-5, 95))));
        for (int i = 0; i <= 30;i++)
            pasari.push_back(glm::mat4x3(glm::vec3(RandomFloat(0, 80), RandomFloat(2.2, 9), RandomFloat(0, 80)), glm::vec3(RandomFloat(0, 80), RandomFloat(2.2, 9), RandomFloat(0, 80)), glm::vec3(RandomFloat(0, 80), RandomFloat(2.2, 9), RandomFloat(0, 80)), glm::vec3(RandomFloat(0, 80), RandomFloat(2.2, 9), RandomFloat(0, 80))));
        std::vector<glm::vec2> walls_coppy = walls;
        for (int i = 0; i < lungime_labirint * 4;i++)
            for (int j = 0; j < lungime_labirint * 4;j++)
            {
                pozitii_cuburi[i][j] = 0;
                pozitii_actuale_inamici[i][j] = 0;
            }
        while (walls_coppy.size() != 0) {
            glm::vec2 Cel = walls_coppy.back();
            int x = Cel[0] * 4;
            int y = Cel[1] * 4;
            walls_coppy.pop_back();
            glm::vec2 Cel_dest = walls_coppy.back();
            walls_coppy.pop_back();
            if (Cel[0] == Cel_dest[0]) {
                if (Cel[1] < Cel_dest[1]) {
                    pozitii_cuburi[x][y] = 1;
                    pozitii_cuburi[x][y + 1] = 1;
                    pozitii_cuburi[x][y + 2] = 1;
                    pozitii_cuburi[x][y + 3] = 1;
                    pozitii_cuburi[x][y + 4] = 1;
                }
                else {
                    pozitii_cuburi[x][y] = 1;
                    pozitii_cuburi[x][y - 1] = 1;
                    pozitii_cuburi[x][y - 2] = 1;
                    pozitii_cuburi[x][y - 3] = 1;
                    pozitii_cuburi[x][y - 4] = 1;
                }
            }
            else {

                if (Cel[0] < Cel_dest[0]) {
                    pozitii_cuburi[x][y] = 1;
                    pozitii_cuburi[x + 1][y] = 1;
                    pozitii_cuburi[x + 2][y] = 1;
                    pozitii_cuburi[x + 3][y] = 1;
                    pozitii_cuburi[x + 4][y] = 1;
                }
                else {
                    pozitii_cuburi[x][y] = 1;
                    pozitii_cuburi[x - 1][y] = 1;
                    pozitii_cuburi[x - 2][y] = 1;
                    pozitii_cuburi[x - 3][y] = 1;
                    pozitii_cuburi[x - 4][y] = 1;
                }

            }

        }
        for (int i = 0; i < lungime_labirint * 4 - 3;i++)
            for (int j = 0; j < lungime_labirint * 4 - 3;j++)
                if (pozitii_cuburi[i][j] + pozitii_cuburi[i][j + 1] + pozitii_cuburi[i][j + 2] + pozitii_cuburi[i + 1][j]
                    + pozitii_cuburi[i + 1][j + 2] + pozitii_cuburi[i + 2][j] + pozitii_cuburi[i + 2][j + 1] + pozitii_cuburi[i + 2][j + 2] == 0)
                {   
                    lista_inamici->Add(i, j);
                    pozitii_cuburi[i][j] = 2;
                    pozitii_cuburi[i][j + 1] = 3;
                    pozitii_cuburi[i][j + 2] = 3;
                    pozitii_cuburi[i + 1][j] = 3;
                    pozitii_cuburi[i + 1][j + 2] = 3;
                    pozitii_cuburi[i + 2][j] = 3;
                    pozitii_cuburi[i + 2][j + 1] = 3;
                    pozitii_cuburi[i + 2][j + 2] = 3;
                    j += 4;

                }
        
        for (int i = 0; i < lungime_labirint * 4;i++)
        {
            for (int j = 0; j < lungime_labirint * 4;j++)
            {
                //cout << pozitii_cuburi[i][j] ;
                if (pozitii_cuburi[i][j] == 1)
                {
                    glm::mat4 modelMatrix = glm::mat4(1);
                    modelMatrix = glm::scale(modelMatrix, glm::vec3(1, labirint_inaltime, 1));
                    modelMatrix = glm::translate(modelMatrix, glm::vec3(i + 0.5, 0.5, j + 0.5));
                    model_matrix_cuburi_labirint.push_back(modelMatrix);
                    cuburi_labirint.push_back(glm::vec3(modelMatrix[3][0], modelMatrix[3][1], modelMatrix[3][2]));
                }
                if (i == 0 && j > 0 && j < lungime_labirint * 4 - 1 && pozitii_cuburi[i][j] !=1 && pozitii_cuburi[i][j-1] != 1 && pozitii_cuburi[i][j+1] != 1)
                    trofee.push_back(glm::vec3(-2, 0, j));
                if (j == 0 && i > 0 && i < lungime_labirint * 4 - 1 && pozitii_cuburi[i][j] != 1 && pozitii_cuburi[i-1][j] != 1 && pozitii_cuburi[i+1][j] != 1)
                    trofee.push_back(glm::vec3(i, 0, -2));
                if (i == lungime_labirint * 4 - 4 && j > 0 && j < lungime_labirint * 4 - 1 && pozitii_cuburi[i][j] != 1 && pozitii_cuburi[i][j - 1] != 1 && pozitii_cuburi[i][j + 1] != 1)
                    trofee.push_back(glm::vec3(i + 2, 0, j));
                if (j == lungime_labirint * 4 - 4 && i > 0 && i < lungime_labirint * 4 - 1 && pozitii_cuburi[i][j] != 1 && pozitii_cuburi[i - 1][j] != 1 && pozitii_cuburi[i + 1][j] != 1)
                    trofee.push_back(glm::vec3(i, 0, j + 2));

            }
            //cout << endl;
        }
        for (int i = lungime_labirint * 2 - 2; i < lungime_labirint * 2 + 2;i++)
            for (int j = lungime_labirint * 2 - 2; j < lungime_labirint * 2 + 2;j++)
                if ((pozitii_cuburi[i][j] == 0 || pozitii_cuburi[i][j] == 3)&& pozitii_cuburi[i+1][j]!=1 && pozitii_cuburi[i - 1][j] != 1 && pozitii_cuburi[i][j-1] != 1 && pozitii_cuburi[i][j+1] != 1)
                {
                    camera->Set(glm::vec3(i, inaltime_camera, j - 3), glm::vec3(i, inaltime_camera, j), glm::vec3(0, inaltime_camera, 0));
                    break;
                }
       
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, lightPosition);
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1f));
            RenderMesh(meshes["sphere"], shaders["Simple"], modelMatrix);
        }
}


void Lab5::FrameStart()
{
    if (health <= 0 || time <= 0)
    {
        cout << "GAME OVER!";
        exit(0);
    }

    // Clears the color buffer (using the previously set color) and depth buffer
    glEnable(GL_SCISSOR_TEST);
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glm::ivec2 resolution = window->GetResolution();

    glScissor(resolution.x * 0.950, 0, resolution.x * 0.975, resolution.y);
    glEnable(GL_SCISSOR_TEST);
    glClearColor(0.078, 1, 0.125, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glScissor(resolution.x * 0.950, 0, resolution.x * 0.975, resolution.y*time/180);
    glEnable(GL_SCISSOR_TEST);
    glClearColor(0.980, 1, 0.121, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glScissor(resolution.x * 0.975, 0, resolution.x, resolution.y);
    glEnable(GL_SCISSOR_TEST);
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glScissor(resolution.x * 0.975, 0, resolution.x, resolution.y*health/4);
    glEnable(GL_SCISSOR_TEST);
    glClearColor(1, 0.196, 0.121, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glScissor(0, 0, window->GetResolution().x * 0.950, window->GetResolution().y);
   

   
}


void Lab5::Update(float deltaTimeSeconds)
{

    time -= deltaTimeSeconds;
    cooldown += deltaTimeSeconds;
    glm::mat4 modelMatrix = glm::mat4(1);
    for (int i = -20; i <= 120;i += 4)
        for (int j = -20; j <= 120;j += 4)
        {
            modelMatrix = translate(glm::mat4(1), glm::vec3(i, 0, j))
                * glm::scale(glm::mat4(1), glm::vec3(0.01, 0.01, 0.01));
            RenderSimpleMesh(meshes["grass_2"], shaders["LabShader"], modelMatrix, glm::vec3(0, 1, 0), 0);
        }
    if (miscare == 1) {
        camera->position = camera->position * (T - t) / T + tranzitie_first_person * t / T;
        camera->distanceToTarget = camera->distanceToTarget * (T - t) / T + distanceToTarget_first_person * t / T;
        t += deltaTimeSeconds;
        if (t >= T)
        {
            miscare = 2;
            t = 0;
        }

    }
    if (miscare == 3) {
        //camera->right = glm::normalize(glm::cross(camera->forward, camera->up));
        camera->position = camera->position * (T - t) / T + tranzitie_third_person * t / T;
        camera->distanceToTarget = camera->distanceToTarget * (T - t) / T + distanceToTarget_third_person * t / T;
        camera->forward = camera->forward * (T - t) / T + glm::vec3(sin(angle), 0, cos(angle)) * t / T;
        camera->right[2] = camera->forward[0];
        camera->right[1] = 0;
        camera->right[0] = -camera->forward[2];
        camera->up = camera->up * (T - t) / T + glm::vec3(0, 1, 0) * t / T;
        t += deltaTimeSeconds;
        if (t >= T || sqrt(pow(camera->position[0] - tranzitie_third_person[0], 2.0) + pow(camera->position[1] - tranzitie_third_person[1], 2.0)
            + pow(camera->position[2] - tranzitie_third_person[2], 2.0)) < 0.1)
        {
            miscare = 0;
            t = 0;
        }

    }
    std::vector<glm::mat4> model_matrix_cuburi_labirint_copy;
    model_matrix_cuburi_labirint_copy = model_matrix_cuburi_labirint;
    while (model_matrix_cuburi_labirint_copy.size()) {
        RenderSimpleMesh(meshes["box"], shaders["LabShader"], model_matrix_cuburi_labirint_copy.back(), glm::vec3(0.5f, 0.35f, 0.05f), 0);
        model_matrix_cuburi_labirint_copy.pop_back();
    }
    cuburi_labirint_global = cuburi_labirint;
    modelMatrix = glm::mat4(1);

    lista_inamici->Calculeaza_pozitie_actuala(deltaTimeSeconds);

    {
        corp_jucator->Set(camera->GetTargetPosition()[0], camera->GetTargetPosition()[2], angle, brat_activat);
        glm::vec3 coliziune_trofeu = corp_jucator->coliziune_jucator_labirint(trofee, 3);
        if (coliziune_trofeu[0] != 0 || coliziune_trofeu[2] != 0)
            {
            cout << "AI CASTIGAT!" << endl;
            exit(0);
            }
        for (int i = 0; i < 6; i++)
            RenderSimpleMesh(meshes["box"], shaders["LabShader"], corp_jucator->componente_jucator[i].modelMatrix, corp_jucator->componente_jucator[i].culoare, 0);

        if (lanseaza_proiectil == 1)
        {
            lista_proiectile->Add(corp_jucator->componente_jucator[6].modelMatrix,
                glm::vec3(corp_jucator->componente_jucator[6].modelMatrix[3][0], corp_jucator->componente_jucator[6].modelMatrix[3][1],
                    corp_jucator->componente_jucator[6].modelMatrix[3][2]), camera->GetTargetPosition_proiectile(2.5));
            lanseaza_proiectil = 0;
        }
        lista_proiectile->Calculeaza_pozitie_proiectile(deltaTimeSeconds);
        std::vector<glm::vec3> cuburi_labirint_copie = cuburi_labirint;
        lista_proiectile->coliziune_proiectil_labirint(cuburi_labirint_copie, labirint_inaltime);
        for (int i = 0; i < lista_proiectile->numar_proiectile; i++)
            if (lista_proiectile->proiectile[i].activ == 1)
            {
                int coliziune_proiectil_inamic = 0;
                coliziune_proiectil_inamic = lista_inamici->coliziune_inamici_proiectil(lista_proiectile->proiectile[i].modelMatrix[3][0], lista_proiectile->proiectile[i].modelMatrix[3][1], lista_proiectile->proiectile[i].modelMatrix[3][2]);
                if (coliziune_proiectil_inamic == 1) lista_proiectile->proiectile[i].activ = 0;
                if (lista_proiectile->proiectile[i].activ == 1)
                    RenderSimpleMesh(meshes["sphere"], shaders["LabShader"], lista_proiectile->proiectile[i].modelMatrix, corp_jucator->componente_jucator[6].culoare, 0);
            }


    }


    health = lista_inamici->coliziune_inamic_jucator(corp_jucator->componente_jucator[2].modelMatrix[3][0], corp_jucator->componente_jucator[2].modelMatrix[3][2], health);
    for (int i = 0; i < lista_inamici->numar_inamici; i++)
        if (lista_inamici->inamici[i].activ == 1 || lista_inamici->inamici[i].efect_shader)
            RenderSimpleMesh(meshes["lego"], shaders["LabShader"], lista_inamici->inamici[i].modelMatrix, lista_inamici->inamici[i].culoare, lista_inamici->inamici[i].efect_shader);
    Deseneaza_decor();

       
}

void Lab5::Deseneaza_decor() {
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, lightPosition);
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.3));
        RenderSimpleMesh(meshes["sun"], shaders["LabShader"], modelMatrix, glm::vec3(1, 1, 0), 0);

    }
    {
        for (int i = 0; i < nori.size(); i++)
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, nori[i]);
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.01));
            RenderSimpleMesh(meshes["nor"], shaders["LabShader"], modelMatrix, glm::vec3(1), 0);
        }
    }
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(55, 20, 10));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.04));
        modelMatrix = glm::rotate(modelMatrix, RADIANS(300), glm::vec3(1, 0, 0));
        RenderSimpleMesh(meshes["saturn"], shaders["LabShader"], modelMatrix, glm::vec3(0.917, 0.839, 0.721), 0);

    }
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(45, 10, 80));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.04));
        modelMatrix = glm::rotate(modelMatrix, RADIANS(270), glm::vec3(0, 1, 0));
        RenderSimpleMesh(meshes["avion"], shaders["LabShader"], modelMatrix, glm::vec3(1, 0.078, 0.572), 0);

    }
    //blocuri

    {
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-3, 0, 35));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.2));
            RenderSimpleMesh(meshes["casa"], shaders["LabShader"], modelMatrix, glm::vec3(0.113, 0.215, 0.247), 0);

        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-3, 0, -5));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.42));
            RenderSimpleMesh(meshes["casa7"], shaders["LabShader"], modelMatrix, glm::vec3(0.113, 0.215, 0.247), 0);

        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-3, 0, 5));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.29));
            RenderSimpleMesh(meshes["casa7"], shaders["LabShader"], modelMatrix, glm::vec3(0.113, 0.215, 0.247), 0);

        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-3, 0, 15));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.3));
            RenderSimpleMesh(meshes["casa"], shaders["LabShader"], modelMatrix, glm::vec3(0.113, 0.215, 0.247), 0);

        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-3, 0, 25));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.15));
            RenderSimpleMesh(meshes["casa"], shaders["LabShader"], modelMatrix, glm::vec3(0.113, 0.215, 0.247), 0);

        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-3, 0, 45));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.35));
            RenderSimpleMesh(meshes["casa"], shaders["LabShader"], modelMatrix, glm::vec3(0.113, 0.215, 0.247), 0);

        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-8, 0, 27));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5));
            RenderSimpleMesh(meshes["casa"], shaders["LabShader"], modelMatrix, glm::vec3(0.113, 0.215, 0.247), 0);

        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-8, 0, 55));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.33));
            RenderSimpleMesh(meshes["casa7"], shaders["LabShader"], modelMatrix, glm::vec3(0.113, 0.215, 0.247), 0);

        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-3, 0, 45));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.25));
            RenderSimpleMesh(meshes["casa7"], shaders["LabShader"], modelMatrix, glm::vec3(0.113, 0.215, 0.247), 0);

        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-6, 0, 65));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5));
            RenderSimpleMesh(meshes["casa7"], shaders["LabShader"], modelMatrix, glm::vec3(0.113, 0.215, 0.247), 0);

        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-3, 0, 75));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.35));
            RenderSimpleMesh(meshes["casa7"], shaders["LabShader"], modelMatrix, glm::vec3(0.113, 0.215, 0.247), 0);

        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-3, 0, 87));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.22));
            RenderSimpleMesh(meshes["casa7"], shaders["LabShader"], modelMatrix, glm::vec3(0.113, 0.215, 0.247), 0);

        }


        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(-14, 0, 7));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.6));
            RenderSimpleMesh(meshes["casa9"], shaders["LabShader"], modelMatrix, glm::vec3(0.113, 0.215, 0.247), 0);

        }
    }

    //case
    
    {
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(55, 0, -9));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(4));
            //modelMatrix = glm::rotate(modelMatrix, RADIANS(0), glm::vec3(0, 1, 0));
            RenderSimpleMesh(meshes["casa11"], shaders["LabShader"], modelMatrix, glm::vec3(0.113, 0.215, 0.247), 0);

        }

        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(35, 0, -9));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.4));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(180), glm::vec3(0, 1, 0));
            RenderSimpleMesh(meshes["casa13"], shaders["LabShader"], modelMatrix, glm::vec3(0.113, 0.215, 0.247), 0);

        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(25, 0, -9));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(1.5));
            RenderSimpleMesh(meshes["pom2"], shaders["LabShader"], modelMatrix, glm::vec3(0.35, 0.16, 0.14), 0);
        }
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(45, 0, -9));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(1.5));
            RenderSimpleMesh(meshes["pom2"], shaders["LabShader"], modelMatrix, glm::vec3(0.35, 0.16, 0.14), 0);
        }
    }
    //pomi

    {
        for (int i = 0;i <= 30;i++)
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(pomi[i][0][0], -1.8, pomi[i][0][2]));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 2.5, 1));
            RenderSimpleMesh(meshes["pom1"], shaders["LabShader"], modelMatrix, glm::vec3(0.35, 0.16, 0.14), 0);

            modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(pomi[i][1][0], 0, pomi[i][1][2]));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(1.5));
            RenderSimpleMesh(meshes["pom2"], shaders["LabShader"], modelMatrix, glm::vec3(0.35, 0.16, 0.14), 0);

            modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(pomi[i][2][0], 0, pomi[i][2][2]));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(4));
            RenderSimpleMesh(meshes["pom5"], shaders["LabShader"], modelMatrix, glm::vec3(0.35, 0.16, 0.14), 0);

            modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(pomi[i][3][0], 0, pomi[i][3][2]));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(4));
            RenderSimpleMesh(meshes["pom6"], shaders["LabShader"], modelMatrix, glm::vec3(0.35, 0.16, 0.14), 0);

        }

    }


    //pasari
    for (int i = 0;i <= 30;i++)
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(pasari[i][0][0], pasari[i][0][1], pasari[i][0][2]));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(1.5));
        RenderSimpleMesh(meshes["pasare1"], shaders["LabShader"], modelMatrix, glm::vec3(0), 0);
        modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(pasari[i][1][0], pasari[i][1][1], pasari[i][1][2]));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(1.5));
        RenderSimpleMesh(meshes["pasare2"], shaders["LabShader"], modelMatrix, glm::vec3(0), 0);
        modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(pasari[i][2][0], pasari[i][2][1], pasari[i][2][2]));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(1.5));
        RenderSimpleMesh(meshes["pasare3"], shaders["LabShader"], modelMatrix, glm::vec3(0), 0);
        modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(pasari[i][3][0], pasari[i][3][1], pasari[i][3][2]));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(1.5));
        RenderSimpleMesh(meshes["pasare5"], shaders["LabShader"], modelMatrix, glm::vec3(0), 0);

    }
    //trofee
    for (int i = 0;i < trofee.size();i++)
    {
        if (trofee[i][2] < 0 || trofee[i][2] >= 78)
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(trofee[i][0], 0, trofee[i][2]));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(270), glm::vec3(1, 0, 0));
            RenderSimpleMesh(meshes["trofeu3"], shaders["LabShader"], modelMatrix, glm::vec3(0.8, 0.498039, 0.196078), 0);

        }
        else if (trofee[i][0] < 0 || trofee[i][0] >= 78)
        {
            glm::mat4 modelMatrix = glm::mat4(1);
            modelMatrix = glm::translate(modelMatrix, glm::vec3(trofee[i][0], 0, trofee[i][2]));
            modelMatrix = glm::scale(modelMatrix, glm::vec3(0.5));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(90), glm::vec3(0, 1, 0));
            modelMatrix = glm::rotate(modelMatrix, RADIANS(270), glm::vec3(1, 0, 0));
            RenderSimpleMesh(meshes["trofeu3"], shaders["LabShader"], modelMatrix, glm::vec3(0.8, 0.498039, 0.196078), 0);

        }
    }



    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(-30, 1, 0));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 100, 200));
        RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, glm::vec3(0.196078, 0.6, 0.8), 0);

    }
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(-10, 1, -10));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(300, 100, 1));
        RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, glm::vec3(0.196078, 0.6, 0.8), 0);

    }
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(120, 1, -10));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(1, 100, 200));
        RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, glm::vec3(0.196078, 0.6, 0.8), 0);

    }
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(120, 1, 90));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(300, 100, 1));
        RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, glm::vec3(0.196078, 0.6, 0.8), 0);

    }
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(-10, 50, 0));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(300, 1, 200));
        RenderSimpleMesh(meshes["box"], shaders["LabShader"], modelMatrix, glm::vec3(0.196078, 0.6, 0.8), 0);

    }
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(35, 0, 80));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.033));
        modelMatrix = glm::rotate(modelMatrix, RADIANS(90), glm::vec3(0, 0, 1));
        modelMatrix = glm::rotate(modelMatrix, RADIANS(90), glm::vec3(0, 1, 0));
        RenderSimpleMesh(meshes["elefant"], shaders["LabShader"], modelMatrix, glm::vec3(0.066, 0.215, 0.243), 0);

    }
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(60, 0, 80));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(1.5,1.8,1.5));
        modelMatrix = glm::rotate(modelMatrix, RADIANS(270), glm::vec3(0, 1, 0));
        RenderSimpleMesh(meshes["girafa"], shaders["LabShader"], modelMatrix, glm::vec3(0.788, 0.498, 0.305), 0);

    }
    {
        glm::mat4 modelMatrix = glm::mat4(1);
        modelMatrix = glm::translate(modelMatrix, glm::vec3(30, 15, -5));
        modelMatrix = glm::scale(modelMatrix, glm::vec3(0.8));
        modelMatrix = glm::rotate(modelMatrix, RADIANS(13), glm::vec3(0, 1, 0));
        modelMatrix = glm::rotate(modelMatrix, RADIANS(40), glm::vec3(1, 0, 0));
        RenderSimpleMesh(meshes["dragon"], shaders["LabShader"], modelMatrix, glm::vec3(0.015, 0.545, 0.376), 0);

    }


}

void Lab5::FrameEnd()
{
 
    //DrawCoordinateSystem(camera->GetViewMatrix(), projectionMatrix);

}
void Lab5::RenderSimpleMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix, const glm::vec3& color, const float &efect_shader)
{
    if (!mesh || !shader || !shader->GetProgramID())
        return;

    // Render an object using the specified shader and the specified position
    glUseProgram(shader->program);

    // Set shader uniforms for light & material properties
    // TODO(student): Set light position uniform
    GLint loc_light_position = glGetUniformLocation(shader->program, "light_position");
    glUniform3fv(loc_light_position, 1, glm::value_ptr(lightPosition));

    glm::vec3 eyePosition = GetSceneCamera()->m_transform->GetWorldPosition();
    // TODO(student): Set eye position (camera position) uniform
    GLint loc_eye_position = glGetUniformLocation(shader->program, "eye_position");
    glUniform3fv(loc_eye_position, 1, glm::value_ptr(eyePosition));

    // TODO(student): Set material property uniforms (shininess, kd, ks, object color)
    GLint material_shininess = glGetUniformLocation(shader->program, "material_shininess");
    glUniform1i(material_shininess, materialShininess);

    GLint material_kd = glGetUniformLocation(shader->program, "material_kd");
    glUniform1f(material_kd, materialKd);

    GLint material_ks = glGetUniformLocation(shader->program, "material_ks");
    glUniform1f(material_ks, materialKs);

    GLint object_color = glGetUniformLocation(shader->program, "object_color");
    glUniform3f(object_color, color.r, color.g, color.b);

    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));
    // Bind view matrix
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));

    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    int loc_time = glGetUniformLocation(shader->program, "time");
    
    if (mesh == meshes["lego"] && efect_shader > 0)
        glUniform1f(loc_time, (float)Engine::GetElapsedTime());
    else
        glUniform1f(loc_time, -1.0f);
    // Draw the object
    glBindVertexArray(mesh->GetBuffers()->m_VAO);
    glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_INT, 0);
}

void Lab5::RenderMesh(Mesh * mesh, Shader * shader, const glm::mat4 & modelMatrix)
{
    if (!mesh || !shader || !shader->program)
        return;

    // Render an object using the specified shader and the specified position
    shader->Use();
    glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
    glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
    glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

    mesh->Render();
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Lab5::OnInputUpdate(float deltaTime, int mods)
{
    // move the camera only if MOUSE_RIGHT button is pressed
    //if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    
    {
        float cameraSpeed = 2.0f;
        *camera_copie = *camera;
        if (window->KeyHold(GLFW_KEY_W)) {
            // TODO(student): Translate the camera forward
            camera_copie->MoveForward(cameraSpeed * deltaTime);     
        }

        if (window->KeyHold(GLFW_KEY_A)) {
            // TODO(student): Translate the camera to the left
            camera_copie->TranslateRight(-cameraSpeed * deltaTime);
        }

        if (window->KeyHold(GLFW_KEY_S)) {
            // TODO(student): Translate the camera backward
            camera_copie->MoveForward(-cameraSpeed * deltaTime);
        }

        if (window->KeyHold(GLFW_KEY_D)) {
            // TODO(student): Translate the camera to the right
            camera_copie->TranslateRight(cameraSpeed * deltaTime);
        }

        if (window->KeyHold(GLFW_KEY_Q)) {
            // TODO(student): Translate the camera downward
            camera_copie->TranslateUpward(-cameraSpeed * deltaTime);
        }

        if (window->KeyHold(GLFW_KEY_E)) {
            // TODO(student): Translate the camera upward
            camera_copie->TranslateUpward(cameraSpeed * deltaTime);
        }
        *corp_jucator2 = *corp_jucator;
        corp_jucator2->Set(camera_copie->GetTargetPosition()[0], camera_copie->GetTargetPosition()[2], angle, brat_activat);
        glm::vec3 coliziune = glm::vec3(0);
        std::vector<glm::vec3> cuburi_labirint_copie = cuburi_labirint;
        coliziune = corp_jucator2->coliziune_jucator_labirint(cuburi_labirint_copie, labirint_inaltime);
        if (coliziune[0] != 0 || coliziune[2] != 0) {
            *camera_copie = *camera;

        }
        else {
            *camera = *camera_copie;
        }

    }

    
    if (window->KeyHold(GLFW_KEY_LEFT_CONTROL)) {
        if (miscare == 0)
        {
            tranzitie_first_person = glm::vec3(camera->GetTargetPosition()[0], 1.5, camera->GetTargetPosition()[2]);
            miscare = 1;
            brat_activat = 1;
            first_person = 1;
            third_person = 0;
        }
        if (miscare == 2) {
            tranzitie_third_person = glm::vec3(camera->GetCameraPosition()[0],inaltime_camera, camera->GetCameraPosition()[2]);
            miscare = 3;
            first_person = 0;
            third_person = 1;
            brat_activat = 0;
        }
    }

    

}


void Lab5::OnKeyPress(int key, int mods)
{
    // Add key press event
    if (key == GLFW_KEY_T)
    {
        renderCameraTarget = !renderCameraTarget;
    }
    // TODO(student): Switch projections
    if (key == GLFW_KEY_O)
    {
        projectionMatrix = glm::ortho(left,-left,bottom,-bottom,near,-near);
    }
    if (key == GLFW_KEY_P)
    {
        projectionMatrix = glm::perspective(RADIANS(fov), window->props.aspectRatio, 0.01f, 200.0f);
    }
    if (key == GLFW_KEY_SPACE)
    {
        if (cooldown > 1 && brat_activat == 1) 
        {
            lanseaza_proiectil = 1;
            cooldown = 0;
        }
    }

}


void Lab5::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Lab5::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
    
    if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
    {
        *camera_copie = *camera;
        float angle_copie = angle;
        float sensivityOX = 0.001f;
        float sensivityOY = 0.001f;
        renderCameraTarget = true;
        if (first_person == 1) {
            // TODO(student): Rotate the camera in first-person mode around
            // OX and OY using `deltaX` and `deltaY`. Use the sensitivity
           // variables for setting up the rotation speed.
            camera_copie->RotateFirstPerson_OX(sensivityOX * deltaY);
            camera_copie->RotateFirstPerson_OY(sensivityOY * deltaX);
            angle_copie += sensivityOY * deltaX;
        }

        
        else {
            // TODO(student): Rotate the camera in third-person mode around
            // OX and OY using `deltaX` and `deltaY`. Use the sensitivity
            // variables for setting up the rotation speed.
            camera_copie->RotateThirdPerson_OY(sensivityOY * deltaX);
            angle_copie += sensivityOY * deltaX;

        }
            *corp_jucator2 = *corp_jucator;
            corp_jucator2->Set(camera_copie->GetTargetPosition()[0], camera_copie->GetTargetPosition()[2], angle, brat_activat);
            glm::vec3 coliziune = glm::vec3(0);
            std::vector<glm::vec3> cuburi_labirint_copie = cuburi_labirint;
            coliziune = corp_jucator2->coliziune_jucator_labirint(cuburi_labirint_copie, labirint_inaltime);
            if (coliziune[0] != 0 || coliziune[2] != 0) {
                *camera_copie = *camera;
                angle_copie = angle;
            }
            else {
                *camera = *camera_copie;
                angle = angle_copie;
            }
        }
        
    
}


void Lab5::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
}


void Lab5::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Lab5::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Lab5::OnWindowResize(int width, int height)
{
    glViewport(0, 0, width, height);
}
