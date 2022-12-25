#include "triangle_area_normal.h"
#include <Eigen/Geometry>

Eigen::RowVector3d triangle_area_normal(
  const Eigen::RowVector3d & a, 
  const Eigen::RowVector3d & b, 
  const Eigen::RowVector3d & c)
{
  ////////////////////////////////////////////////////////////////////////////
  return (b-a).cross(c - a) / 2; // output vector should have length equal to the area of the triangle.
  //half area of parallelgram
  ////////////////////////////////////////////////////////////////////////////
  return Eigen::RowVector3d(0,0,0);
}
