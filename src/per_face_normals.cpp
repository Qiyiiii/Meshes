#include "per_face_normals.h"
#include "triangle_area_normal.h"

void per_face_normals(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  Eigen::MatrixXd & N)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code:
  N = Eigen::MatrixXd::Zero(F.rows(),3);
  //get the norm of the face by getting the area of triangle mesh
  for (int i = 0; i < F.rows(); i++) {
    N.row(i) = triangle_area_normal(V.row(F(i,0)), V.row(F(i,1)), V.row(F(i,2)));
    }
  ////////////////////////////////////////////////////////////////////////////
}
