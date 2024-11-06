// #include <iostream>
// #include "core/session/onnxruntime_cxx_api.h"
#include "test.h"
int main(int argc, char **argv)
{
    /*
    Ort::Env env;
    Ort::Session session_{
        env, "./model/mnist.onnx", Ort::SessionOptions{nullptr}};
    std::cout << session_.GetInputCount() << std::endl;
    */
    Test test = Test();
    test.bark();
}