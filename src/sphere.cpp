#include "sphere.h"
#include <iostream>

void sphere(
  const int num_faces_u,
  const int num_faces_v,
  Eigen::MatrixXd & V,
  Eigen::MatrixXi & F,
  Eigen::MatrixXd & UV,
  Eigen::MatrixXi & UF,
  Eigen::MatrixXd & NV,
  Eigen::MatrixXi & NF)
{
  ////////////////////////////////////////////////////////////////////////////
  

  int facenum  = num_faces_u * num_faces_v;
  int vernum = (num_faces_u + 1) * num_faces_v + num_faces_u + 1;
  V.resize(vernum, 3);
  UV.resize(vernum, 2);
  NV.resize(vernum, 3);
  F.resize(facenum, 4);
  NF.resize(facenum, 4);
  UF.resize(facenum, 4); 
  int num = 0;
  //since there are ((num_faces_u + 1) * num_faces_v + num_faces_u + 1) vertex
  //determine shape
  for (int i = 0; i < num_faces_u + 1; i++){ //longitude
    for (int j = 0; j < num_faces_v + 1; j++){ //latitude
      // coordinate equation from tut 
      double theta = i* 2 * M_PI / num_faces_u;
      double phi = j*M_PI / num_faces_v;
      //equation acquired from https://en.wikipedia.org/wiki/Spherical_coordinate_system
      double x = sin(phi) * cos(theta);
      double y = sin(phi) * sin(theta);
      double z = cos(phi);
      
      V.row(num)  << x,y,z; //each loaction represent a vertex
      UV.row(num) <<(double) i / (num_faces_u + 1), (double) j / (num_faces_v + 1) ;//cut sphere into texture and x from 0 to 1 y from 0 to 1
      NV.row(num) << x,y,z;
      num++;
      }}


  num = 0;
  for (int i = 0; i < num_faces_u; i++){ //w
    for (int j = 0; j < num_faces_v; j++){ //h
      //i * (num_faces_v + 1) represent the postion in texture of (i,j)
      int v1 = i * (num_faces_v + 1) + j; //bottom left corner
      int v2 = v1 + 1;
      int v3 = (i+1) * (num_faces_v + 1) + j + 1; //upper left corner
      int v4 = v3 -1;

      F.row(num) << v1, v2, v3, v4;
      UF.row(num) << v1, v2, v3, v4;
      NF.row(num) << v1, v2, v3, v4;
      num++;
    }
  }

  ////////////////////////////////////////////////////////////////////////////
}
