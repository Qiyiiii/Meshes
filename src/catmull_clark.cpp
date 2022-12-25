#include "catmull_clark.h"
#include <unordered_map>
#include <utility>
#include <functional>
#include "vertex_triangle_adjacency.h"
void catmull_clark(
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const int num_iters,
  Eigen::MatrixXd & SV,
  Eigen::MatrixXi & SF)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  SV = V;
  SF = F;

  //https://web.cse.ohio-state.edu/~dey.8/course/784/note20.pdf and slides
  //Step 1: Set the face point for each facet to be the average of its vertices
  // std::vector< std::vector<int> > VF;
  // vertex_triangle_adjacency(F, V.rows(), VF);
  // std::unordered_map<int, std::vector<int> > new_face;
  std::unordered_map<int, Eigen::RowVector3d> new_face;
  std::vector<std::vector<Eigen::RowVector3d> > AV;  //adjacent vertex
  
  for (int i = 0; i < F.rows(); i++) {//for each face
      // since F has 4 columns
      Eigen::RowVector3d face(0, 0, 0);
      for (int j; j < 4; j++){
        face += V.row(F(i, 0));
      //add vertex to adjacent vertex
          AV[F(i,j)].push_back( V.row(F(i, 0)));
      
      }
      new_face[i] = face / 4;
  }
  

  //Step 2: Add edge points – average of two neighbouring face points and edge end points
  std::vector< std::vector<int> > VF;
  vertex_triangle_adjacency(F, V.rows(), VF);
  std::vector< std::vector<Eigen::RowVector3d> > edges;
  for (int i = 0; i < F.rows(); i++) {//for each face
      // since F has 4 columns
      //for each 2 vertex, we will compute it average with new face point
      Eigen::RowVector3d e1 = (V.row(F(i, 0)) + V.row(F(i,1)) + new_face[i] + new_face[i])/4;
      Eigen::RowVector3d e2 = (V.row(F(i, 0)) + V.row(F(i,3)) + new_face[i] + new_face[i])/4;
      Eigen::RowVector3d e3 = (V.row(F(i, 1)) + V.row(F(i,2)) + new_face[i] + new_face[i])/4;
      Eigen::RowVector3d e4 = (V.row(F(i, 2)) + V.row(F(i,3)) + new_face[i] + new_face[i])/4;
      edges[i].push_back(e1);
      edges[i].push_back(e2);
      edges[i].push_back(e3);
      edges[i].push_back(e4);}
  //Step 3: Add edges between face points and edge points

  

  ////////////////////////////////////////////////////////////////////////////
}
