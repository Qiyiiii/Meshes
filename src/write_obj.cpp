#include "write_obj.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_obj(
  const std::string & filename,
  const Eigen::MatrixXd & V,
  const Eigen::MatrixXi & F,
  const Eigen::MatrixXd & UV,
  const Eigen::MatrixXi & UF,
  const Eigen::MatrixXd & NV,
  const Eigen::MatrixXi & NF)
{
  assert((F.size() == 0 || F.cols() == 3 || F.cols() == 4) && "F must have 3 or 4 columns");
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  //equation adopted from tut recording
  std::ofstream data;

  //format: https://en.wikipedia.org/wiki/Wavefront_.obj_file
   for (int i = 0; i < V.rows(); i++){
      data << "v " << V.row(i)[0] << " " << V.row(i)[1] << " " << V.row(i)[2]<< "\n"; //List of geometric vertices
    }

  for (int i = 0; i < F.rows(); i++){
     // mesh face_index/texture_index/normal_index of face
      data << "f ";
      for (int j = 0; j < F.cols(); j++){
        data << (F.row(i)[j] + 1) << "/" << (UF.row(i)[j] + 1) << "/" << (NF.row(i)[j] + 1) << " "; //face element
        //index starts at 1
      data << "\n";
    }}

  for (int i = 0; i < UV.rows(); i++){
      data << "vt " << UV.row(i)[0] << " " << UV.row(i)[1] << "\n"; //texture coordinates
    }
  
  for (int i = 0; i < NV.rows(); i++){
      data << "vn " << NV.row(i)[0] << " " << NV.row(i)[1] << " " << NV.row(i)[2]<< "\n"; //vertex normals
    }
  return true;


  ////////////////////////////////////////////////////////////////////////////
  return false;
}
