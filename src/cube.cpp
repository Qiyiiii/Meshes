#include "cube.h"

void cube(
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  ////////////////////////////////////////////////////////////////////////////

  ////Hint:
  V.resize(8,3);
  F.resize(6,4);
  UV.resize(14,2);
  UF.resize(6,4);
  NV.resize(6,3);
  NF.resize(6,4);

  //V
  //x: 0 to 1 y:0 to 1 z: 0 to 1
  V << 0, 0, 1,
      1,0,1,
      1,1,1,
      0,1,1,
      0,0,0,
      1,0,0,
      1,1,0,
      0,1,0;//z axis faces upward, y axis faces us

  //Faces
  F <<  4, 7,6,5, //bottom
        3, 2, 6, 7, //front
        0, 3, 7, 4, //left
        2,1,5,6, //right
        1,2,3,0, //top
        1,0,4,5; //back
  
  //texture map
  // UV << 1,3,
  // 1,4,
  // 2,4,
  // 2,3,
  // 1,1,
  // 2,1,
  // 2,0,
  // 1,0,
  // 0,1,
  // 0,2,
  // 3,2,

  

  //adapted from tut recording
  UV << 0.25,0,
        0.5,0,
        0,0.25,
        0.25,0.25,
        0.5,0.25,
        0.75,0.25,
        1,0.25,
        0,0.5,
        0.25,0.5,
        0.5,0.5,
        0.75,0.5,
        1,0.5,
        0.25,0.75,
        0.5,0.75;





  //Normal vec
  NV << 1,  0, 0,
        -1, 0, 0,
        0,  1,  0,
        0, -1,  0,
        0,  0,  1,
        0,  0, -1;
  
  //map  vector to uv
  UF << 3,4,1,0,
        9,10,5,4,
        8,9,4,3,
        10,11,6,5,
        12,13,9,8,
        7,8,3,2;

  //map face to normal
  NF << 5,5,5,5, //(0,0,-1) bottom
        2,2,2,2, //(0,1,0) front
        1,1,1,1, //(-1,0,0) left
        0,0,0,0, //(1,0,0) right
        4,4,4,4, //(0,0,1) top
        3,3,3,3; //(0,-1,0) back










}
