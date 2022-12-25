#include "per_vertex_normals.h"
#include "triangle_area_normal.h"

void per_vertex_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(V.rows(),3);
  ////////////////////////////////////////////////////////////////////////////
  // For each vertex
  // we calculate average of each face 
  for (int i = 0; i < V.rows(); i++) {
    int count = 0;
    for (int j = 0; j < F.rows(); j++) {
       
      if (V.row(i) == V.row(F(j, 0)) || V.row(i) == V.row(F(j, 1))  || V.row(i) == V.row(F(j, 2)) ){ 
        //check if the triangle mesh contains the vertex, that is vertex need to be in the mesh
      N.row(i) += triangle_area_normal(V.row(F(j, 0)), V.row(F(j, 1)), V.row(F(j, 2)));
      //compute neighbouring normals
      count++;
     }}
    N.row(i) /= count; //take the average, since mesh has equal area, so no weight
     }



  ////////////////////////////////////////////////////////////////////////////
}
