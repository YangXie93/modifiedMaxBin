
#include </home/yang/.local/include/python2.7/pybind11/embed.h>
#include <string>
#include <iostream>

namespace py = pybind11;

long double get_prob_dist(char* seq1,char* seq2)
{
    long double cRes = 0.0;
    py::scoped_interpreter guard{};
    
    py::module mod = py::module::import("randomProb");
    py::object res = mod.attr("randomProb")(seq1,seq2);
 
    return res.cast<double>();
    
}
