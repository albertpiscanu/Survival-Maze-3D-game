#pragma once


#include "utils/glm_utils.h"
#include "utils/math_utils.h"
#include <vector>
#include <iostream>
using namespace std;





namespace implemented
{
    class maze
    {
    public:
       maze()
        {
            
        }


        ~maze()
        { }

        
        int Random(int a, int b)
                {
                    int random = ((int)rand()) / (int)RAND_MAX;
                    int diff = b - a;
                    int r = random * diff;
                    return a + r;
                }
       
        std::vector<glm::vec2> getUnvisitedNeighbors(int** visited,glm::vec2 current_cell, int height, int width) {
            std::vector<glm::vec2> neighbors;
            int x = current_cell[0];
            int y = current_cell[1];
            if (x - 1 >= 0 && visited[x - 1][y] != 1)
                neighbors.push_back(glm::vec2(x - 1, y));
            if (x + 1 < height && visited[x + 1][y] != 1)
                neighbors.push_back(glm::vec2(x + 1, y));
            if (y - 1 >= 0 && visited[x][y - 1] != 1)
                neighbors.push_back(glm::vec2(x, y-1));
            if (y + 1 < width && visited[x][y + 1] != 1)
                neighbors.push_back(glm::vec2(x, y + 1));
            return neighbors;
        }

        std::vector<glm::vec2> generateMaze(int height, int width) {
            int** visited = new int* [height];
            for (int i = 0; i < height; ++i)
                visited[i] = new int[width];
            for (int i = 0; i < height; ++i)
                for (int j = 0; j < width; ++j) {
                   
                    visited[i][j] = 0;
                }
           
            glm::vec2 current_cell = glm::vec2(2, 0);
            std::vector<glm::vec2> used;
            std::vector<glm::vec2> walls;
            int visited_cells = 1;
            visited[2][0] = 1;
            while (visited_cells < width * height) {
                std::vector<glm::vec2> neighbors = getUnvisitedNeighbors(visited, current_cell, height, width);
                int n = neighbors.size() - 1;
                if (n > -1) {
                    glm::vec2 randomNeighbor = neighbors[rand() % (n + 1) ];
                    used.push_back(current_cell);
                    int x = randomNeighbor[0];
                    int y = randomNeighbor[1];
                    
                    walls.push_back(current_cell);
                    walls.push_back(randomNeighbor);
                    current_cell = randomNeighbor;
                    visited[x][y] = 1;
                    visited_cells++;
                }
                
                else if(used.empty()){
                    current_cell = used.back();
                    used.pop_back();


                }
                else {
                    for (int i = 0; i < height; ++i)
                        for (int j = 0; j < width; ++j)
                            if (visited[i][j] == 0) {
                                current_cell = glm::vec2(i, j);
                                visited[i][j] = 1;
                                visited_cells++;
                                i = height;
                                break;
                            }
                
                }
            }
            return walls;

        }
        

   

    public:
        
        

       


    };
}   // namespace implemented
