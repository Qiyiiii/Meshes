#include "vertex_triangle_adjacency.h"

void vertex_triangle_adjacency(
  const Eigen::MatrixXi & F,
  const int num_vertices,
  std::vector<std::vector<int> > & VF)
{
  VF.resize(num_vertices);
  ////////////////////////////////////////////////////////////////////////////
  for (int i = 0; i < num_vertices; ++i) {
      for (int j = 0; j < F.rows(); ++j) {
        if((i == F(j, 0))||(i == F(j, 1))||(i == F(j,2))){
          //check if the triangle mesh contains the vertex, that is vertex need to be in the mesh, like what we did in per vertex normal
          //so that we can find ALL triangles that contains the vertex
          VF[i].push_back(j); //if vertex is included, record the trianfle mesh
        }
      }}
  ////////////////////////////////////////////////////////////////////////////
}

