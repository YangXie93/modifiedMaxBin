
#include <pybind11/embed.h>
#include <string>
#include <iostream>

namespace py = pybind11;

long double newProbDistt(const char* seq1,const char* seq2)
{
    py::scoped_interpreter guard{};
    
    py::module mod = py::module::import("randomProb");
    py::object res = mod.attr("randomProb")(seq1,seq2);
 
    return res.cast<double>();
    
}

int main(){
    const char* x = "aaaa";
    const char* y = "bbbbb";
    std::cout << newProbDistt(x,y) << std::endl;
    return 1;
}