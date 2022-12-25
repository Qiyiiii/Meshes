#include "per_corner_normals.h"
#include "triangle_area_normal.h"
// Hint:
#include "vertex_triangle_adjacency.h"
#include <iostream>

void per_corner_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const double corner_threshold,
  Eigen::MatrixXd & N)
{
  N = Eigen::MatrixXd::Zero(F.rows()*3,3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  std::vector< std::vector<int> > VF;
  vertex_triangle_adjacency(F, V.rows(), VF);
  
  for (int i=0; i<F.rows(); i++) {
    Eigen::RowVector3d r = triangle_area_normal(V.row(F(i,0)), V.row(F(i,1)), V.row(F(i,2))); //face norm
    for (int j=0; j<3; j++) { //loop each vertex of the triangle mesh

      for (int k : VF[F(i, j)]) {//loop through adjacent vertex
        Eigen::RowVector3d norm2 = triangle_area_normal(V.row(F(k, 0)), V.row(F(k, 1)), V.row(F(k, 2)));
        //normal vector of adjacent triangle mesh
        if ((r.normalized().dot(norm2.normalized()) ) > (cos(corner_threshold *(M_PI/180)))){//changed from degree to radiant
        //if that neighbouring face it larger than threshold, then add to its corresponding vertex with this face value
          N.row(i*3+j) += norm2; //map to its corresponding vertex in V
        }
        
        }
      }

    }
  ////////////////////////////////////////////////////////////////////////////
}
